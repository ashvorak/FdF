/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:59:59 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/30 13:46:06 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	display(t_proj *proj)
{
	int x;
	int y;

	proj->pixels = (int*)mlx_get_data_addr(proj->win_image, &proj->bits_per_pixel,
		&proj->size_line, &proj->endian);
	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			if (y + 1 < proj->height)
				line(proj, proj->list[y][x], proj->list[y + 1][x]);
			if (x + 1 < proj->width)
				line(proj, proj->list[y][x], proj->list[y][x + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(proj->mlx_ptr, proj->win_ptr, proj->win_image, 0, 0);
}