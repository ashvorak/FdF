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
			proj->list[y][x].x = proj->list[y][x].x * cos(angle) + proj->list[y][x].y * sin(angle);
			proj->list[y][x].y = -tmp * sin(angle) + proj->list[y][x].y * cos(angle);
			x++;
		}
		y++;
	}
}

void	rotation(t_proj *proj, int key)
{
	double angle;

	angle = 1 * M_PI / 180;
	if (key == 7)
		rotate_x(proj, angle);	
	else if (key == 16)
		rotate_y(proj, angle);
	else if (key == 6)
		rotate_z(proj, angle);
}
