/**
 * Name: EMIC2_UART
 * Author: Shamyl Bin Mansoor (shamylmansoor@gmail.com)
 * Version: 1.0, updated Aug 2016
 * Desctiption: A clone of the original library modified to work with harware
 * Serial Port 1 of Atmega2560
 * License: Copyright (c) 2013 Nick Lamprianidis
 *          This library is licensed under the MIT license
 *          http://www.opensource.org/licenses/mit-license.php
 * Source: https://github.com/shamyl/EMIC2_UART
 * Original Author and contributor ******************************
 * Original Author: Nick Lamprianidis (lampnick67@yahoo.com)
 * Version: 1.0
 * Description: A library for interfacing the EMIC2 Text-to-Speech module
 * License: Copyright (c) 2013 Nick Lamprianidis
 *          This library is licensed under the MIT license
 *          http://www.opensource.org/licenses/mit-license.php
 * Source: https://github.com/pAIgn10/EMIC2
 *
 * Filename: EMIC2_UART.cpp
 * File description: Implementation of methods for the EMIC2 library
 */

#include <EMIC2_UART.h>

// Creates an instance of the EMIC2_UART class and initializes variables
EMIC2_UART::EMIC2_UART()
{
    _paused = 0;
    _voice = 0;
    _volume = 0;
    _rate = 200;
    _language = 0;
    _parser = 1;
    _sd = 0;
}

// Upon destruction of an instance,
// it frees dynamically allocated data members
EMIC2_UART::~EMIC2_UART()
{
    //delete _emic2_io;
}

// Initializes serial port and checks for availability of the Emic 2 module
void EMIC2_UART::begin()
{
    //_emic2_io = new SoftwareSerial(rx_pin, tx_pin);
    //_emic2_io->begin(9600);
    Serial1.begin(9600);

    #ifdef VERBOSE
    Serial.println("Serial Port is set");
    #endif

    // When the Emic 2 powers on, it takes about 3 seconds for it to successfully initialize
    // It then sends a ":" character to indicate it's ready to accept commands
    // If the Emic 2 is already initialized, a CR will also causes it to send a ":"
    Serial1.print('\n');  // Sends a CR in case the system is already up
    while ( Serial1.read() != ':' ) ;  // When the Emic 2 has initialized and is ready,
                                          // it will send a single ':' character...
                                          // so it waits here until it receives the ':'
    delay(10);  // Short delay
    Serial1.flush();  // Flushs receive buffer

    #ifdef VERBOSE
    Serial.println("Emic 2 Module is ready");
    #endif

}

// Initializes serial port and SD card, and checks for availability of the Emic 2 module
void EMIC2_UART::begin(uint8_t cs_pin)
{
    begin(); // Initializes serial port

    #if defined(__AVR_ATmega2560__)
    pinMode(53, OUTPUT); // Sets the hardware SS pin on Arduino Mega to output
    #else
    pinMode(10, OUTPUT); // Sets the hardware SS pin on the rest of Arduino boards to output
    #endif

    _sd = 1;  // Indicator of availability of messages to speak, in the SD card
    uint8_t chk = SD.begin(cs_pin);  // Initializes SD card

    #ifdef VERBOSE
    if ( !chk ) Serial.println("SD card failed, or not present");
    else Serial.println("SD card initialized");
    #endif
}

// Waits (Blocking) until Emic 2 is ready to receive a command
void EMIC2_UART::ready()
{
    //_emic2_io->listen();
    Serial1.flush();  // Flushes receive buffer
    Serial1.print('\n');  // Triggers response
    while (Serial1.read() != ':') ;  // Awaits for ':' indicator
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(char *msg)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(msg);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(msg);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(String msg)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(msg);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(msg);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(char num)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(num);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(num);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(unsigned char num)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(num);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(num);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(int num)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(num);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(num);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(unsigned int num)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(num);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(num);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(long num)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(num);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(num);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(unsigned long num)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(num);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(num);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
void EMIC2_UART::speak(double num)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Playing message: ");
    Serial.println(num);
    #endif

    // Sends the desired string to convert to speech
    Serial1.print('S');
    Serial1.print(num);
    Serial1.print('\n');
}

