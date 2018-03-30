/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/30 14:56:48 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
	proj->pixels = NULL;
	proj->bits_per_pixel = 0;
	proj->size_line = 0;
	proj->endian = 0;
	return (proj);
}

int exit_x()
{
	exit(0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	t_proj	*proj;

	i = 0;
	proj = new_proj();
	(argc == 2) ? fd = open(argv[1], O_RDONLY) : exit(1);
	read_file(fd, proj);
	while (i < proj->height)
	{
		j = 0;
		while (j < proj->width)
		{
			printf("(%.0f, %.0f, %.0f)", proj->list[i][j].x, proj->list[i][j].y, proj->list[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
	proj->mlx_ptr = mlx_init();
	proj->win_ptr = mlx_new_window(proj->mlx_ptr, WIN_X, WIN_Y, "test");
	proj->win_image = mlx_new_image(proj->mlx_ptr, WIN_X, WIN_Y);
	display(proj);
	mlx_hook(proj->win_ptr, 2, 5, move, proj);
	mlx_hook(proj->win_ptr, 17, 1L << 17, exit_x, proj);
	mlx_loop(proj->mlx_ptr);
	return (0);
}
