/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:40:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/30 17:37:53 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include  <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include "../lib/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../minilibx/mlx.h"
# include "../minilibx_macos/mlx.h"

#define WIN_X 1500
#define	WIN_Y 1000
#define SCALE 30

typedef struct	s_coor
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_coor;

typedef struct	s_proj
{
	t_coor	**list;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_image;
	int		width;
	int		height;
	int		*pixels;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_proj;

void	read_file(int fd, t_proj *proj);
void	zoom(t_proj *proj, double scale);
void	modification(t_proj *proj, double dx, double dy, double dz);
void	display(t_proj *proj);
void	line(t_proj *gen, t_coor t1, t_coor t2);
int		move(int key, t_proj *proj);
void	rotation(t_proj *proj, int key);

#endif
