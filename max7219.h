#ifndef __MAX7219_LIBRARY__
#define __MAX7219_LIBRARY__
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
//
// Power on or off the LED controllers
//
void maxPowerUp(uint8_t bPowerUp);
//
// Set the intensity (duty cycle of PWM signal) for the LED segments
// valid values are 0 (dimmest) to 15 (brightest)
//
void maxSetIntensity(uint8_t bIntensity);
//
// Set the segment decode mode (BCD or none)
//
void maxSetSegmentMode(uint8_t bMode);
//
// Send image data to the array of controllers
// The image data is transmitted as N by 8 lines tall (N is the number of MAX7219 controllers)
// The pitch (uint8_ts per line) can be any value
//
void maxSendImage(uint8_t *pImage, int iPitch);
//
// Enable (1) or disable (0) test mode
// This mode lights up every LED at max brightness
// It can sometimes power up in test mode
//
void maxSetTestMode(uint8_t bOn);
//
// Number of "digits/rows" to control
// valid values are 1-8 active digits/rows
//
void maxSetLimit(uint8_t bLimit);
//
// Send an ASCII string of digits to a 7-segment display
//
void maxSegmentString(char *pString);
//
// Draw a string of characters into the image buffer
// Normal characters are 8x8 and drawn on uint8_t boundaries
// Small characters are 6x8 and drawn on bit boundaries
//
void maxDrawString(char *pString, uint8_t *pImage, uint8_t iPitch, uint8_t bSmall);
//
// Scroll a bitmap N bits left (positive) or right (negative)
// Valid scroll values are +1 to +7 and -1 to -7
// A bitmap is assumed to be iPitch uint8_ts wide by 8 rows tall
// Bits which scroll off one end are added back to the other end
//
void maxScrollBitmap(uint8_t *pBitmap, int iPitch, int iScroll);
//
// Initialize the controllers
// returns 0 for success, -1 for failure
//
int maxInit(uint8_t iNum, uint8_t bDecodeMode, uint8_t iChannel, uint8_t iSelect);
//
// Turn off the LED controllers and free resources
//
void maxShutdown(void);
#endif // __MAX7219_LIBRARY__
