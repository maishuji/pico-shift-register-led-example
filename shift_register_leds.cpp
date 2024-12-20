#include "pico/stdlib.h"

// Define GPIO pins for the shift register
#define DATA_PIN 2    // Data pin (DS)
#define CLOCK_PIN 3   // Clock pin (SHCP)
#define LATCH_PIN 4   // Latch pin (STCP)

// Function to pulse the clock pin
void pulseClock() {
    gpio_put(CLOCK_PIN, 1);
    sleep_us(1);
    gpio_put(CLOCK_PIN, 0);
}

// Function to pulse the latch pin
void pulseLatch() {
    gpio_put(LATCH_PIN, 1);
    sleep_us(1);
    gpio_put(LATCH_PIN, 0);
}

// Function to send a byte to the shift register
void shiftOut(uint8_t data) {
    for (int i = 7; i >= 0; --i) {
        gpio_put(DATA_PIN, (data >> i) & 0x01);  // Set the data bit
        pulseClock();                           // Pulse the clock
    }
    pulseLatch();                               // Update the outputs
}

int main() {
    stdio_init_all();

    // Initialize GPIO pins
    gpio_init(DATA_PIN);
    gpio_set_dir(DATA_PIN, GPIO_OUT);
    gpio_init(CLOCK_PIN);
    gpio_set_dir(CLOCK_PIN, GPIO_OUT);
    gpio_init(LATCH_PIN);
    gpio_set_dir(LATCH_PIN, GPIO_OUT);

    uint8_t pattern1 = 0b10101010; // LEDs 1, 3, 5, 7 ON
    uint8_t pattern2 = 0b01010101; // LEDs 2, 4, 6, 8 ON

    while (true) {
        shiftOut(pattern1);  // Light LEDs in pattern1
        sleep_ms(500);       // Wait for 500ms
        shiftOut(pattern2);  // Light LEDs in pattern2
        sleep_ms(500);       // Wait for 500ms
    }

    return 0;
}
