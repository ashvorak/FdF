/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/29 17:59:07 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	make_list(t_proj *proj, char *buf)
{
	int		x;
	int		y;
	char	**arr;

	x = 0;
	arr = ft_strsplit(buf, ' ');
	proj->list = (t_coor**)malloc(sizeof(t_coor*) * proj->width * proj->height);
	while (x < proj->height)
	{
		y = 0;
		proj->list[x] = (t_coor*)malloc(sizeof(t_coor) * proj->width);
		while (y < proj->width)
		{
			proj->list[x][y].x = x;
			proj->list[x][y].y = y;
			proj->list[x][y].z = ft_atoi(*arr);
			y++;
			arr++;
		}
		x++;
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
	while (*arr)
	{
		proj->width++;
		arr++;
	}
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
}

t_proj *new_proj()
{
	t_proj *proj;

	if (!(proj = (t_proj*)malloc(sizeof(t_proj))))
		return (NULL);
	proj->list = NULL;
	proj->mlx_ptr = NULL;
	proj->win_ptr = NULL;
	proj->width = 0;
	proj->height = 0;
	return (proj);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	int		fd;
	t_proj	*proj;

	i = 0;
	j = 0;
	proj = new_proj();
	(argc == 2) ? fd = open(argv[1], O_RDONLY) : exit(1);
	read_file(fd, proj);
	while (i < proj->height)
	{
		j = 0;
		while (j < proj->width)
		{
			printf("%.0f ", proj->list[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
	//proj->mlx_ptr = mlx_init();
	//proj->win_ptr = mlx_new_window(proj->mlx_ptr, 1000, 1000, "test");
	//mlx_loop(proj->mlx_ptr);
	return (0);
}
