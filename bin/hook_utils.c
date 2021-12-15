/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:37:57 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:37:59 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	press(int key, t_par *m)
{
	if (key == W || key == A || key == S || key == D)
	{
		m->gd->f_view = key;
		m->gd->f_move = key;
	}
	else if (key == ESC)
		red_cross(m);
	return (0);
}

int	release(int key, t_par *m)
{
	if (key == W || key == A || key == S || key == D)
	{
		if (m->gd->f_move == key)
			m->gd->f_move = 0;
	}
	return (0);
}

int	draw_frame(t_par *m)
{
	if (!m->gd->f_winner)
		game_play(m, m->gd);
	if (m->gd->f_winner == 1)
		m->gd->adr_back = m->gd->adr_wnr;
	draw_image(m, m->gd, 0);
	mlx_put_image_to_window(m->mlx, m->win, m->gd->img, m->gd->w_s, m->gd->h_s);
	return (0);
}
