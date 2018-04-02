/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:27:58 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/30 15:28:00 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	make_list(t_proj *proj, char *buf)
{
	int		x;
	int		y;
	char	**arr;
	char 	*tmp;

	y = 0;
	arr = ft_strsplit(buf, ' ');
	proj->list = (t_coor**)malloc(sizeof(t_coor*) * proj->width * proj->height);
	while (y < proj->height)
	{
		x = 0;
		proj->list[y] = (t_coor*)malloc(sizeof(t_coor) * proj->width);
		while (x < proj->width)
		{
			proj->list[y][x].x = x;
			proj->list[y][x].y = y;
			proj->list[y][x].z = ft_atoi(*arr);
			if (ft_strstr(*arr, ","))
			{
				tmp = ft_strchr(*arr, ',');
				proj->list[y][x].color = ft_atoi_base(&tmp[3], 16);
			}
			x++;
			arr++;
		}
		y++;
	}
}

static void	scaling(t_proj *proj)
{
	double scale;

	if (WIN_X - proj->list[0][proj->width - 1].x > WIN_Y - proj->list[proj->height - 1][0].y)
		scale = WIN_X / proj->list[0][proj->width - 1].x;
	else
		scale = WIN_Y / proj->list[proj->height - 1][0].y;
	scale = (scale / 100) * SCALE;
	zoom(proj, scale);
}

static	void	centering(t_proj *proj)
{
	int		x;
	int		y;
	double	dx;
	double	dy;

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

void	read_file(int fd, t_proj *proj)
{
	char 	*buf;
	char	*line;
	char 	**arr;

	get_next_line(fd, &line);
	buf = ft_strdup(line);
	//ft_strdel(&line);
	arr = ft_strsplit(buf, ' ');
	proj->width = 0;
	while (*(arr++))
		proj->width++;
	buf = ft_strjoin(buf, " ");
	proj->height = 1;
	while (get_next_line(fd, &line))
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, " ");
		//ft_strdel(&line);
		proj->height++;
	}
	make_list(proj, buf);
	scaling(proj);
	centering(proj);
}

