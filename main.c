/*
 * Test of termcolor library 
 * https://github.com/cyounes/termcolor
 * author: Younes CHEIKH | cyounes@twitter
 * 
 */
#include <stdio.h>
#include "termcolor.h"

int main() {

	printf("Hi, Thanks for trying termcolor library :) \n" );
	printf("Using this library allow the developer to decorate \
the output of its console application.\n\n");
	printf("Some Examples: \n\n");
	
	bgColor(RED); // Background RED and not "RED" !
	printf("text with RED Background\n\n");
	bgColor(DEFAULT); // Default Background Color
	fgColor(RED); // RED Foreground color 
	printf("text with RED Foreground\n\n");
	bgColor(RED);
	fgColor(YELLOW);
	printf("YELLOW text in RED Background\n\n");
	textBold(TRUE); // Bold Text
	printf("YELLOW and BOLD text in RED Background\n\n");
	textUnderline(TRUE); // Underlined text 
	bgColor(DEFAULT);
	printf("YELLOW and BOLD and Underlined text\n\n");
	fgColor(DEFAULT);
	colorReverse(TRUE);
	printf("REVERSED test with default foreground and default background :)\n\n");
	colorReverse(FALSE);
	textBlink(TRUE);
	printf("BLINKING text with default foreground and default background\n\n");
	
	resetStyle(); // Reset all as default 
	printf("Now Examples using High Intensity\n\n");
	highFgIntensity(TRUE);
	highBgIntensity(TRUE);
	bgColor(RED);
	printf("text with RED Background\n\n");
	bgColor(DEFAULT);
	fgColor(RED);
	printf("text with RED Foreground\n\n");
	bgColor(RED);
	fgColor(YELLOW);
	printf("YELLOW text in RED Background\n\n");
	textBold(TRUE);
	printf("YELLOW and BOLD text in RED Background\n\n");
	
	resetStyle();
	printf("Simple Text :D \n\n");
	
    return 0;
}
