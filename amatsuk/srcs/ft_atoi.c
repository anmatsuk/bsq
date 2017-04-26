/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <amatsuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:15:09 by amatsuk           #+#    #+#             */
/*   Updated: 2017/04/10 16:42:39 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check_str(char *str, int index)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (str != '\0' && flag)
	{
		if (*(str + i) == '\t')
			index++;
		if (*(str + i) == '\n')
			index++;
		if (*(str + i) == ' ')
			index++;
		if (*(str + i) == '\v')
			index++;
		if (*(str + i) == '\f')
			index++;
		if (*(str + i) == '\r')
			index++;
		if (*(str + i) >= '0' && *(str + i) <= '9')
			flag = 0;
		i++;
	}
	return (index);
}

int		negative(char *str, int index, int *sign)
{
	int i;

	*sign = 0;
	i = index;
	if (*(str + i) == '-')
	{
		*sign = 1;
		return (i + 1);
	}
	else if (*(str + i) == '+')
	{
		return (i + 1);
	}
	else
		return (index);
}

int		ft_atoi(char *str, int *len)
{
	int i;
	int k;
	int res;
	int sign;

	res = 0;
	k = 1;
	i = check_str(str, 0);
	i = negative(str, i, &sign);
	while (*(str + i) >= '0' && *(str + i) <= '9' && *(str + i) != '\0')
	{
		res = (*(str + i) - '0') + res * k;
		k = 10;
		i++;
	}
	*len = i;
	if (sign)
		res *= -1;
	return (res);
}