// Sends a message to the Emic 2 module to speak
// The message originates from an SD card
// There can be at most 1023 characters per line in a file
void EMIC2_UART::speak(char *filename, uint8_t sd)
{
    if ( _sd )  // Checks if the SD card has been initiliazed
    {
        // Creates the file path
        char path[20] = "/emic2/";
        strcat(path, filename);

        #ifdef VERBOSE
        Serial.print("Requesting file: ");
        Serial.println(path);
        #endif

        File f = SD.open(path);  // Tries to open the file
        if ( f )
        {
            #ifdef VERBOSE
            Serial.print(path);
            Serial.println(" found\nFile opended");
            #endif

            #ifdef VERBOSE
            Serial.println("Playing message: ");
            #endif

            char c;
            while ( f.available() )  // Sends a message for every line in the file
            {
                ready();
                Serial1.print('S');

                while ( ( ( c = f.read() ) != '\n' ) && ( c != -1 ) )
                {
                    #ifdef VERBOSE
                    Serial.print(c);
                    #endif

                    Serial1.print(c);  // Sends characters one by one
                }

                #ifdef VERBOSE
                Serial.println();
                #endif

                Serial1.print('\n');  // Finishes the message (line)
            }

            f.close();

            #ifdef VERBOSE
            Serial.println("File closed");
            #endif
        }
        #ifdef VERBOSE
        else
        {
            Serial.print("/emic2/");
            Serial.print(filename);
            Serial.println(" not present");
        }
        #endif
    }
    #ifdef VERBOSE
    else
    {
        Serial.println("SD card not initialized");
    }
    #endif
}

// Sends a message to the Emic 2 module to speak
// The message originates from an SD card
// There can be at most 1023 characters per line in a file
void EMIC2_UART::speak(String filename, uint8_t sd)
{
    char buf[13];
    filename.toCharArray(buf, 13);
    speak(buf, SD_C);
}

// Plays demonstration messages
void EMIC2_UART::speakDemo(uint8_t num)
{
    if ( num >= 0 && num < 3 )
    {
        ready();

        // Sends demo command
        Serial1.print('D');
        Serial1.print(num);
        Serial1.print('\n');

        #ifdef VERBOSE
        Serial.print("Plays demo ");
        Serial.println(num);
        #endif
    }
}

// Sends a command specified entirely on the input argument
void EMIC2_UART::sendCmd(char *cmd)
{
    ready();

    #ifdef VERBOSE
    Serial.print("Sending command: ");
    Serial.println(cmd);
    #endif

    Serial1.print(cmd);  // Sends command
}

// Pauses/Unpauses playback
EMIC2_UART& EMIC2_UART::operator~()
{
    //_emic2_io->listen();
    // Sends pause/unpause command
    Serial1.print('Z');
    uint8_t val;
    while ((val = Serial1.read()) != '.' && val != ':') ;

    _paused = !_paused;  // Updates state

    #ifdef VERBOSE
    if ( _paused ) Serial.println("Playback unpaused");
    else Serial.println("Playback paused");
    #endif

    return *this;
}

// Stops playback
EMIC2_UART& EMIC2_UART::operator!()
{
    //_emic2_io->listen();
    // Sends stop command
    Serial1.print('X');
    while (Serial1.read() != ':') ;

    #ifdef VERBOSE
    Serial.println("Playback stopped");
    #endif

    return *this;
}

// Raises volume by 1dB
EMIC2_UART& EMIC2_UART::operator++()
{
    setVolume(_volume + 1);

    #ifdef VERBOSE
    Serial.println("Volume raised");
    #endif

    return *this;
}

// Lowers volume by 1dB
EMIC2_UART& EMIC2_UART::operator--()
{
    setVolume(_volume - 1);

    #ifdef VERBOSE
    Serial.println("Volume lowered");
    #endif

    return *this;
}

// Raises volume by the specified dB
EMIC2_UART& EMIC2_UART::operator+=(uint8_t adjust_volume)
{
    setVolume(_volume + adjust_volume);

    #ifdef VERBOSE
    Serial.println("Volume raised");
    #endif

    return *this;
}

// Lowers volume by the specified dB
EMIC2_UART& EMIC2_UART::operator-=(uint8_t adjust_volume)
{
    setVolume(_volume - adjust_volume);

    #ifdef VERBOSE
    Serial.println("Volume lowered");
    #endif

    return *this;
}

// Increases speaking rate
EMIC2_UART& EMIC2_UART::operator>>(uint16_t adjust_rate)
{
    setRate(_rate + adjust_rate);

    #ifdef VERBOSE
    Serial.println("Rate increased");
    #endif

    return *this;
}

// Decreases speaking rate
EMIC2_UART& EMIC2_UART::operator<<(uint16_t adjust_rate)
{
    // Ensures that the result rate won't be negative...
    // ! Input argument to setRate is unsigned
    int16_t tmp_rate = _rate - adjust_rate;
    if ( tmp_rate < 0 ) tmp_rate = 0;

    setRate((uint16_t)tmp_rate);

    #ifdef VERBOSE
    Serial.println("Rate decreased");
    #endif

    return *this;
}

