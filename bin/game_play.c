/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:37:43 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:37:46 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_play(t_par *m, t_data *gd)
{
	if (gd->f_move == 'w' && check_wall('w', m, gd, '1'))
		gd->pl_y -= gd->pl_speed;
	else if (gd->f_move == 's' && check_wall('s', m, gd, '1'))
		gd->pl_y += gd->pl_speed;
	else if (gd->f_move == 'a' && check_wall('a', m, gd, '1'))
		gd->pl_x -= gd->pl_speed;
	else if (gd->f_move == 'd' && check_wall('d', m, gd, '1'))
		gd->pl_x += gd->pl_speed;
	if (m->f_c != 0)
		check_collect(m, gd);
	else if (gd->f_winner != 1)
		check_exit(m, gd);
	if (gd->f_move && m->mv_count != m->tmp_mv_count && gd->f_winner != 1)
	{
		printf("%.2f\n", (float)m->mv_count / 64);
		m->tmp_mv_count = m->mv_count;
	}
}

void	check_collect(t_par *m, t_data *gd)
{
	static char	flg;

	if ((gd->f_move == 'w' && check_wall('w', m, gd, 'C') == 0) || \
	(gd->f_move == 's' && check_wall('s', m, gd, 'C') == 0) || \
	(gd->f_move == 'a' && check_wall('a', m, gd, 'C') == 0) || \
	(gd->f_move == 'd' && check_wall('d', m, gd, 'C') == 0))
		(m->f_c)--;
	if (m->f_c == 0 && !flg)
	{
		flg = 1;
		gd->adr_ex = mlx_get_data_addr(gd->ex2, &(gd->bpp_small), \
		&(gd->ll_small), &(gd->e_small));
	}
}

void	check_exit(t_par *m, t_data *gd)
{
	static char	flg;

	if ((gd->f_move == 'w' && check_wall('w', m, gd, 'E') == 0) || \
	(gd->f_move == 's' && check_wall('s', m, gd, 'E') == 0) || \
	(gd->f_move == 'a' && check_wall('a', m, gd, 'E') == 0) || \
	(gd->f_move == 'd' && check_wall('d', m, gd, 'E') == 0))
	{
		gd->f_winner = 1;
		printf("total steps = %.2f\n", (float)m->mv_count / 64);
	}
	if (gd->f_winner && !flg)
	{
		flg = 1;
		gd->adr_ex = mlx_get_data_addr(gd->ex3, &(gd->bpp_small), \
		&(gd->ll_small), &(gd->e_small));
	}
}

int	check_wall(char c, t_par *m, t_data *gd, char w)
{
	if (c == 'w')
	{
		if (check_w(m, gd, w) == 0)
			return (0);
	}
	else if (c == 's')
	{
		if (check_s(m, gd, w) == 0)
			return (0);
	}
	else if (c == 'a')
	{
		if (check_a(m, gd, w) == 0)
			return (0);
	}
	else if (c == 'd')
	{
		if (check_d(m, gd, w) == 0)
			return (0);
	}
	if (w == '1')
		m->mv_count += gd->pl_speed;
	return (1);
}
