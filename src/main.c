/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:22:23 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/26 18:32:38 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
/*
t_coor	**read_file(int fd)
{
    char	*line;
    char	**arr;
	t_coor	*coor;

    while (get_next_line(fd, &line))
    {
		
    }
    return (coor);
}
*/
int	main(void)
{
    //int		fd;
    //char	**map;
	void	*mlx_ptr;
	void	*win_ptr;

	//(argc == 2) ? fd = open(argv[1], O_RDONLY) : exit(1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_loop(mlx_ptr);
	return (0);
}
