#pragma once


const unsigned char ScreenWidth = 230;
const unsigned char ScreenHeight = 110;


char* CharBuffer = new char[ScreenWidth * ScreenHeight];
WORD* AttrBuffer = new WORD[ScreenWidth * ScreenHeight];


HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
DWORD dwBytesWritten,dwNumberOfAttrsWritten = 0;
HWND consoleWindow = GetConsoleWindow();
HDC consoleDC = GetDC(consoleWindow);


void InitWindow()
{
	SetConsoleTitle("Potato Engine");
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 8;
	cfi.dwFontSize.Y = 8;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, 9, L"Terminal");
	SetCurrentConsoleFontEx(console, FALSE, &cfi);

	COORD a;
	a.X = ScreenHeight;
	a.Y = ScreenWidth;


	SMALL_RECT rect{};
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = ScreenHeight;
	rect.Right = ScreenWidth;

	SetConsoleWindowInfo(console, 1, &rect);
	SetConsoleScreenBufferSize(console, a);
	

	SetConsoleActiveScreenBuffer(console);
}

void RefreshScreen()
{
	WriteConsoleOutputCharacter(console, CharBuffer, ScreenHeight * ScreenWidth, { 0,0 }, &dwBytesWritten);
	WriteConsoleOutputAttribute(console, AttrBuffer, ScreenHeight * ScreenWidth, { 0,0 }, &dwNumberOfAttrsWritten);
	SetConsoleCursorPosition(console, { 0,0 });
}


void ClearBuffer(char clearChar = char(219), WORD clearAttr = 0x0010)
{

	for (int x = 0; x < ScreenHeight * ScreenWidth; x++)
	{
		CharBuffer[x] = clearChar;
		AttrBuffer[x] = clearAttr;
	}

}