#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <math.h>
#include <surface.h>

namespace rend
{

	class line
	{
	public:
		line(rend::surface &surface, std::array<int, 2> loc, std::array<int, 2> loc2, char symbol)
		{
			int x1 = loc[0];
			int y1 = loc[1];
			int x2 = loc2[0];
			int y2 = loc2[1];

			int dx = abs(x2 - x1);
			int dy = abs(y2 - y1);
			int sx = (x1 < x2) ? 1 : -1;
			int sy = (y1 < y2) ? 1 : -1;
			int err = dx - dy;

			while (true)
			{
				surface.draw_at(x1, y1, symbol);

				if (x1 == x2 && y1 == y2)
					break;

				int err2 = 2 * err;

				if (err2 > -dy)
				{
					err -= dy;
					x1 += sx;
				}

				if (err2 < dx)
				{
					err += dx;
					y1 += sy;
				}
			}
		}
	};
}
