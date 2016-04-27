/******************************************************************************
* Zowi LED Matrix Library
* 
* @version 20150710
* @author Raul de Pablos Martin
*		  José Alberca Pita-Romero (Mouth's definitions)
*
* @version 20160410
* @adaptec to work with i2c Matrix  (Adafruit Mini 8x8 LED Matrix w/I2C Backpack - Ultra Bright White) PRODUCT ID: 1080 
* https://www.adafruit.com/product/1080
* based on the // Trinket/Gemma + LED matrix backpack jewelry by Phillip Burgess 
*
******************************************************************************/
#ifndef __LEDMATRIX_H__
#define __LEDMATRIX_H__

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
#endif

////////////////////////////
// Definitions            //
////////////////////////////
#define ROWS 5
#define COLUMNS 6
#define MATRIX_LENGTH ROWS*COLUMNS
#define BRIGHTNESS   6 // 0=min, 15=max
#define I2C_ADDR   0x70 // Edit if backpack A0/A1 jumpers set

   static const uint8_t PROGMEM reorder[] = { // Column-reordering table
        0x00,0x40,0x20,0x60,0x10,0x50,0x30,0x70,0x08,0x48,0x28,0x68,0x18,0x58,0x38,0x78,
        0x04,0x44,0x24,0x64,0x14,0x54,0x34,0x74,0x0c,0x4c,0x2c,0x6c,0x1c,0x5c,0x3c,0x7c,
        0x02,0x42,0x22,0x62,0x12,0x52,0x32,0x72,0x0a,0x4a,0x2a,0x6a,0x1a,0x5a,0x3a,0x7a,
        0x06,0x46,0x26,0x66,0x16,0x56,0x36,0x76,0x0e,0x4e,0x2e,0x6e,0x1e,0x5e,0x3e,0x7e,
        0x01,0x41,0x21,0x61,0x11,0x51,0x31,0x71,0x09,0x49,0x29,0x69,0x19,0x59,0x39,0x79,
        0x05,0x45,0x25,0x65,0x15,0x55,0x35,0x75,0x0d,0x4d,0x2d,0x6d,0x1d,0x5d,0x3d,0x7d,
        0x03,0x43,0x23,0x63,0x13,0x53,0x33,0x73,0x0b,0x4b,0x2b,0x6b,0x1b,0x5b,0x3b,0x7b,
        0x07,0x47,0x27,0x67,0x17,0x57,0x37,0x77,0x0f,0x4f,0x2f,0x6f,0x1f,0x5f,0x3f,0x7f,
        0x80,0xc0,0xa0,0xe0,0x90,0xd0,0xb0,0xf0,0x88,0xc8,0xa8,0xe8,0x98,0xd8,0xb8,0xf8,
        0x84,0xc4,0xa4,0xe4,0x94,0xd4,0xb4,0xf4,0x8c,0xcc,0xac,0xec,0x9c,0xdc,0xbc,0xfc,
        0x82,0xc2,0xa2,0xe2,0x92,0xd2,0xb2,0xf2,0x8a,0xca,0xaa,0xea,0x9a,0xda,0xba,0xfa,
        0x86,0xc6,0xa6,0xe6,0x96,0xd6,0xb6,0xf6,0x8e,0xce,0xae,0xee,0x9e,0xde,0xbe,0xfe,
        0x81,0xc1,0xa1,0xe1,0x91,0xd1,0xb1,0xf1,0x89,0xc9,0xa9,0xe9,0x99,0xd9,0xb9,0xf9,
        0x85,0xc5,0xa5,0xe5,0x95,0xd5,0xb5,0xf5,0x8d,0xcd,0xad,0xed,0x9d,0xdd,0xbd,0xfd,
        0x83,0xc3,0xa3,0xe3,0x93,0xd3,0xb3,0xf3,0x8b,0xcb,0xab,0xeb,0x9b,0xdb,0xbb,0xfb,
        0x87,0xc7,0xa7,0xe7,0x97,0xd7,0xb7,0xf7,0x8f,0xcf,0xaf,0xef,0x9f,0xdf,0xbf,0xff };


class LedMatrix
{
public:
	////////////////////////////
	// Enumerations           //
	////////////////////////////

	////////////////////////////
	// Variables              //
	////////////////////////////

	////////////////////////////
	// Functions              //
	////////////////////////////
	// LedMatrix -- LedMatrix class constructor
	LedMatrix(void);
		
	// writeFull
	void writeFull(unsigned long value);
	
	// readFull
	unsigned long readFull(void);
	
	// setLed
	void setLed(char row, char column);
	
	// unsetLed
	void unsetLed(char row, char column);
	
	// readLed
	bool readLed(char row, char column);
	
	// clearMatrix
	void clearMatrix(void);
	
	// clearMatrix
	void initMatrix(void);
	void ledCmd(uint8_t x);
	//void cclear(void);

	// setEntireMatrix
	void setEntireMatrix(void);



private:	
	////////////////////////////
	// Enumerations           //
	////////////////////////////
	
	
	////////////////////////////
	// Variables              //
	////////////////////////////
        unsigned long memory;

	
	
	////////////////////////////
	// Functions              //
	////////////////////////////
	void sendMemory(void);
	
};

#endif // LEDMATRIX_H //