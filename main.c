/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:18:36 by icheres           #+#    #+#             */
/*   Updated: 2016/12/28 18:28:12 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init(t_mlx *c)
{
	static int	ok = 0;

	if (ok == 0)
	{
		if ((c->mlx = mlx_init()) == NULL)
			err('m');
		if ((c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "fdf")) == NULL)
			err('w');
		ok = 1;
	}
}

t_config	get_config(int lin, int col)
{
	t_config	conf;

	conf.spacing = 0.75 * (WIDTHIMG / (lin * 0.5 + col * 0.86));
	conf.cols = col;
	conf.rows = lin;
	conf.unghi = 30;
	conf.angle = 30 * M_PI / 180;
	conf.move_x = 0;
	conf.move_y = 0;
	conf.hight = 0.10;
	return (conf);
}

int			main(int argc, char *av[])
{
	char		*c;
	t_config	config;
	t_lc		lc;
	t_3d		**tab;

	lc.lin = 0;
	lc.col = 0;
	if (argc != 2)
		err('a');
	g_k = -1;
	tab = get_data(av[1], &lc);
	config = get_config(lc.lin, lc.col);
	clean_version(tab, &config);
	return (0);
}
