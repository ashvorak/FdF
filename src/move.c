/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:37:00 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/30 15:45:47 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
/*
static	void	centering(t_proj *proj)
{
	int x;
	int y;
	double dx;
	double dy;

	y = 0;
	dx = WIN_X / 2 - proj->list[0][proj->width - 1].x / 2;
	dy = WIN_Y / 2 - proj->list[proj->height - 1][0].y / 2;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			proj->list[y][x].x += dx;
			proj->list[y][x].y += dy;
			x++;
		}
		y++;
	}
}
*/
int move(int key, t_proj *proj)
{
	if (key == 123)
		modification(proj, -10, 0, 0);
	else if (key == 124)
		modification(proj, 10, 0, 0);
	else if (key == 125)
		modification(proj, 0, 10, 0);
	else if (key == 126)
		modification(proj, 0, -10, 0);
	else if (key == 69)
		zoom(proj, 1.1);
	else if (key == 78)
		zoom(proj, 0.9);	
	mlx_clear_window(proj->mlx_ptr, proj->win_ptr);
	ft_bzero(proj->pixels, WIN_X * WIN_Y * 4);
	proj->size_line = 0;
	mlx_put_image_to_window(proj->mlx_ptr, proj->win_ptr, proj->win_image, 0, 0);
	display(proj);
	return (0);
}