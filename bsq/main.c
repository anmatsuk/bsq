/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:42:44 by amatsuk           #+#    #+#             */
/*   Updated: 2017/04/24 16:42:46 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

extern char	g_empty;
extern char	g_obstacle;
extern char	g_full;
extern int g_ii;
extern int g_jj;
extern int g_max;

void	show_error(int index)
{
	if (index != 0)
		ft_putchar('\n');
	ft_putstr("map error\n");
}

void	bsq(int fd, int i, int index, int **res)
{
	char	**fl;

	fl = ft_split_whitespaces(read_input(fd));
	if (fl != NULL)
	{
		i = parse_first_line(*fl);
		if (size_error(fl, i) || fd == -1)
			show_error(index);
		else
		{
			g_max = 0;
			res = create_table(fl, i);
			if (!res)
				show_error(index);
			else
			{
				set_square(&res);
				if (index != 0)
					ft_putchar('\n');
				show_matrix(res, i, ft_strlen(fl[1]));
			}
		}
	}
	else
		show_error(index);
}

int		main(int ac, char **av)
{
	int		i;
	int		index;
	int		fd;
	int		**res;

	av++;
	index = 0;
	res = NULL;
	i = 0;
	if (ac == 1)
		bsq(0, i, index, res);
	else
	{
		while (*av)
		{
			if ((fd = open(*av, O_RDONLY)) != -1)
				bsq(fd, i, index, res);
			else
				show_error(index);
			av++;
			index++;
			close(fd);
		}
	}
	return (0);
}
