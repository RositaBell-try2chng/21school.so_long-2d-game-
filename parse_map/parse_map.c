/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:56 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:35:58 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parse_map(int fd, t_par *mp_p)
{
	char	*s;
	char	buf[BUF_SIZE + 1];
	ssize_t	res_read;

	res_read = BUF_SIZE;
	s = NULL;
	while (res_read == BUF_SIZE)
	{
		res_read = read(fd, buf, BUF_SIZE);
		if (res_read > 0)
		{
			s = write_buf_to_s(buf, res_read, s, mp_p);
			if (!s)
				return ;
		}
	}
	close(fd);
	if (!s)
		mp_p->f_correct = 'M';
	else
		ft_split(s, mp_p);
	if (!(mp_p->map) && !(mp_p->f_correct))
		mp_p->f_correct = 'm';
	free(s);
}

char	*take_more_mem(size_t *size, size_t res_read, char *s, t_par *mp_p)
{
	char	*new;
	size_t	i;

	if (*size < res_read && res_read < BUF_SIZE)
		(*size) += res_read + 1;
	else if (*size < res_read)
		(*size) += (res_read * 2);
	else
		(*size) *= 2;
	i = -1;
	new = malloc(sizeof(char) * (*size + 1));
	if (s && new)
	{
		while (s[++i])
			new[i] = s[i];
		new[i] = 0;
	}
	if (!new)
		mp_p->f_correct = 'm';
	return (new);
}

char	*write_buf_to_s(char *buf, size_t res_read, char *s, t_par *mp_p)
{
	static size_t	size;
	char			*new;
	static size_t	i;
	size_t			j;

	j = -1;
	if (i + res_read < size)
	{
		while (++j < res_read)
			s[i + j] = buf[j];
		s[i + j] = 0;
		i += j;
		return (s);
	}
	new = take_more_mem(&size, res_read, s, mp_p);
	free(s);
	if (!new)
		return (NULL);
	while (++j < res_read)
		new[i + j] = buf[j];
	new[i + j] = 0;
	i += j;
	return (new);
}
