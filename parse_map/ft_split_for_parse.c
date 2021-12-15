/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_for_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:47 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:35:49 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	check_correct(char *c, size_t i, t_par *mp_p)
{
	if ((mp_p->lines == 0 || (i - (mp_p->lines * (mp_p->width + 1))) == 0) && \
	*c != '1')
		return (0);
	if (*c == 'P')
	{
		mp_p->pl_x = i - (mp_p->lines * (mp_p->width + 1));
		mp_p->pl_y = mp_p->lines;
		*c = '0';
		(mp_p->f_p)++;
	}
	else if (*c == 'E')
		(mp_p->f_e) = 1;
	else if (*c == 'C')
		(mp_p->f_c)++;
	else if (*c != '0' && *c != '1')
		return (0);
	if ((mp_p->f_p) > 1)
		return (0);
	return (1);
}

static void	count_words(char *s, t_par *mp_p)
{
	size_t	i;
	char	c;

	c = '\n';
	i = 0;
	while (s[i] && !(mp_p->f_correct))
	{
		if (s[i] == c)
			mp_p->f_correct = 'M';
		while (s[i] != c && s[i])
		{
			if (check_correct(&(s[i]), i, mp_p) == 0)
				mp_p->f_correct = 'M';
			i++;
		}
		mp_p->tmp_width = i - (mp_p->lines * (mp_p->width + 1));
		if (mp_p->lines == 0)
			mp_p->width = mp_p->tmp_width;
		(mp_p->lines)++;
		if (mp_p->width != mp_p->tmp_width || !(mp_p->width))
			mp_p->f_correct = 'M';
		if (s[i] != 0)
			i++;
	}
}

static size_t	str_mod_dup(char *s, t_par *mp_p, size_t i)
{
	size_t	j;

	j = mp_p->width;
	(mp_p->map)[i] = (char *)malloc(sizeof(char) * (j + 1));
	if (!((mp_p->map)[i]))
	{
		mp_p->f_correct = 'm';
		return (0);
	}
	(mp_p->map)[i][j] = 0;
	while (j-- > 0)
	{
		(mp_p->map)[i][j] = s[j];
		if (s[j] != '1' && (j == mp_p->width - 1 || i == mp_p->lines - 1))
			mp_p->f_correct = 'M';
	}
	return (mp_p->width);
}

void	ft_split(char *s, t_par *mp_p)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	count_words(s, mp_p);
	if (!(mp_p->f_p) || !(mp_p->f_e) || !(mp_p->f_c))
		mp_p->f_correct = 'M';
	if (mp_p->f_correct != 0)
		return ;
	mp_p->map = (char **)malloc(sizeof(char *) * (mp_p->lines + 1));
	if (NULL == mp_p->map)
		return ;
	while (s[j] && !(mp_p->f_correct))
	{
		j += str_mod_dup((s + j), mp_p, i++);
		if (s[j])
			j++;
	}
	(mp_p->map)[i] = NULL;
	if ((i < mp_p->lines || mp_p->lines == 0) && mp_p->f_correct == 0)
		mp_p->f_correct = 'M';
	if ((mp_p->lines > 511 || mp_p->width == 511) && mp_p->f_correct == 0)
		mp_p->f_correct = 'B';
}
