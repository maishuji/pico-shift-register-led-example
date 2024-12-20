# LED Control Using SN74HC595 Shift Register with Raspberry Pi Pico

## Project Overview
This project demonstrates how to control multiple LEDs using an SN74HC595 shift register and a Raspberry Pi Pico. The shift register allows controlling up to 8 LEDs with just three GPIO pins from the Pico, making it an efficient way to expand output capabilities.

---

## Features
- Alternate lighting patterns for LEDs.
- Efficient GPIO usage via serial data transfer to the shift register.
- Modular setup for easy expansion using daisy-chaining.

---

## Components Required
1. Raspberry Pi Pico
2. SN74HC595 Shift Register
3. 8 LEDs
4. 8 Resistors (220 Ω)
5. Breadboard and jumper wires

---

## Circuit Diagram

### SN74HC595 Shift register mapping 

|Left|-|\_\_\_o\_\_\_|- |Right||
|----|-|-------------|- |-----|-|
|Q_b |1|             |16|Vcc  ||
|Q_c |2|             |15|Q_a  ||
|Q_d |3|             |14|DS/SER  |*Data Serial* / *Serial Data* : Responsible for receiving the serial input data that gets shifted into the register|
|Q_e |4|             |13|OE   | *Output Enable* : Active-low, connect to GND to enable outputs|
|Q_f |5|             |12|SHCP (RCLK) | *Shift Register Clock* : Advances the shift register on the rising edgoe of the clock |
|Q_g |6|             |11|STCP (SRCLK)| *Register Clock* : Latches the shifted data into the storage register, transferring it to the outputs|
|Q_h |7|             |10|MR(SRCLR)| *Master Reset* /*Shift Register Clear* : Clear or reset the contents of the shift register|
|GND |8|             | 9|Q_h' |*Q_h'* /*Q7'* : Serial data output pin. Allow cascading of multiple shift registers|



### Pin Connections
| **SN74HC595 Pin** | **Connection**                     |
|-------------------|-------------------------------------|
| Pin 8 (GND)       | Raspberry Pi Pico GND              |
| Pin 16 (VCC)      | Raspberry Pi Pico 3.3V or 5V       |
| Pin 14 (DS)       | Raspberry Pi Pico GPIO (e.g., GP2) |
| Pin 11 (SHCP)     | Raspberry Pi Pico GPIO (e.g., GP3) |
| Pin 12 (STCP)     | Raspberry Pi Pico GPIO (e.g., GP4) |
| Pin 13 (OE)       | GND                                |
| Pin 10 (MR)       | VCC                                |
| Pins 1-7, 15 (Q0-Q7) | To LEDs via 220 Ω resistors       |

---

## Software Setup
### Code Overview
The C++ program utilizes the Raspberry Pi Pico SDK to send serial data to the SN74HC595. It alternates between two LED patterns, creating a blinking effect.

### Installation Instructions
1. Install the Raspberry Pi Pico SDK on your development machine.
    *PICO_SDK_PATH* should be set as environment variable.
    ```bash
    echo ${PICO_SDK_PATH}
    ```
2. Clone or create the C++ project.
3. Save the example code below as `main.cpp`.
4. Build and flash the program to your Pico.
    ```bash
    cd <project-name>
    mkdir build && cd build
    cmake .. && make all
    ```


---

## How It Works
1. **Shift Register Basics:**
   - The SN74HC595 receives serial data via the `DS` pin.
   - The `SHCP` pin clocks the data into the shift register.
   - The `STCP` pin latches the data to the outputs (Q0-Q7).
2. **LED Control:**
   - Patterns (`0b10101010` and `0b01010101`) determine which LEDs are ON or OFF.
   - Alternate patterns are shifted into the register to create a blinking effect.

---

## Expanding the Project
- **More LEDs:**
   - Daisy-chain multiple SN74HC595 shift registers by connecting `Q7’` to the next register’s `DS` pin.
   - Adjust the software to handle more bits.
- **Advanced Patterns:**
   - Create custom lighting patterns for animations or displays.

---

## Troubleshooting
1. **No LEDs Lighting Up:**
   - Check connections and ensure the circuit is powered.
   - Verify GPIO pins match the code.
2. **Flickering LEDs:**
   - Ensure proper timing in the software.
   - Check connections for loose wires.

---

## License
This project is open-source and available for personal and educational use. Feel free to modify and share.

---

## Acknowledgments
- Raspberry Pi Pico Documentation
- Texas Instruments SN74HC595 Datasheet
