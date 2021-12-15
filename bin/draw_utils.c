/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:37:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:37:16 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_small(int i, int j, t_data *gd, unsigned int *adr)
{
	unsigned int	*dst;
	unsigned int	*src;
	int				y;

	dst = gd->adr_img + i * gd->ll_img + j * (gd->bpp_img / 8);
	src = gd->adr_back;
	i = -1;
	while (++i < 64)
	{
		j = 0;
		y = 0;
		while (j < 64 * gd->ll_small / 4)
		{
			if (adr[i + j] != 0xFF000000)
				dst[i + y] = adr[i + j];
			else if (adr != gd->adr_pls && adr != gd->adr_plw && \
			adr != gd->adr_pla && adr != gd->adr_pld)
				dst[i + y] = src[i + j];
			j += gd->ll_small / 4;
			y += gd->ll_img / 4;
		}
	}
}

void	put_player(t_par *m, t_data *gd)
{
	(void)m;
	if (gd->f_view == 's')
		put_small(gd->pl_y, gd->pl_x, gd, gd->adr_pls);
	else if (gd->f_view == 'w')
		put_small(gd->pl_y, gd->pl_x, gd, gd->adr_plw);
	else if (gd->f_view == 'a')
		put_small(gd->pl_y, gd->pl_x, gd, gd->adr_pla);
	else if (gd->f_view == 'd')
		put_small(gd->pl_y, gd->pl_x, gd, gd->adr_pld);
}

void	draw_image(t_par *m, t_data *gd, char flg_first)
{
	int	i;
	int	j;

	count_offset_w(m, gd);
	count_offset_h(m, gd);
	i = count_borders(m, gd, 0, flg_first) - 1;
	while (++i < (m->i_border))
	{
		j = count_borders(m, gd, 1, flg_first) - 1;
		while (++j < (m->j_border))
		{
			if ((m->map)[i][j] == '0')
				put_small(i * 64, j * 64, gd, gd->adr_back);
			else if ((m->map)[i][j] == '1')
				put_small(i * 64, j * 64, gd, gd->adr_wall);
			else if ((m->map)[i][j] == 'C')
				put_small(i * 64, j * 64, gd, gd->adr_coll);
			else if ((m->map)[i][j] == 'E')
				put_small(i * 64, j * 64, gd, gd->adr_ex);
		}
	}
	if (!gd->f_winner)
		put_player(m, gd);
}

void	count_offset_w(t_par *m, t_data *gd)
{
	int			w;
	static char	flg;

	w = m->width * 64;
	if (gd->flg_big_map != 1 && gd->flg_big_map != 3)
		return ;
	if (!flg)
	{
		gd->w_s = -(gd->pl_x - m->win_w / 2);
		if (-(gd->w_s) + m->win_w > w)
			gd->w_s = m->win_w - w;
		else if (gd->w_s > 0)
			gd->w_s = 0;
		flg = 1;
		return ;
	}
	if (gd->f_move == 'd' && gd->pl_x + gd->w_s > m->win_w / 2 && \
	m->win_w - (gd->w_s - gd->pl_speed) < w)
		gd->w_s -= gd->pl_speed;
	else if (gd->f_move == 'a' && gd->pl_x + gd->w_s < m->win_w / 2 \
			&& gd->w_s + gd->pl_speed <= 0)
		gd->w_s += gd->pl_speed;
}

void	count_offset_h(t_par *m, t_data *gd)
{
	int			h;
	static char	flg;

	if (gd->flg_big_map != 1 && gd->flg_big_map != 2)
		return ;
	h = m->lines * 64;
	if (!flg)
	{
		gd->h_s = -(gd->pl_y - m->win_h / 2);
		if (-(gd->h_s) + m->win_h > h)
			gd->h_s = m->win_h - h;
		else if (gd->h_s > 0)
			gd->h_s = 0;
		flg = 1;
		return ;
	}
	if (gd->f_move == 's' && gd->pl_y > m->win_h / 2 - gd->h_s && \
		m->win_h - (gd->h_s - gd->pl_speed) <= h)
		gd->h_s -= gd->pl_speed;
	else if (gd->f_move == 'w' && gd->pl_y < m->win_h / 2 - gd->h_s && \
		gd->h_s + gd->pl_speed <= 0)
		gd->h_s += gd->pl_speed;
}
