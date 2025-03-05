/***************************************************
  Example “Hello World” for Adafruit E-Ink Friend
  using Adafruit_EPD_RK on a Photon 2
****************************************************/

#include "Particle.h"

// Include Particle-ported Adafruit GFX & EPD libraries
#include "Adafruit_GFX_RK.h"
#include "Adafruit_EPD_RK.h"

// --------------------------------------------------
// Pin definitions (change if needed for your wiring)
// --------------------------------------------------
#define EPD_CS       D5    // E-Ink display chip select
#define SRAM_CS      D6    // SRAM chip select
#define EPD_BUSY     D7    // Busy pin from the E-Ink display

// If your E-Ink breakout exposes these, uncomment and assign pins:
// #define EPD_DC    D4    // Data/Command
// #define EPD_RST   D3    // Reset

// --------------------------------------------------
// Create display object (driver & resolution must match your panel)
// Example: IL0373 driver at 152x152 resolution, no DC/RST pins used
// --------------------------------------------------
Adafruit_IL0373 display(
  152,        // width
  152,        // height
  /* DC  */ -1,
  /* RST */ -1,
  EPD_CS,
  SRAM_CS,
  EPD_BUSY
);

void setup() {
  // Start Particle
  //Particle.begin();

  // Initialize the EPD display
  display.begin();

  // Clear the internal buffer
  display.clearBuffer();

  // Set up text
  display.setTextSize(1);           // Increase for bigger text
  display.setTextColor(EPD_BLACK);  // Black text
  display.setCursor(0, 0);

  // Print "Hello World"
  display.println("Hello World");

  // Send the buffer to the E-Ink display
  display.display();
}

void loop() {
  // E-Ink remains static until you update again
}
