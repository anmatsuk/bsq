/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 23:16:21 by amatsuk           #+#    #+#             */
/*   Updated: 2017/04/25 23:16:23 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

extern int g_ii;
extern int g_jj;
extern int g_max;

void	set_square(int ***tab)
{
	int i;
	int j;

	i = g_ii - g_max + 1;
	while (i <= g_ii)
	{
		j = g_jj - g_max + 1;
		while (j <= g_jj)
		{
			(*tab)[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	show_matrix(int **tab, int size, int len)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < len)
		{
			if (tab[i][j] == -1)
				ft_putchar(g_full);
			else if (tab[i][j] == 0)
				ft_putchar(g_obstacle);
			else
				ft_putchar(g_empty);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int		size_error(char **res, int size)
{
	int i;

	i = 0;
	if (res == NULL)
		return (1);
	while (i < size + 1)
	{
		if (res[i] == NULL)
			return (1);
		i++;
	}
	if (res[size + 1] != NULL)
		return (1);
	return (0);
}
