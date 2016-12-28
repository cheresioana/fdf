/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpoint_fromstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:29:10 by icheres           #+#    #+#             */
/*   Updated: 2016/04/01 14:29:51 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_3d	getpoint_fromstr(char *s, t_lc *ij)
{
	t_3d	point;
	char	**array;

	array = ft_split_whitespaces(s, ' ');
	point.z = getnbr(array[ij->col]);
	point.x = ij->lin;
	point.y = ij->col;
	return (point);
}
