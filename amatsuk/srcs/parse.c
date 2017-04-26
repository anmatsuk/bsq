/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:41:39 by amatsuk           #+#    #+#             */
/*   Updated: 2017/04/24 16:41:41 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ft.h"
#include <stdlib.h>

extern char	g_empty;
extern char	g_obstacle;
extern char	g_full;
extern int g_ii;
extern int g_jj;
extern int g_max;

char	*read_input(int fd)
{
	char	*input;
	char	*buf;
	char	*tmp;
	long	sz;
	int		ret;

	buf = NULL;
	sz = BUF_SIZE;
	input = malloc(BUF_SIZE + 1);
	while ((ret = read(fd, input, BUF_SIZE)) > 0)
	{
		input[ret] = '\0';
		tmp = buf;
		sz += BUF_SIZE;
		buf = malloc(sz + 1);
		ft_strcpy(buf, tmp);
		ft_strcat(buf, input);
		free(tmp);
	}
	free(input);
	return (buf);
}

int		parse_first_line(char *line)
{
	int i;
	int size;

	size = ft_atoi(line, &i);
	if (ft_strlen(line) != (i + 3))
		return (-1);
	else
	{
		g_empty = line[i];
		g_obstacle = line[i + 1];
		g_full = line[i + 2];
	}
	return (size);
}

int		weight(int *prev, int *curr_int, char *curr, int j)
{
	int min;

	if (curr[j] == g_obstacle)
		return (0);
	if (curr[j] != g_obstacle && curr[j] != g_empty)
		return (-1);
	if (prev == NULL || j == 0)
		return (1);
	min = prev[j - 1];
	if (min > prev[j])
		min = prev[j];
	if (min > curr_int[j - 1])
		min = curr_int[j - 1];
	return (min + 1);
}

void	set_max(int val, int i, int j)
{
	if (g_max < val)
	{
		g_max = val;
		g_ii = i - 1;
		g_jj = j;
	}
}

int		**create_table(char **fl, int size)
{
	int i;
	int j;
	int **r;

	i = 1;
	j = 0;
	r = (int**)malloc(sizeof(int*) * size);
	while (i < size + 1)
	{
		j = 0;
		if (ft_strlen(fl[i]) != ft_strlen(fl[1]))
			return (NULL);
		r[i - 1] = (int*)malloc(sizeof(int) * (ft_strlen(fl[1])));
		while (j < ft_strlen(fl[1]))
		{
			if (weight(i == 1 ? NULL : r[i - 2], r[i - 1], fl[i], j) == -1)
				return (NULL);
			r[i - 1][j] = weight(i == 1 ? NULL : r[i - 2], r[i - 1], fl[i], j);
			if (g_max < r[i - 1][j])
				set_max(r[i - 1][j], i, j);
			j++;
		}
		i++;
	}
	return (r);
}
