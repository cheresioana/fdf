/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:29:54 by icheres           #+#    #+#             */
/*   Updated: 2016/04/01 14:30:47 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		is_clean(char *s)
{
	while (*s)
	{
		if (!(*s == ' ' || (*s >= '0' && *s <= '9') || (*s == '-' &&
						(*(s + 1) >= '0' && *(s + 1) <= '9'))))
			return (0);
		s++;
	}
	return (1);
}
