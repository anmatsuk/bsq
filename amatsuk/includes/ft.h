/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:31:42 by amatsuk           #+#    #+#             */
/*   Updated: 2017/04/20 16:08:41 by amatsuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUF_SIZE 1024 * 1024 * 1024

char	g_empty;
char	g_obstacle;
char	g_full;
int		g_ii;
int		g_jj;
int		g_max;

int		ft_atoi(char *str, int *len);
char	**ft_split_whitespaces(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
char	*read_input(int fd);
int		parse_first_line(char *line);
int		**create_table(char **fl, int size);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	set_square(int ***tab);
void	show_matrix(int **tab, int size, int len);
int		size_error(char **res, int size);

#endif
