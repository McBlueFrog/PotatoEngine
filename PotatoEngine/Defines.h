#pragma once


#define black 0x0010
#define gray FOREGROUND_INTENSITY
#define white FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
#define blue FOREGROUND_BLUE
#define green FOREGROUND_GREEN
#define red FOREGROUND_RED
#define lightblue FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define lightgreen FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define lightred FOREGROUND_RED | FOREGROUND_INTENSITY
#define purple FOREGROUND_BLUE | FOREGROUND_RED
#define pink FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY
#define solidcyan FOREGROUND_BLUE | FOREGROUND_GREEN
#define cyan FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define yellow FOREGROUND_RED | FOREGROUND_GREEN
#define lemon FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY


#define fullPixel char(219) 
#define halfPixel char(178) 
#define thirdPixel char(177) 
#define quarterPixel char(176) 


#define bluebackground BACKGROUND_BLUE 
#define redbackground BACKGROUND_RED
#define greenbackground BACKGROUND_GREEN