#ifndef __MAX7219__
#define __MAX7219__
//
// MAX7219 LED Matrix controller library
// Copyright (c) 2018 BitBank Software, Inc.
// Written by Larry Bank
// bitbank@pobox.com
// Project started 3/10/2018
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Initialize the controllers
//
// iNum - number of cascaded controllers
// bDecodeMode - pixels (0) or 7-segments (1)
// bClk - pin number used for clock (in bit-banged mode)
// bData - pin number used for data (in bit-banged mode)
// bSel - pin number used for select (in both SPI and bit-banged mode)
//
void maxInit(byte iNum, byte bDecodeMode, byte bClk, byte bData, byte bSel);

//
// Scroll a bitmap N bits left (positive) or right (negative)
// Valid scroll values are +1 to +7 and -1 to -7
// A bitmap is assumed to be iPitch bytes wide by 8 rows tall
// Bits which scroll off one end are added back to the other end
//
void maxScrollBitmap(byte *pBitmap, int iPitch, int iScroll);
//
// Draw a string of characters into the image buffer
// Normal characters are 8x8 and drawn on byte boundaries
// Small characters are 6x8 and drawn on bit boundaries
//
void maxDrawString(char *pString, byte *pImage, byte iPitch, byte bSmall);
//
// Number of "digits/rows" to control
// valid values are 0-7 (corresponds to 1-8 active digits/rows)
// Set automatically during maxInit() function
//
void maxSetLimit(byte bLimit);
//
// Enable (1) or disable (0) test mode
// This mode lights up every LED at max brightness
// It can sometimes power up in test mode
//
void maxSetTestMode(byte bOn);
//
// Send image data to the array of controllers
// The image data is transmitted as N by 8 lines tall (N is the number of MAX7219 controllers)
// The pitch (bytes per line) can be any value
//
void maxSendImage(byte *pImage, int iPitch);
//
// Set the segment decode mode
// BCD (1)
// None (0)
//
void maxSetSegmentMode(byte bMode);
//
// Set the LED intensity
// 0 (min) to 15 (max)
//
void maxSetIntensity(byte bIntensity);
//
// Power on or off the LED controllers
//
void maxPowerUp(byte bPowerUp);

#endif // __MAX7219__
