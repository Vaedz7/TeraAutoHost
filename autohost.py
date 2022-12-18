# IMPORTS
from __future__ import print_function
from tkinter import *
from tkinter import ttk
import pytesseract
import time
import threading
import datetime
import imutils
import cv2
import os
from discord_webhook import DiscordWebhook, DiscordEmbed
from rich import print

# SETUP GUI
win = Tk()
win.title("Tera Raid AutoHost v0.0.1")
win.geometry("1000x500")

# FIND CAMERA INPUTS
def list_ports():
    non_working_ports = []
    dev_port = 0
    working_ports = []
    available_ports = []
    while len(non_working_ports) < 6:
        camera = cv2.VideoCapture(dev_port)
        if not camera.isOpened():
            non_working_ports.append(dev_port)
        else:
            is_reading, img = camera.read()
            w = camera.get(3)
            h = camera.get(4)
            if is_reading:
                working_ports.append(str(dev_port))
            else:
                available_ports.append(dev_port)
        dev_port +=1
    return working_ports
    
video_ports = list_ports()
print("[magenta][CONFIGURATION] - All Video Sources Found[/magenta]")
print("[yellow][GUI] - Graphical Interface Successfully Built[/yellow]")

# ADD GUI ELEMENTS
wurl=StringVar()
wdesc=StringVar()

ttk.Label(win, text = "Tera AutoHost v0.0.1",
          font = ("Ariel", 24)).grid(row = 0, column = 2)

ttk.Label(win, text = "Webhook URL: ",
          font = ("Ariel", 15)).grid(row = 5, column = 0)
          
ttk.Label(win, text = "Video Source: ",
          font = ("Ariel", 15)).grid(column = 0,
          row = 10, padx = 10, pady = 25)
          
urlget=ttk.Entry(win, textvariable=wurl).grid(row = 5, column = 1)

ttk.Label(win, text = "Raid Description: ",
          font = ("Ariel", 15)).grid(column = 0,
          row = 15, padx = 10, pady = 25)
          
desget=ttk.Entry(win, textvariable=wdesc).grid(row = 15, column = 1)

src = StringVar()
cvs = ttk.Combobox(win, width = 10, values=video_ports, textvariable = src).grid(column = 1, row = 10)

# ADD OCR MEASUREMENTS
left = 170
top = 95
right = 360
bottom = 135

lleft = 400
ltop = 130
lright = 575
lbottom = 210

run=True
linkcode = "AAAAA"
fails=0

# RUN OCR AND NOTIFY WHEN RAID DETECTED

def stop():
  run=False

def start_program():
  global fails
  fails = 0
  print("[blue][PROGRAM] - Program Started[/blue]")
  global linkcode
  vc=src.get()
  from PIL import Image as imghelp
  from PIL import ImageTk
  vid = cv2.VideoCapture(int(vc))
  while run == True:
    ret, frame = vid.read()
    frame = cv2.resize(frame, (1280, 720))
    cv2.imwrite("frame_captured.png", frame)
    cv2.imwrite("find_code.png", frame)
    cfr=imghelp.open("frame_captured.png")
    cfr = cfr.crop((left, top, right, bottom))
    cfr.save("ocr.png")
    img = cv2.imread("ocr.png")
    if "Rem" and "Time" in pytesseract.image_to_string(img):
        print("[green][DETECTION] - Raid Detected[/green]")
        lcim=imghelp.open("find_code.png")
        lcim = lcim.crop((lleft, ltop, lright, lbottom))
        lcim.save("lc_det.png")
        linkcodeimg = cv2.imread("lc_det.png")
        linkcode=pytesseract.image_to_string(linkcodeimg)
        print("[green][DETECTION] - Link Code Found: "+linkcode+"[/green]")
        webhook = DiscordWebhook(url=wurl.get())
        embed = DiscordEmbed(title='AutoHosting Tera Raid', description=wdesc.get(), color='03b2f8')
        linkcode=str(linkcode)
        embed.set_author(name='Tera Raid AutoHost v0.0.1')
        embed.set_footer(text='Tera Raid AutoHost by Vaedz#1011')
        embed.add_embed_field(name='**Link Code**', value=linkcode)
        with open("frame_captured.png", "rb") as f:
            webhook.add_file(file=f.read(), filename='frame_captured.png')
        embed.set_image(url='attachment://frame_captured.png')
        embed.set_timestamp()
        webhook.add_embed(embed)
        response = webhook.execute()
        time.sleep(300)
        
    else:
        print("[red][DETECTION] - Raid Not Detected... Rescanning[/red]")
        fails = fails+1
        if fails == 1000:
            webhook = DiscordWebhook(url=wurl.get())
            embed = DiscordEmbed(title='Program Failure', description="**Raid Not Detected in: ~1000s**", color='ff0000')
            embed.set_author(name='Tera Raid AutoHost v0.0.1')
            embed.set_footer(text='Tera Raid AutoHost by Vaedz#1011')
            embed.set_timestamp()
            webhook.add_embed(embed)
            response = webhook.execute()
            fails = 0
        
  vid.release()
  cv2.destroyAllWindows()


start_button = ttk.Button(win, text="Start Program", command=start_program).grid(row = 20, column = 1)
stop_button = ttk.Button(win, text="Stop Program", command=stop).grid(row = 25, column = 1)

win.mainloop()
