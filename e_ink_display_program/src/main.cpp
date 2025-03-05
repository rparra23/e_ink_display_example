#include "Particle.h"
#include "Adafruit_GFX.h"      // Graphics library for drawing shapes/text
#include "Adafruit_EPD.h"      // Library for your E‑ink display (choose the right subclass for your display controller)

#define EINK_CLK   D7   // SPI Clock (SCK)
#define EINK_MOSI  D6   // SPI Data (MOSI)
#define EINK_CS    D5   // Chip Select
#define EINK_DC    D4   // Data/Command control
#define EINK_RST   D3   // Reset pin
#define EINK_BUSY  D2   // Busy status pin

// If your board also needs to control additional signals like EINK_SRC and EINK_ENA,
// and if they are not hardwired, define them here with their assigned pins.
// For example:
// #define EINK_SRC   <your_pin_here>
// #define EINK_ENA   <your_pin_here>
// Then set them HIGH in setup() if required by your display’s datasheet.


// Create an instance of the EPD display.
// NOTE: Replace "Adafruit_IL0373" with the appropriate class for your display controller.
// For example, if your display uses the IL0373 controller, then:
Adafruit_IL0373 display(EINK_CLK, EINK_MOSI, EINK_CS, EINK_DC, EINK_RST, EINK_BUSY);

void setup() {
    Serial.begin(9600);
    waitFor(Serial.isConnected, 10000);
    Serial.println("Initializing E‑ink display...");

    // (Optional) If your EINK_SRC and EINK_ENA need to be manually controlled:
    // pinMode(EINK_SRC, OUTPUT);
    // digitalWrite(EINK_SRC, HIGH);
    // pinMode(EINK_ENA, OUTPUT);
    // digitalWrite(EINK_ENA, HIGH);

    // Initialize the display
    if (!display.begin()) {
        Serial.println("Display initialization failed!");
        while (1) {
            delay(100);
        }
    }
    
    // Clear the internal display buffer
    display.clearBuffer();
    
    // Draw "Hello World" on the buffer.
    // Adjust the cursor position as needed (here, starting at x=0, y=10).
    display.setCursor(0, 10);
    display.setTextColor(EPD_BLACK);  // Use black text (EPD_BLACK is defined in the library)
    display.setTextSize(2);           // Choose an appropriate text size
    display.println("Hello World");
    
    // Send the buffer to the display – this refreshes the screen.
    display.display();
    
    Serial.println("Display updated with 'Hello World'.");
}

void loop() {
    // Nothing to do in loop for this static display example.
}