// Sets voice
void EMIC2_UART::setVoice(uint8_t voice)
{
    if ( voice >= 0 && voice < 9 )
    {
        ready();

        _voice = voice;  // Updates state

        // Sends voice command
        Serial1.print('N');
        Serial1.print(_voice);
        Serial1.print('\n');
        while (Serial1.read() != ':') ;

        #ifdef VERBOSE
        Serial.print("Voice set to ");
        Serial.println(_voice);
        #endif
    }
}

// Returns the current setting of the voice level (in dB)
uint8_t EMIC2_UART::getVoice()
{
    return _voice;
}

// Sets volume level (in dB)
void EMIC2_UART::setVolume(int8_t volume)
{
    ready();

    // Enforces bounds and updates state
    if ( volume < -48 ) _volume = -48;
    else if ( volume > 18 ) _volume = 18;
    else _volume = volume;

    // Sends volume command
    Serial1.print('V');
    Serial1.print(_volume);
    Serial1.print('\n');
    while (Serial1.read() != ':') ;

    #ifdef VERBOSE
    Serial.print("Volume set to ");
    Serial.println(_volume);
    #endif
}

// Resets volume level (0dB)
void EMIC2_UART::resetVolume()
{
    setVolume(0);

    #ifdef VERBOSE
    Serial.println("Volume reset");
    #endif
}

// Returns the current setting of the volume
int8_t EMIC2_UART::getVolume()
{
    return _volume;
}

// Sets speaking rate (in words/minute)
void EMIC2_UART::setRate(uint16_t rate)
{
    ready();

    // Enforces bounds and updates state
    if ( rate < 75 ) _rate = 75;
    else if ( rate > 600 ) _rate = 600;
    else _rate = rate;

    // Sends rate command
    Serial1.print('W');
    Serial1.print(_rate);
    Serial1.print('\n');
    while (Serial1.read() != ':') ;

    #ifdef VERBOSE
    Serial.print("Rate set to ");
    Serial.println(_rate);
    #endif
}

// Resets speaking rate (200words/minute)
void EMIC2_UART::resetRate()
{
    setRate(200);

    #ifdef VERBOSE
    Serial.println("Rate reset");
    #endif
}

// Returns the current setting of the speaking rate (in words/minute)
uint16_t EMIC2_UART::getRate()
{
    return _rate;
}

// Sets speaking language
void EMIC2_UART::setLanguage(uint8_t language)
{
    if ( language == 0 || language == 1 || language == 2 )
    {
        ready();

        _language = language; // Updates state

        // Sends language command
        Serial1.print('L');
        Serial1.print(_language);
        Serial1.print('\n');
        while (Serial1.read() != ':') ;

        #ifdef VERBOSE
        Serial.print("Language set to ");
        Serial.println(_language);
        #endif
    }
}

// Returns the current setting of the language
uint8_t EMIC2_UART::getLanguage()
{
    return _language;
}

// Sets the parser
void EMIC2_UART::setParser(uint8_t parser)
{
    if ( parser == 0 || parser == 1 )
    {
        ready();

        _parser = parser;  // Updates state

        // Sends parser command
        Serial1.print('P');
        Serial1.print(_parser);
        Serial1.print('\n');
        while (Serial1.read() != ':') ;

        #ifdef VERBOSE
        Serial.print("Parser set to ");
        Serial.println(_parser);
        #endif
    }
}

// Returns the current setting of the parser
uint8_t EMIC2_UART::getParser()
{
    return _parser;
}

// Updates an instance to the default settings
void EMIC2_UART::setDefaultSettings()
{
    ready();

    // Sends restore command
    Serial1.print("R\n");
    while (Serial1.read() != ':') ;

    // Restores data members
    _paused = 0;
    _voice = 0;
    _volume = 0;
    _rate = 200;
    _language = 0;
    _parser = 1;

    #ifdef VERBOSE
    Serial.println("Default settings restored");
    #endif
}

// Prints to the serial port the current settings of the Emic 2 Module
// The response is bigger than the size of the receive buffer...
// so it prints the response while it receives the data to make room for them
void EMIC2_UART::getCurrentSettings()
{
    ready();

    // Sends the print settings command
    Serial1.print("C\n");
    delayMicroseconds(200);  // Waits for response. Appropriate for the specific command
    while ( Serial1.available() ) Serial.print((char)Serial1.read());
    Serial.println();
    Serial1.flush();
}

// Prints to the serial port the version information of the Emic 2 Module
// The response is bigger than the size of the receive buffer...
// so it prints the response while it receives the data to make room for them
// The process is not fast enough. The end of the response printed will be gibberish
void EMIC2_UART::getVInfo()
{
    ready();

    // Sends the print version info command
    Serial1.print("I\n");
    delayMicroseconds(3400);  // Waits for response. Appropriate for the specific command
    while ( Serial1.available() ) Serial.print((char)Serial1.read());
    Serial.println();
    Serial1.flush();
}
