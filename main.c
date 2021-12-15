/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_par	*mp_p;
	char	b[1];

	if (argc != 2)
		return (-1 * write(2, "ERR: wrong number of arguments\n", 31));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1 * write(2, "ERR: can't open file for read\n", 30));
	if (read(fd, b, 0) < 0)
		exit (-1 * write(2, "ERR: can't read from file\n", 26));
	mp_p = malloc(sizeof(t_par));
	if (!mp_p)
		exit (-1 * write(2, "ERR: malloc error\n", 18));
	null_mp_p(mp_p);
	parse_map(fd, mp_p);
	if (mp_p->f_correct != 0)
		print_error(mp_p);
	lets_play(mp_p);
	return (0);
}
