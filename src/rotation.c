/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:42:43 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/30 18:04:23 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	void	centering(t_proj *proj, double dx, double dy)
{
	int x;
	int y;

	y = 0;
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

void	rotate_x(t_proj *proj, double angle)
{
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			tmp = proj->list[y][x].y;
			proj->list[y][x].y = proj->list[y][x].y * cos(angle) + proj->list[y][x].z * sin(angle);
			proj->list[y][x].z = -tmp * sin(angle) + proj->list[y][x].z * cos(angle);
			x++;
		}
		y++;
	}
}

void	rotate_y(t_proj *proj, double angle)
{
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			tmp = proj->list[y][x].x;
			proj->list[y][x].x = proj->list[y][x].x * cos(angle) + proj->list[y][x].z * sin(angle);
			proj->list[y][x].z = -tmp * sin(angle) + proj->list[y][x].z * cos(angle);
			x++;
		}
		y++;
	}
}

void	rotate_z(t_proj *proj, double angle)
{
	int		x;
	int		y;
	double	tmp;

	y = 0;
	while (y < proj->height)
	{
		x = 0;
		while (x < proj->width)
		{
			tmp = proj->list[y][x].x;
			proj->list[y][x].x = proj->list[y][x].x * cos(angle) - proj->list[y][x].y * sin(angle);
			proj->list[y][x].y = tmp * sin(angle) + proj->list[y][x].y * cos(angle);
			x++;
		}
		y++;
	}
}

void	rotation(t_proj *proj, int key)
{
	double angle;
	double dx;
	double dy;

	dx = proj->list[0][0].x;//(proj->list[0][proj->width - 1].x + proj->list[0][0].x) / 2;
	dy = proj->list[0][0].y;//(proj->list[proj->height - 1][0].y + proj->list[0][0].y) / 2;
	angle = 5 * M_PI / 180;
	centering(proj, -dx, -dy);
	if (key == 6)
		rotate_z(proj, angle);
	else if (key == 7)
		rotate_x(proj, angle);
	else if (key == 16)
		rotate_y(proj, angle);
	centering(proj, dx, dy);
}