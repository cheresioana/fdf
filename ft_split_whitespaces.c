/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 12:52:08 by icheres           #+#    #+#             */
/*   Updated: 2016/12/28 16:31:54 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*clean_special_chars(char *str)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		if (str[i] == '\t')
			aux[i] = ' ';
		else
			aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*clean(char *str, char del)
{
	t_ij	s;
	char	*aux;

	s.i = 0;
	s.j = 0;
	if (del == ' ')
		str = clean_special_chars(str);
	while (str[s.i] == del)
		s.i++;
	str += s.i;
	s.i = 0;
	aux = (char	*)malloc(sizeof(char) * (ft_strlen(str)));
	while (str[s.i])
	{
		if (str[s.i] == del && (str[s.i + 1] == '\0' || str[s.i + 1] == del))
			s.i++;
		else
		{
			aux[s.j] = str[s.i];
			s.j++;
			s.i++;
		}
	}
	aux[s.j] = '\0';
	return (aux);
}

int		ft_words(char *s, char delim)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == delim)
			count++;
		i++;
	}
	return (count + 2);
}

char	**ft_split_whitespaces(char *str, char delim)
{
	char	**words;
	int		idx;
	t_ij	s;

	initij(&s);
	idx = 0;
	str = clean(str, delim);
	words = (char **)malloc(sizeof(char *) * (ft_words(str, delim) + 2));
	while (str[s.i])
	{
		s.j = 0;
		words[idx] = (char *)malloc(sizeof(char) * (ft_strlen(str + s.i) + 2));
		while (str[s.i] && str[s.i] != delim)
		{
			words[idx][s.j] = str[s.i];
			s.i++;
			s.j++;
		}
		if (str[s.i])
			s.i++;
		words[idx][s.j] = '\0';
		if (s.j != 0)
			idx++;
	}
	return (words);
}
