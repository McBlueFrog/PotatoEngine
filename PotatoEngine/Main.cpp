#include <windows.h>
#include <iostream>
#include <memory.h>
#include <chrono>
#include <string>
#include "Init.h"
#include "Graphics.h"
#include "Defines.h"

using namespace std;



auto beginTime = std::chrono::system_clock::now();
auto tp1 = std::chrono::system_clock::now();
auto tp2 = std::chrono::system_clock::now();
std::chrono::duration<float> elapsedTime = tp2 - tp1;
float fElapsedTime,runTime;



int i = 0;
int main()
{
	InitWindow();
	ClearBuffer();
	while (true)
	{
		runTime = runTime + fElapsedTime;
		tp2 = std::chrono::system_clock::now();
		elapsedTime = tp2 - tp1;
		///



		Text(0, 0, "FPS:", 1 / fElapsedTime, gray);
		Text(0, 1, "Runtime:", runTime, gray);
		Text(0, 2, "DrawCalls:", drawCalls, gray);
		drawCalls = 0;


		///
		RefreshScreen();
		ClearBuffer(fullPixel, blue);
		
		tp1 = tp2;
		fElapsedTime = elapsedTime.count();
	}

	FreeConsole();
	ReleaseDC(consoleWindow,consoleDC);
	return 0;
}