/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:38:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:38:15 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	count_speed(t_par *mp)
{
	if (mp->gd->flg_big_map == 1)
		mp->gd->pl_speed = 4;
	else if (mp->gd->flg_big_map && mp->lines > 11 && mp->width > 15)
		mp->gd->pl_speed = 3;
	else if ((mp->lines > 5 || mp->width > 10) \
	&& !(mp->lines <= 5 || mp->width <= 7))
		mp->gd->pl_speed = 2;
}

void	lets_play(t_par *mp)
{
	char	res;

	prepare(mp);
	if (mp->lines * 64 > 900 && mp->width * 64 > 1600)
		mp->gd->flg_big_map = 1;
	else if (mp->lines * 64 > 900)
		mp->gd->flg_big_map = 2;
	else if (mp->width * 64 > 1600)
		mp->gd->flg_big_map = 3;
	else
		mp->gd->flg_big_map = 0;
	count_speed(mp);
	res = norm_game(mp);
	if (res == 'n')
		write(2, "ft not found\n", 13);
	else if (res == '\0')
	{
		destroy_images(mp);
		free(mp->gd);
		quit_game(mp, 3);
	}
	free(mp->gd);
	quit_game(mp, 4);
}

char	norm_game(t_par *m)
{
	m->gd->h_s = 0;
	m->gd->w_s = 0;
	m->gd->img = mlx_new_image(m->mlx, m->width * 64, m->lines * 64);
	if (m->gd->img == NULL)
		quit_game(m, 5);
	m->gd->adr_img = mlx_get_data_addr(m->gd->img, &(m->gd->bpp_img), \
	&(m->gd->ll_img), &(m->gd->e_img));
	draw_image(m, m->gd, 1);
	m->win = mlx_new_window(m->mlx, m->win_w, m->win_h, "so_long");
	if (!(m->win))
		return (0);
	mlx_hook(m->win, 2, 1L << 0, press, m);
	mlx_hook(m->win, 3, 1L << 1, release, m);
	mlx_hook(m->win, 17, 1L << 17, red_cross, m);
	mlx_loop_hook(m->mlx, draw_frame, m);
	mlx_loop(m->mlx);
	return (13);
}
