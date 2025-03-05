#include "Particle.h"

// Save and temporarily undefine conflicting macros:
#pragma push_macro("D16")
#undef D16
#pragma push_macro("S1")
#undef S1
#pragma push_macro("MISO")
#undef MISO

#include "Adafruit_GFX.h"
#include "Adafruit_EPD.h"
#include "Adafruit_IL0373.h"

#pragma pop_macro("MISO")
#pragma pop_macro("S1")
#pragma pop_macro("D16")

// Wiring definitions per your setup:
// SPI (Photon 2 uses fixed SPI pins: D15, D16, D17)
#define SPI_MOSI  D15
#define SPI_MISO  D16
#define SPI_SCK   D17

// Control Pins (from your wiring guide)
#define EPD_CS    D18   // Chip Select (S3)
#define EPD_DC    D19   // Data/Command (S4)
#define EPD_RST   D10   // Reset
#define EPD_BUSY  D2    // Busy

// Additional control pins:
#define EPD_ENA   D3    // Enable – drive HIGH (3.3V)
#define EPD_SRC   D4    // Source – typically tied LOW (GND)

// Not used in this wiring (no off-chip SRAM):
#define SRAM_CS   -1

// Create display object using the IL0373 driver at 152x152 resolution.
Adafruit_IL0373 display(152, 152, EPD_DC, EPD_RST, EPD_CS, SRAM_CS, EPD_BUSY);

void setup() {
    // Configure additional control pins:
    pinMode(EPD_ENA, OUTPUT);
    pinMode(EPD_SRC, OUTPUT);
    digitalWrite(EPD_ENA, HIGH);  // Enable the display circuitry
    digitalWrite(EPD_SRC, LOW);   // Tie SRC low (or to GND as required by your board)

    // Initialize hardware SPI (Photon 2 uses fixed SPI pins)
    SPI.begin();
    
    // Initialize the EPD display:
    display.begin();
    display.clearBuffer();
    
    // Set up text properties:
    display.setTextSize(1);           // Adjust text size if desired
    display.setTextColor(EPD_BLACK);  // Use black text
    display.setCursor(0, 0);
    
    // Print "Hello World" into the internal buffer:
    display.println("Hello World");
    
    // Update the display:
    display.display();
}

void loop() {
    // Nothing needed in loop for a static display.
}
