Termcolor
=========

Is a C library used for ANSII Color formatting for terminal output.

![Termcolor Library](https://raw.github.com/cyounes/termcolor/master/examples/example_termcolor.png) 

## Available Colors:
 `BLACK` `RED` `GREEN` `YELLOW` `BLUE` `MAGENTA` `CYAN` `WHITE`


## BOOLEAN ?
By including **termcolor** library in your code, you don't need to include the ~~**stdbool**~~ library. However you need to write the boolean keywords in uppercase characters:  ***TRUE***  and ***FALSE*** 

## Functions:

#### Colors: 

+ `bgColor(COLOR)` : set the background color using the available colors.

+ `fgColor(COLOR)` : set the foreground color using the available colors.

for `bgColor(COLOR)` and `fgColor(COLOR)` functions use the variable `DEFAULT`as parameter to reset the default color:
```
{
	…
	bgColor(DEFAULT);
	fgColor(DEFAULT);
	…
}
```
#### Text decorations:

+ `textBold(BOOLEAN)` : enable or disable text bolding for the next output:
``` 
	{
		…
		textBold(TRUE); 
		…
		textBold(FALSE);
	} 
```

+ `textBlink(BOOLEAN)` : enable or disable text blinking for the next output:
``` 
	{
		...
		textBlink(TRUE); 
		...
		textBlink(FALSE);
	} 
```

+ `colorReverse(BOOLEAN)`: enable or disable colors reversing for the next output:
``` 
	{
		...
		colorReverse(TRUE); 
		...
		colorReverse(FALSE);
	} 
```

+ `textUnderline(BOOLEAN)`: underline text

+ `highFgIntensity(BOOLEAN)` : Use High Intensity for foreground colors.

+ `highBgIntensity(BOOLEAN)` : Use High Intensity for background colors.

+ `setStyle()` : Usually the programer don't need to invoke this function, it will be invoked automatically by the other functions each time you change the style.

+ `resetStyle()` : Reset all colors and decorations by default!, i segues to invoke this function at the end of your main to restore all as default.

### Examples:
##### Red Background:

```
{
	bgColor(RED);
	printf("text with RED Background");
}
```
######Result:
![termcolor red background](https://raw.github.com/cyounes/termcolor/master/examples/red_background.png) 
-
##### Default background + Red foreground:

```
{
	bgColor(DEFAULT);
	fgColor(RED);
	printf("text with RED Foreground");
}
```
######Result:
![termcolor red foreground](https://raw.github.com/cyounes/termcolor/master/examples/red_foreground.png)
-
##### Yellow text on red background:

```
{
	bgColor(RED);
	fgColor(YELLOW);
	printf("YELLOW text in RED Background");
}
```
######Result:
![Yellow text on red background](https://raw.github.com/cyounes/termcolor/master/examples/yellow_in_red.png)
-
##### Yellow Bold text on red background:

```
{
	bgColor(RED);
	fgColor(YELLOW);
	textBold(TRUE);
	printf("YELLOW and BOLD text in RED Background");
}
```
######Result:
![termcolor Yellow Bold text on red background](https://raw.github.com/cyounes/termcolor/master/examples/bold_yellow_in_red.png)
-
##### Yellow, Bold and underlined text on red background:

```
{
	bgColor(RED);
	fgColor(YELLOW);
	textBold(TRUE);
	textUnderline(TRUE);
	printf("YELLOW and BOLD text in RED Background");
}
```
######Result:
![termcolor Yellow, Bold and underlined text on red background](https://raw.github.com/cyounes/termcolor/master/examples/bold_yellow_underline.png)
-

##### High Intensity: Yellow Bold text on red background:

```
{
	bgColor(RED);
	fgColor(YELLOW);
	textBold(TRUE);
	highFgIntensity(TRUE);
	highBgIntensity(TRUE);
	printf("YELLOW and BOLD text in RED Background");
}
```
######Result:
![termcolor High Intensity: Yellow Bold text on red background](https://raw.github.com/cyounes/termcolor/master/examples/high_intens.png)
-

##### Reversed colors:

```
{
	bgColor(DEFAULT);
	fgColor(DEFAULT);
	textBold(TRUE);
	textUnderline(TRUE);
	printf("REVERSED test with default foreground and default background :)");
}
```
######Result:
![termcolor Reversed colors](https://raw.github.com/cyounes/termcolor/master/examples/reversed_colors.png)
-

##### Main Example:

```
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

```
######Result:
![termcolor Reversed colors](https://raw.github.com/cyounes/termcolor/master/examples/example_termcolor.png)
-


###Who am i ?
My name is [Younes Cheikh][1] C-addicted, student and desktop applications developer, follow me on [twitter][2] or visite my [personal website][3] :)


[1]: http://github.com/cyounes/        "c.Younes on github"
[2]: http://twitter/cyounes  "@cyounes"
[3]: http://cyounes.com/    "personal website"

