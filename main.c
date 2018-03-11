//
// MAX7219 demo program
//
// Copyright (c) 2018 BitBank Software, Inc.
// Written by Larry Bank
// email: bitbank@pobox.com
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
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <max7219.h>

int main(int argc, char* argv[])
{
int rc, i, j, iPitch;
char cTemp[64];
uint8_t bImg[40*8];

	iPitch = 40; // bytes per line of image
	memset(bImg, 0, iPitch*8);

	// Initialize the library
	// num controllers, BCD mode, SPI channel, GPIO pin number for CS
	rc = maxInit(4, 0, 0, 22);
	if (rc != 0)
	{
		printf("Problem initializing max7219\n");
		return 0;
	}

// Display a message and scroll it to the left (2 iterations)
	for (i=0; i<2; i++)
	{
		sprintf(cTemp,"BitBank MAX7219 library scroll test #%02d 10:05 ", i);
		maxDrawString(cTemp, bImg, iPitch, 1); // draw narrow digits
		for (j=0; j<iPitch*8; j++)
		{
			maxSendImage(bImg, iPitch);
			maxScrollBitmap(bImg, iPitch, 1);
			usleep(40000);
		} // for each pixel to scroll
	} // for each iteration
	// Quit library and free resources
	maxShutdown();

   return 0;
} /* main() */
