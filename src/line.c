/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:03:38 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/30 16:22:23 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	void	put_pixel(int x, int y, t_proj *gen, int color)
{
	int i;

	if (x >= gen->size_line / 4 || x < 0 || y < 0 || y >= 1000)
		return ;
	i = (x + (y * (gen->size_line / 4)));
	if (color)
		gen->pixels[i] = color;
	else
		gen->pixels[i] = 16657966;
}

static	int		ft_incline(t_coor t1, t_coor t2)
{
	return (fabs(t2.y - t1.y) > fabs(t2.x - t1.x));
}

static	void	ft_swaps(t_coor *t1, t_coor *t2, int i)
{
	double	tmp;

	if (i == 1)
	{
		tmp = t1->x;
		t1->x = t1->y;
		t1->y = tmp;
		tmp = t2->x;
		t2->x = t2->y;
		t2->y = tmp;
	}
	else
	{
		tmp = t1->x;
		t1->x = t2->x;
		t2->x = tmp;
		tmp = t1->y;
		t1->y = t2->y;
		t2->y = tmp;
		tmp = (double)t1->color;
		t1->color = t2->color;
		t2->color = (int)tmp;
	}
}

void			line(t_proj *gen, t_coor t1, t_coor t2)
{
	double dx;
	double dy;
	double steep;
	double err;
	double ystep;

	if ((steep = ft_incline(t1, t2)))
		ft_swaps(&t1, &t2, 1);
	if (t1.x > t2.x)
		ft_swaps(&t1, &t2, 0);
	dx = t2.x - t1.x;
	dy = fabs(t2.y - t1.y);
	err = dx / 2;
	ystep = (t1.y < t2.y) ? 1 : -1;
	while (t1.x++ < t2.x)
	{
		put_pixel(steep ? t1.y : t1.x, steep ? t1.x : t1.y, gen, t1.color);
		err -= dy;
		if (err < 0)
		{
			t1.y += ystep;
			err += dx;
		}
	}
}