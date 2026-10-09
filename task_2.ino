// for delay functions
#include <util/delay.h>

#define FIRST_LED 1
#define LAST_LED 5
#define TOTAL_LEDS 5

#define LED_PORT PORTD
#define LED_DDR DDRD

#define SWITCH_DDR DDRB
#define SWITCH_PORT PORTB
#define SWITCH_PIN PINB
#define SWITCH_BIT 1

// count of presses
int step_counter = 0;

void setup() {

     // Set LED pins as outputs
     for (int i = FIRST_LED; i <= LAST_LED; i++) {
     LED_DDR |= (1 << i);
    }

    // set button as input with pull-up
    SWITCH_DDR &= ~(1 << SWITCH_BIT);
    SWITCH_PORT |= (1 << SWITCH_BIT);

    // Turn all LEDs off
    for (int i = FIRST_LED; i <= LAST_LED; i++) {
    LED_PORT &= ~(1 << i);
    }
}

void loop() {

    // Read button state
    int current_button_state = (SWITCH_PIN & (1 << SWITCH_BIT)) ? 1 : 0;

    // if button is pressed
    if (current_button_state == 0) {
       // delay to avoid false readings
      _delay_ms(50);

      if (!(SWITCH_PIN & (1 << SWITCH_BIT))) {
      // move to the next sequence
      step_counter++;

      // Turn LEDs on from 1 to 5 one by one
      if (step_counter >= 1 && step_counter <= TOTAL_LEDS) {

      int pin = FIRST_LED + step_counter - 1;
      LED_PORT |= (1 << pin);

      }

      // Turn LEDs off from 5 to 1
      else if (step_counter > TOTAL_LEDS && step_counter <= 2 * TOTAL_LEDS) {

      int pin = FIRST_LED + (2 * TOTAL_LEDS) - step_counter;
      LED_PORT &= ~(1 << pin);

     }

      // Restart sequence
      else {
      step_counter = 0;
      }

     // Wait until button is released
     while (!(SWITCH_PIN & (1 << SWITCH_BIT))) {
      _delay_ms(10);
     }

     _delay_ms(50);
    }

  }
}
