#include "../inc/fdf.h"

int ret_color(char *color)
{
	if (!ft_strcmp(color, "0xFFFFFF"))
		return (16777215);
	return (0);
}

