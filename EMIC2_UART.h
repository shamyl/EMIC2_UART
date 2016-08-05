/**
 * Name: EMIC2_UART
 * Author: Shamyl Bin Mansoor (shamylmansoor@gmail.com)
 * Version: 1.0
 * Desctiption: A clone of the original library modified to work with harware
 * Serial Port 1 of Atmega2560
 * License: Copyright (c) 2013 Nick Lamprianidis
 *          This library is licensed under the MIT license
 *          http://www.opensource.org/licenses/mit-license.php
 * Source: https://github.com/shamyl/EMIC2_UART
 * Original Author and contributor ******************************
 * Author: Nick Lamprianidis (lampnick67@yahoo.com)
 * Version: 1.0 / Version: 1.0
 * Description: A library for interfacing the EMIC2 Text-to-Speech module
 * License: Copyright (c) 2013 Nick Lamprianidis
 *          This library is licensed under the MIT license
 *          http://www.opensource.org/licenses/mit-license.php
 * Source: https://github.com/pAIgn10/EMIC2
 *
 * Filename: EMIC2_UART.h
 * File description: Definitions and methods for the EMIC2 library
 */

#ifndef EMIC2_UART_h
#define EMIC2_UART_h

#include <Arduino.h>
//#include <SoftwareSerial.h>
#include <SD.h>
#include <string.h>

// #define VERBOSE true // Use this if you want verbose output of the operations executed

#define SD_C 1

// A class for interfacing the Emic 2 module
class EMIC2_UART
{
public:
	EMIC2_UART();
	~EMIC2_UART();
	void begin();
	void begin( uint8_t cs_pin);
	void speak(char *msg);
	void speak(String msg);
	void speak(char num);
	void speak(unsigned char num);
	void speak(int num);
	void speak(unsigned int num);
	void speak(long num);
	void speak(unsigned long num);
	void speak(double num);
	void speak(char *filename, uint8_t sd);
	void speak(String filename, uint8_t sd);
	void speakDemo(uint8_t num);
	void sendCmd(char *cmd);
	void ready();
	EMIC2_UART& operator~();
	EMIC2_UART& operator!();
	EMIC2_UART& operator++();
	EMIC2_UART& operator--();
	EMIC2_UART& operator+=(uint8_t adjust_volume);
	EMIC2_UART& operator-=(uint8_t adjust_volume);
	EMIC2_UART& operator>>(uint16_t adjust_rate);
	EMIC2_UART& operator<<(uint16_t adjust_rate);
	void setVoice(uint8_t voice);
	uint8_t getVoice();
	void setVolume(int8_t volume);
	void resetVolume();
	int8_t getVolume();
	void setRate(uint16_t rate);
	void resetRate();
	uint16_t getRate();
	void setLanguage(uint8_t language);
	uint8_t getLanguage();
	void setParser(uint8_t parser);
	uint8_t getParser();
	void setDefaultSettings();
	// With only 64Bytes available on the receive buffer of the various Arduino boards
	// UARTs and the SoftwareSerial library, current settings and version information
	// can't be obtainted in their entirety. So the following functions are being
	// implemented only for reference and they are not going to be utilized in any way
	void getCurrentSettings();
	void getVInfo();

private:
	//SoftwareSerial *_emic2_io;
	uint8_t _paused;
	uint8_t _voice;
	int8_t _volume;
	uint16_t _rate;
	uint8_t _language;
	uint8_t _parser;
	uint8_t _sd;
};

#endif  // EMIC2_UART
