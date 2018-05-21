/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:45:32 by amatsuk           #+#    #+#             */
/*   Updated: 2017/04/13 13:45:33 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft.h"

int		get_words_count(char *s)
{
	int flag;
	int i;
	int len;

	len = 0;
	i = 0;
	flag = 1;
	while (s[i] != '\0')
	{
		if (*(s + i) == '\t' || *(s + i) == '\n' || *(s + i) == ' ')
			flag = 1;
		else if (flag)
		{
			flag = 0;
			len++;
		}
		i++;
	}
	return (len);
}

int		get_word_position(char *s, int num)
{
	int		flag;
	int		i;
	int		len;

	len = 0;
	i = 0;
	flag = 1;
	while (s[i] != '\0')
	{
		if (*(s + i) == '\t' || *(s + i) == '\n' || *(s + i) == ' ')
			flag = 1;
		else if (flag)
		{
			if (num == len)
				return (i);
			flag = 0;
			len++;
		}
		i++;
	}
	return (0);
}

char	*get_word(int i, char *s)
{
	int		j;
	int		word_len;
	char	*word;

	j = i;
	word_len = 0;
	while (s[i] != '\t' && s[i] != '\n' && s[i] != ' ' && s[i] != '\0')
	{
		word_len++;
		i++;
	}
	i = 0;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	while (s[j] != '\t' && s[j] != '\n' && s[j] != ' ' && s[j] != '\0')
	{
		word[i] = s[j];
		i++;
		j++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		p;
	char	**res;
	int		len;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = get_words_count(str);
	res = (char**)malloc(sizeof(char*) * (len + 1));
	while (i < len)
	{
		p = get_word_position(str, i);
		res[i] = get_word(p, str);
		i++;
	}
	res[len] = NULL;
	return (res);
}
