/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:38:45 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:38:48 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_player_exit(t_par *m, t_data *gd)
{
	gd->pl_w = mlx_xpm_file_to_image(m->mlx, "xpm/PlW.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->pl_a = mlx_xpm_file_to_image(m->mlx, "xpm/PlA.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->pl_s = mlx_xpm_file_to_image(m->mlx, "xpm/PlS.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->pl_d = mlx_xpm_file_to_image(m->mlx, "xpm/PlD.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->ex = mlx_xpm_file_to_image(m->mlx, "xpm/ex.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->ex2 = mlx_xpm_file_to_image(m->mlx, "xpm/ex2.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->ex3 = mlx_xpm_file_to_image(m->mlx, "xpm/ex3.xpm", &(gd->w_s), \
	&(gd->h_s));
}

void	open_all_images(t_par *m, t_data *gd)
{
	gd->back = mlx_xpm_file_to_image(m->mlx, "xpm/b.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->wnr = mlx_xpm_file_to_image(m->mlx, "xpm/winner.xpm", &(gd->w_s), \
	&(gd->h_s));
	gd->wall = mlx_xpm_file_to_image(m->mlx, "xpm/11.xpm", &(gd->w_s), \
	&(gd->h_s));
	open_player_exit(m, gd);
	gd->coll = mlx_xpm_file_to_image(m->mlx, "xpm/c.xpm", &(gd->w_s), \
	&(gd->h_s));
	if (!(gd->back) || !(gd->wall) || !(gd->pl_w) || !(gd->pl_a) || \
	!(gd->pl_s) || !(gd->pl_d) || !(gd->coll) || !(gd->ex) || !(gd->wnr) \
	|| !(gd->ex2) || !(gd->ex3))
		quit_game(m, 5);
	get_adr_images(gd);
}

void	get_adr_images(t_data *gd)
{
	gd->adr_back = mlx_get_data_addr(gd->back, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_wall = mlx_get_data_addr(gd->wall, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_coll = mlx_get_data_addr(gd->coll, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_ex = mlx_get_data_addr(gd->ex, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_plw = mlx_get_data_addr(gd->pl_w, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_pla = mlx_get_data_addr(gd->pl_a, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_pls = mlx_get_data_addr(gd->pl_s, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_pld = mlx_get_data_addr(gd->pl_d, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
	gd->adr_wnr = mlx_get_data_addr(gd->wnr, &(gd->bpp_small), \
	&(gd->ll_small), &(gd->e_small));
}

void	prepare(t_par *m)
{
	m->gd = malloc(sizeof(t_data));
	if (!(m->gd))
		quit_game(m, 0);
	m->mlx = mlx_init();
	if (!(m->mlx))
	{
		free(m->gd);
		quit_game(m, 1);
	}
	open_all_images(m, m->gd);
	m->gd->f_winner = 0;
	m->gd->f_view = 's';
	m->gd->f_move = 0;
	if (m->lines < H_MAX / 64)
		m->win_h = (int)m->lines * 64;
	else
		m->win_h = H_MAX;
	if (m->width < W_MAX / 64)
		m->win_w = (int)m->width * 64;
	else
		m->win_w = W_MAX;
	m->gd->pl_x = (int)m->pl_x * 64;
	m->gd->pl_y = (int)m->pl_y * 64;
	m->gd->pl_speed = 1;
}
