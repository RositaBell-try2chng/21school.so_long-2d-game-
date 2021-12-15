/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:34 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:37 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_mp_p(t_par *mp_p)
{
	mp_p->f_correct = 0;
	mp_p->lines = 0;
	mp_p->width = 0;
	mp_p->tmp_width = 0;
	mp_p->map = NULL;
	mp_p->f_c = 0;
	mp_p->f_e = 0;
	mp_p->f_p = 0;
	mp_p->pl_x = 0;
	mp_p->pl_y = 0;
	mp_p->mlx = NULL;
	mp_p->win = NULL;
	mp_p->mv_count = 0;
	mp_p->tmp_mv_count = 0;
}

void	free_map(t_par *mp_p)
{
	size_t	i;

	i = 0;
	if (mp_p->map)
	{
		while ((mp_p->map)[i])
		{
			free((mp_p->map)[i]);
			i++;
		}
		free(mp_p->map);
	}
	free(mp_p);
}

int	print_error(t_par *mp_p)
{
	if (mp_p->f_correct == 'M')
		write(2, "ERROR: map incorrect\n", 21);
	else if (mp_p->f_correct == 'm')
		write(2, "ERROR: malloc error\n", 20);
	else if (mp_p->f_correct == 'i')
		write(2, "ERROR: init error\n", 18);
	else if (mp_p->f_correct == 'I')
		write(2, "ERROR: image error\n", 19);
	else if (mp_p->f_correct == 'w')
		write(2, "ERROR: open window error\n", 25);
	else if (mp_p->f_correct == 'B')
		write(2, "ERROR: map too big\n", 19);
	else
	{
		write(2, "ERROR: unknown error\n code = ", 28);
		write(2, &(mp_p->f_correct), 1);
		write(2, "\n", 1);
	}
	free_map(mp_p);
	exit (1);
}
