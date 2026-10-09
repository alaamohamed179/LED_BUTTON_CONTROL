# LED_BUTTON_CONTROL

## Project Description

This project controls five LEDs using a push button and an Arduino Uno.

Each button press moves to the next step in the sequence.

Components

- Arduino Uno
- 5 LEDs
- 5 current-limiting resistors
- 1 push button

How It Works

- The first five button presses turn the LEDs ON one by one.
- The next five presses turn the LEDs OFF one by one.
- The sequence then restarts.

Tools Used

- Arduino IDE
- SimulIDE

How to Run

1. Open the ".ino" file in Arduino IDE.
2. Compile the code and export the compiled binary if needed.
3. Load the HEX file into SimulIDE.
4. Run the simulation and press the button to test the sequence.
