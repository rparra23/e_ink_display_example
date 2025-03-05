#include "epd.h"
#include <stdio.h>

int main(void) {
    // Initialize the e-ink display
    if (epd_init() != 0) {
        printf("Failed to initialize e-ink display\n");
        return -1;
    }
    
    // Clear the display
    epd_clear();
    
    // Display an image (this is a placeholder)
    epd_display();
    
    // Put the display to sleep
    epd_sleep();
    
    return 0;
}

