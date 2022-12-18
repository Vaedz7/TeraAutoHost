// [BETA] Tera Raid AutoHost

#include "Common/PokemonSwSh/PokemonProgramIDs.h"
#include "NativePrograms/DeviceFramework/DeviceSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/FrameworkSettings.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_Device.h"
#include "NativePrograms/NintendoSwitch/Libraries/NintendoSwitch_PushButtons.h"
#include "NativePrograms/NintendoSwitch/Programs/CustomProgram.h"
#include "NativePrograms/PokemonSwSh/Libraries/PokemonSwSh_Settings.h"

int main(void){
// START PROGRAM ON MICROCONTROLLER
start_program_callback();
initialize_framework(0);
runs=0

// START PROGRAM ON SWITCH
start_program_flash(CONNECT_CONTROLLER_DELAY);
grip_menu_connect_go_home();

// START GAME (BE SURE TO HAVE INSTRUCTIONS SET UP)
pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_HOME_TO_GAME_DELAY);

while (true){
    // DELAY START
    pbf_wait(50);
    
    // CONNECT TO INTERNET AND SAVE
    pbf_press_button(BUTTON_X, 5, 105);
    pbf_press_button(BUTTON_R, 5, 250);
    pbf_press_button(BUTTON_A, 5, 750);
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_press_button(BUTTON_L, 5, 1250);
    pbf_press_button(BUTTON_A, 5, 105);
    
    // FAILSAFE
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_B, 5, 105);
    pbf_press_button(BUTTON_PLUS, 5, 250);
    pbf_press_button(BUTTON_A, 5, 105);
    
    // START RAID
    pbf_press_button(BUTTON_A, 5, 250);
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_press_button(BUTTON_A, 5, 750);
    
    // WAIT FOR PARTICIPANTS
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_wait(37500);
    
    // ATTACK ONCE AND WAIT FOR RAID TO END
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_wait(22500);
    pbf_press_dpad(DPAD_DOWN, 5, 105);
    pbf_press_button(BUTTON_A, 5, 625);
    pbf_press_button(BUTTON_A, 5, 105);
    pbf_wait(3750);
    
    // RESET GAME
    pbf_press_button(BUTTON_HOME, 5, 250);
    pbf_press_button(BUTTON_X, 5, 105);
    pbf_press_button(BUTTON_A, 5, 625);
    runs++;
    
    // EDIT DATE
    if (runs = 6) {
        // NAVIGATE TO SETTINGS
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_button(BUTTON_A, 5, 250);
        pbf_press_dpad(DPAD_DOWN, 625, 105);
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_button(BUTTON_A, 5, 250);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_button(BUTTON_A, 5, 105);
        
        // SKIP DATE (1 HR BACK)
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_RIGHT, 5, 105);
        pbf_press_dpad(DPAD_DOWN, 5, 105);
        pbf_press_dpad(DPAD_RIGHT, 375, 105);
        pbf_press_button(BUTTON_A, 5, 105);
        
        // RETURN TO GAME
        pbf_press_button(BUTTON_HOME, 10, 375);
    };
    
    // RESTART GAME
    pbf_press_button(BUTTON_A, 5, 125);
    pbf_press_button(BUTTON_A, 5, 3750);
    pbf_press_button(BUTTON_A, 5, 3750);
    
    
}
    // EXIT TO IDLE MODE (NEVER USED)
    pbf_press_button(BUTTON_HOME, 10, PokemonSwSh_GAME_TO_HOME_DELAY_SAFE);
    end_program_callback();
    end_program_loop();
};

