#pragma once
int drawCalls = 0;



void Text(SHORT y, SHORT x, std::string text = "",float value = NULL, WORD Attr = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
{
	drawCalls++;
	char p;
	size_t len;
	std::string svalue;
	if (value != NULL)
	{
		svalue = std::to_string(value);
		len = text.length() + svalue.length();
	}
	else
	{
		len = text.length();
		svalue = "";
	}
	std::string all = text + svalue;

	for (int i = 0; i < len; ++i)
	{
		p = all[i];
		CharBuffer[y + i + (x * ScreenWidth)] = p;
		AttrBuffer[y + i + (x * ScreenWidth)] = Attr;
	}

}

void Pixel(unsigned char height, unsigned char width,WORD Attr = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
{
	drawCalls++;
	if (height <= ScreenHeight - 1 && height >= 0 && width <= ScreenWidth - 1 && width >= 0)
	{
		AttrBuffer[width + (height * ScreenWidth)] = Attr;
	}
}

void Line(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2,WORD Attr = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
{
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		Pixel(x, y, Attr);
		for (i = 0; x < xe; ++i)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					++y;
				}
				else
				{
					--y;
				}
				px = px + 2 * (dy1 - dx1);
			}

			Pixel(x, y, Attr);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		Pixel(x, y, Attr);
		for (i = 0; y < ye; ++i)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					++x;
				}
				else
				{
					--x;
				}
				py = py + 2 * (dx1 - dy1);
			}
			Pixel(x, y, Attr);
		}
	}
}