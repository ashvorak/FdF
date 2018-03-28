/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:40:03 by oshvorak          #+#    #+#             */
/*   Updated: 2018/03/28 17:29:31 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "../lib/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../minilibx/mlx.h"
# include "../minilibx_macos/mlx.h"

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
	char	*crd;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_proj; 

#endif
