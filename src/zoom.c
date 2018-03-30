#include "../inc/fdf.h"

void zoom(t_proj *proj, double scale)
{
	int x;
	int y;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			proj->list[y][x].x *= scale;
			proj->list[y][x].y *= scale;
			proj->list[y][x].z *= scale;
			x++;
		}
		y++;
	}
}

