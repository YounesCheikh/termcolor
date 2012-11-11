/***
 * Termcolor Copyright &copy; 2012  
 *
 * This program is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with 
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * for more informations contact at <contact@cYounes.com>
 * 
 * author: Younes Cheikh
 *  
 */


/*
 * About: ANSII Color formatting for output in terminal.
 * TODO: Add code documentation
 * TODO: add Italic decoration
 */

#ifndef _TERMCOLOR_H
#define _TERMCOLOR_H

#include <stdio.h>

/*
 * Available colors 
 */
typedef enum {
  BLACK,  /*!< number 0 */
  RED,    /*!< number 1 */
  GREEN,  /*!< number 2 */
  YELLOW, /*!< number 3 */
  BLUE,   /*!< number 4 */
  MAGENTA,/*!< number 5 */
  CYAN,   /*!< number 6 */
  WHITE,   /*!< number 7 */
  DEFAULT  /*!< number 8 */ 
}
_COLOR_ ;

/*
 * Type Boolean
 */
typedef enum { 
  FALSE, /*!< Can be the integer 0 */
  TRUE  /*!< Can be the integer 1 */
} 
BOOLEAN;

/*
 * Standard variables
 */
BOOLEAN _BOLD_TEXT=FALSE,
		_HIGH_INTENSITY_FG=FALSE,
		_HIGH_INTENSITY_BG=FALSE,
		_UNDERLINE_TEXT=FALSE,
		_BLINK_TEXT=FALSE,
		_REVERSE_COLORS=FALSE;


int FGCOLOR, /*!< The forground chosed by the programer */
    BGCOLOR; /*!< The background chosed by the programer */

BOOLEAN _CHANGE_FGCOLOR=FALSE, /*!< this will be set TRUE if you         call the FG_COLOR_ON() function */                                          
       _CHANGE_BGCOLOR=FALSE; /*!< this will be set TRUE if you call the           FG_COLOR_ON() function */
    

/*
 * HEADERS
 */
    
void bgColor(_COLOR_ COLOR) ;

void fgColor(_COLOR_ COLOR) ;

void textBold(BOOLEAN status) ;

void textBlink(BOOLEAN status) ;

void colorReverse(BOOLEAN status);

void textUnderline(BOOLEAN status);

void highFgIntensity(BOOLEAN status) ;

void highBgIntensity(BOOLEAN status) ;

void setStyle() ;

void resetStyle() ;

/*
 * FUNCTIONS 
 */
void bgColor(_COLOR_ COLOR) {
	
	if (COLOR >=0 && COLOR <8 ) {
		BGCOLOR = (_HIGH_INTENSITY_BG==FALSE)?40:100 ;
		BGCOLOR = BGCOLOR + COLOR;
		_CHANGE_BGCOLOR = TRUE;
	} 
	else {
		_CHANGE_BGCOLOR = FALSE;
	}
	setStyle();
}

void fgColor(_COLOR_ COLOR) {
	
	if (COLOR >=0 && COLOR <8 ) {
		FGCOLOR = (_HIGH_INTENSITY_FG==FALSE)?30:90;
		FGCOLOR = FGCOLOR + COLOR;
		_CHANGE_FGCOLOR = TRUE;
	} 
	else {
		_CHANGE_FGCOLOR = FALSE;
	}
	setStyle();
}

void textBold(BOOLEAN status) {
  _BOLD_TEXT = status ;
  setStyle();
}

void textBlink(BOOLEAN status) {
	_BLINK_TEXT = status ;
	setStyle();
}

void colorReverse(BOOLEAN status) {
	_REVERSE_COLORS = status;
	setStyle();
}

void textUnderline(BOOLEAN status) {
	_UNDERLINE_TEXT = status ;
}

void highFgIntensity(BOOLEAN status) {
	_HIGH_INTENSITY_FG = status;
	setStyle();
}

void highBgIntensity(BOOLEAN status) {
	_HIGH_INTENSITY_BG = status;
	setStyle();
}

void setStyle() {
	
	int conf[6];
	
	conf[0] = (_BLINK_TEXT == FALSE) ? 0 : 5 ;
	conf[1]  = (_BOLD_TEXT  == FALSE) ? 0 : 1 ;
	conf[2] = (_UNDERLINE_TEXT == FALSE ) ? 0 : 4 ;
	conf[3] = (_CHANGE_FGCOLOR == FALSE ) ? 0 : FGCOLOR ;
	conf[4] = (_CHANGE_BGCOLOR == FALSE ) ? 0 : BGCOLOR ;
	conf[5] = (_REVERSE_COLORS == FALSE ) ? 0 : 7 ; 
	
	printf("\e[0m");
	int i ;
	for (i = 0 ; i< 6 ; i++) 
	{
		if (conf[i] !=0 )
			printf("\e[%dm", conf[i]);
	}
}

void resetStyle() {
  _BLINK_TEXT = FALSE; 
  _BOLD_TEXT = FALSE;
  _UNDERLINE_TEXT = FALSE;
  _REVERSE_COLORS = FALSE;
  FGCOLOR = 0 ;
  BGCOLOR = 0 ;
  setStyle();
}

#endif
