/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:37:26 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:37:29 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	quit_game(t_par *mp, char flg)
{
	if (flg == 1)
		mp->f_correct = 'm';
	else if (flg == 2)
		mp->f_correct = 'i';
	else if (flg == 3)
		mp->f_correct = 'w';
	else if (flg == 4)
		mp->f_correct = 'u';
	else if (flg == 5)
	{
		mp->f_correct = 'I';
		destroy_images(mp);
	}
	if (mp->f_correct != 0)
		print_error(mp);
	free_map(mp);
	exit(0);
}

void	destroy_images(t_par *m)
{
	if (m->gd->img != NULL)
		mlx_destroy_image(m->mlx, m->gd->img);
	if (m->gd->back != NULL)
		mlx_destroy_image(m->mlx, m->gd->back);
	if (m->gd->wall != NULL)
		mlx_destroy_image(m->mlx, m->gd->wall);
	if (m->gd->pl_a != NULL)
		mlx_destroy_image(m->mlx, m->gd->pl_a);
	if (m->gd->pl_d != NULL)
		mlx_destroy_image(m->mlx, m->gd->pl_d);
	if (m->gd->pl_s != NULL)
		mlx_destroy_image(m->mlx, m->gd->pl_s);
	if (m->gd->pl_w != NULL)
		mlx_destroy_image(m->mlx, m->gd->pl_w);
	if (m->gd->coll != NULL)
		mlx_destroy_image(m->mlx, m->gd->coll);
	if (m->gd->ex != NULL)
		mlx_destroy_image(m->mlx, m->gd->ex);
	if (m->gd->ex2 != NULL)
		mlx_destroy_image(m->mlx, m->gd->ex2);
	if (m->gd->ex3 != NULL)
		mlx_destroy_image(m->mlx, m->gd->ex3);
	if (m->gd->wnr != NULL)
		mlx_destroy_image(m->mlx, m->gd->wnr);
}

int	red_cross(t_par *m)
{
	destroy_images(m);
	mlx_destroy_window(m->mlx, m->win);
	free(m->gd);
	quit_game(m, 0);
	return (0);
}
