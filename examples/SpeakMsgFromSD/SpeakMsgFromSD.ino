// This example exposes the use of an SD card with the EMIC2_UART library
// Text files will be fetched from the SD card, read and sent to the Emic 2 module
// Steps:
// * Format an SD card to a FAT file system on your computer
// * Create a folder with name "EMIC2_UART"
// * Create two text files with contents: (1) Hello Stranger, I'm the emic 2 text to speech module.
//                                            How can I be of service to you?
//                                        (2) Right away!
// The final arrangement will be /EMIC2_UART/
//                                  |----> text001.txt
//                                  |----> text002.txt
// Notes:
// * The files can have at most 1023 characters per line
// * The filename of the files can be at most 8 characters (8.3 format)

#include <SD.h>  // Needed by the EMIC2_UART library
#include "EMIC2_UART.h"

// Chip Select pin for the SD card
// For more info http://arduino.cc/en/Reference/SD/
#define CS_PIN 4

EMIC2_UART emic;  // Creates an instance of the EMIC2_UART library

void setup()
{
    // Initializes the EMIC2_UART instance
    // The library sets up a SoftwareSerial port
    // for the communication with the Emic 2 module
    emic.begin(CS_PIN);
    emic += 10;
}

void loop()
{
    // The speak method fetches a file from the SD card
    // and creates one message per line of the file that gets sent to the Emic 2 module
    // Only the filename needs to be provided (file is inside the EMIC2_UART folder)
    emic.speak("text001.txt", SD_C);
    emic.ready();  // Waits until playback finishes
    delay(2000);
    emic.speak("text002.txt", SD_C);

    emic.setDefaultSettings();  // Restores all settings to their default values

    while (true) ;
}
