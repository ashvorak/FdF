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

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    (argc == 2) ? fd = open(argv[1], O_RDONLY) : exit(1);
    while (get_next_line(fd, line))
    return (0);
}