/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:38:24 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:38:26 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_w(t_par *m, t_data *gd, char w)
{
	int	i;
	int	j;

	i = (gd->pl_y + 20 - gd->pl_speed) / 64;
	j = ((gd->pl_x + 25) / 64);
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	j = ((gd->pl_x + 64 - 25) / 64);
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	return (1);
}

int	check_s(t_par *m, t_data *gd, char w)
{
	int	i;
	int	j;

	i = (gd->pl_y + 64 - 20 + gd->pl_speed) / 64;
	j = (gd->pl_x + 25) / 64;
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	j = ((gd->pl_x + 64 - 25) / 64);
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	return (1);
}

int	check_a(t_par *m, t_data *gd, char w)
{
	int	i;
	int	j;

	j = (gd->pl_x - gd->pl_speed + 25) / 64;
	i = (gd->pl_y + 20) / 64;
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	i = (gd->pl_y + 64 - 20) / 64;
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	return (1);
}

int	check_d(t_par *m, t_data *gd, char w)
{
	int	i;
	int	j;

	j = (gd->pl_x + gd->pl_speed + 64 - 25) / 64;
	i = (gd->pl_y + 20) / 64;
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	i = (gd->pl_y + 64 - 20) / 64;
	if ((m->map)[i][j] == w)
	{
		if (w == 'C')
			(m->map)[i][j] = '0';
		return (0);
	}
	return (1);
}

int	count_borders(t_par *m, t_data *gd, char flg, char flg_first)
{
	if (flg_first)
	{
		m->i_border = (int)m->lines;
		m->j_border = (int)m->width;
		return (0);
	}
	if (!flg && (gd->flg_big_map == 1 || gd->flg_big_map == 2))
	{
		m->i_border = (-gd->h_s + m->win_h) / 64 + 1;
		if (m->i_border > (int)m->lines)
			m->i_border = (int)m->lines;
		if (-gd->h_s / 64 > 0)
			return (-gd->h_s / 64 - 1);
	}
	else if (flg && (gd->flg_big_map == 1 || gd->flg_big_map == 3))
	{
		m->j_border = (-gd->w_s + m->win_w) / 64 + 1;
		if (m->j_border > (int)m->width)
			m->j_border = (int)m->width;
		if (-gd->w_s / 64 - 1 > 0)
			return (-gd->w_s / 64 - 1);
	}
	return (0);
}
