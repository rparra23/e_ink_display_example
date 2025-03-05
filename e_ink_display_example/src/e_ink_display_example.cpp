#include "Particle.h"
#include "Adafruit_GFX_RK.h"
#include "Adafruit_EPD_RK.h"

// Wiring definitions per your guide:
// SPI Communication (fixed on Photon 2)
#define SPI_MOSI  D15
#define SPI_MISO  D16
#define SPI_SCK   D17

// Control Pins (from your wiring guide)
#define EPD_CS    D18   // Chip Select (S3)
#define EPD_DC    D19   // Data/Command (S4)
#define EPD_RST   D10   // Reset
#define EPD_BUSY  D2    // Busy

// Additional pins that need connection:
#define EPD_ENA   D3    // Enable: should be driven HIGH (3.3V)
#define EPD_SRC   D4    // Source: typically set LOW (GND)

// Not used in this wiring
#define SRAM_CS   -1

// Create display object (example uses IL0373 driver with 152x152 resolution)
Adafruit_IL0373 display(152, 152, EPD_DC, EPD_RST, EPD_CS, SRAM_CS, EPD_BUSY);

void setup() {
    // Configure additional control pins:
    pinMode(EPD_ENA, OUTPUT);
    pinMode(EPD_SRC, OUTPUT);
    // Drive ENA high to enable the board, and SRC low (per typical requirements)
    digitalWrite(EPD_ENA, HIGH);
    digitalWrite(EPD_SRC, LOW);
    
    // Initialize hardware SPI (Photon 2's SPI pins are fixed)
    SPI.begin();
    
    // Initialize the EPD display:
    display.begin();
    display.clearBuffer();
    
    // Set up text properties:
    display.setTextSize(1);           // Adjust for larger text if desired
    display.setTextColor(EPD_BLACK);  // Black text color
    display.setCursor(0, 0);
    
    // Print "Hello World":
    display.println("Hello World");
    
    // Update the display:
    display.display();
}

void loop() {
    // E-Ink displays are static until updated, so nothing is needed here.
}
