/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/28 18:02:24 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
//write height and width!!!
void	read_file(int fd, t_proj *proj)
{
	char	*line;

	get_next_line(fd, &line);
	proj->crd = ft_strdup(line);
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		proj->crd = ft_strjoin(proj->crd, " ");
		proj->crd = ft_strjoin(proj->crd, line);
		ft_strdel(&line);
	}
}

t_proj *new_proj()
{
	t_proj *proj;

	if (!(proj = (t_proj*)malloc(sizeof(t_proj))))
		return (NULL);
	proj->list = NULL;
	proj->crd = NULL;
	proj->mlx_ptr = NULL;
	proj->win_ptr = NULL;
	return (proj);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_proj	*proj;

	proj = new_proj();
	(argc == 2) ? fd = open(argv[1], O_RDONLY) : exit(1);
	proj->mlx_ptr = mlx_init();
	proj->win_ptr = mlx_new_window(proj->mlx_ptr, 1000, 1000, "test");
	mlx_loop(proj->mlx_ptr);
	return (0);
}
