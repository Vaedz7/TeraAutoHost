# **Tera Raid AutoHost in Pokemon Scarlet and Violet**
**DISCLAIMER: This is a BETA RELEASE, this means that there WILL BE ERRORS**
## Credits
- [Vaedz7](https://github.com/Vaedz7 "Vaedz7") for TeraAutoHost Program and Detection App
- [Pokemon Automation Team](https://github.com/PokemonAutomation "Pokemon Automation Team") for Program Base

## Setup
### Board Setup
1. Follow Microcontroller guide by Pokemon Automation [here](https://github.com/PokemonAutomation/Microcontroller "here")
2. Download the latest release from this repository
3. Copy and Paste ``TeraAutoHost_Core.c`` to ``CustomProgram_Core.c``
4. Compile CustomProgram.hex file for your board
5. Flash HEX file to your board

### In Game Setup
1. Stand in front of the Den you wish to host (Be sure to be facing **SOUTH**)
2. Turn Auto Save **OFF**
3. Save incase of error
4. Have your first party Pokemon have an attacking move (Ideally something with at least 100 Damage) in the **FIRST MOVE SLOT**
5. Set Text Speed to **FAST**

### Application Setup
1. Have your Discord WebHook URL ready and make sure the folder is located in ``Downloads`` and named ``TeraAutoHost``
2. Install Python from [here](https://www.python.org/downloads/ "here")
3. Open Terminal/Command Prompt and run the following commands ``pip install pytesseract``, ``pip install opencv-python``, ``pip install discord-webhook``, and ``pip install rich``
4. Now run ``cd Downloads/TeraAutoHost``
5. Then run ``python3 autohost.py``
6. Enter in WebHook URL
7. Select Video Capture Device
8. Add a description for users to see

### Starting the Program
1. Go to Change Grip/Order Menu on the Switch
2. Plug in your Board with the HEX file flashed
3. Press ``Start Program`` in the application

## Settings
None

## About Program
This program Automatically hosts Tera Raids in Pokemon Scarlet and Violet. It requires a capture card to detect the raid code but no serial connection is required. The program auto adjusts the date in order to preserve the raid den. It will automatcally post the raid code to Discord using a WebHook for users to join


## Issues
Contact Vaedz#1011 on Discord to resolve issues
