# Flashing instructions

## Step 1: Setting up Arduino IDE

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software)

2. Go to **File > Preferences** (or press ctrl+,) and paste "https://dl.espressif.com/dl/package_esp32_index.json" into the "Additional Board Manager URLs" field, then click "OK"

3. Go to **Tools > Board > Boards Manager**, use the search bar on the top to find "esp32" and install **"esp32 by Espressif Systems"**

4. Go to **Tools > Manage Libraries...** and search "Dabble", then install "**DabbleESP32**"
    - The plain "Dabble" library will not work in this case, you must use "DabbleESP32"

5. Download [this](https://github.com/ERROPiX/ESP32_AnalogWrite/archive/refs/heads/master.zip) library, then go to **Sketch > Include Library > Add .ZIP Library...** and navigate to and select the the .zip archive that just downloaded


## Step 2: Flashing the board

1. Download and open (**File > Open**) ["BB8_dabble.ino"](https://github.com/Team3309/Summer-Camp-BB8/blob/main/Code/BB8_dabble.ino)
    - Optionally, find `Dabble.begin("BB8_xx");` and change the contents of the `""` to be whatever you want the robot to appear as on the pairing screen

2. Make sure that noting is powering the robot by removing one of the batteries

3. Go to **Tools > Board** and select **DOIT ESP32 DEVKIT V1**

4. Plug the ESP32 board into your computer with a micro-USB cable

5. Go to **Tools > Port** and select "COMx"
    - If there are multiple COM ports, you may need to use trial and error to find the right one (i.e continue with the next steps and if you get errors like "board not found", then switch ports and try again)

6. If you did everything correctly, then when you press the checkmark in the top left corner, the code should compile with no errors.

7. If it compiled with no problems, then flash the code onto the ESP32 by clicking the "upload" (arrow) button directly next to the checkmark


## Step 3: It's alive!

1. Unplug the USB cable, then power on the robot by replacing the batteries and putting the head in place on the neck

2. Download the Dabble app on your phone if you haven't done so already ([iOS](https://apps.apple.com/us/app/dabble-bluetooth-controller/id1472734455), [Android](https://play.google.com/store/apps/details?id=io.dabbleapp))

3. Launch the app and press the pair button (a plug and socket) in the top right corner

4. Find "BB8_xx" and pair to that, then open the "Controller" screen

5. Press the up button on the controller
    - The reed switch is in the front of the robot
    - If the left wheel spins backward, then change `#define LEFT_MOTOR_INVERTED false` to `#define LEFT_MOTOR_INVERTED true` and flash the updated code onto the ESP32 board again
    - If the right wheel spins backward, then change `#define RIGHT_MOTOR_INVERTED false` to `#define RIGHT_MOTOR_INVERTED true` and flash the updated code onto the ESP32 board again
    - Alternatively, switch the polarity of the inverted motor(s)

6. Press the right button on the controller
    - If the left wheel spins backward and the right wheel spins forward (i.e. robot spins counterclockwise), then move the wires from the left and right motors to the opposite set of terminals on the motor controller and repeat the last step

7. Finally, put the robot chassis inside the shells and tape them closed. Then attach the head to the top of the robot to power it on
    - Chances are that the reed switch will not stay reliably closed and the robot will loose connection as soon as it moves at all. In that case, tape/glue annother magnet on top of the reed switch so that it is always triggered