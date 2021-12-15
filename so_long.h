/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:48 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:50 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define W_MAX 1600
# define H_MAX 900
# define BUF_SIZE 4096
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_g_data
{
	void	*back;
	void	*adr_back;
	void	*wall;
	void	*adr_wall;
	void	*pl_w;
	void	*pl_a;
	void	*pl_s;
	void	*pl_d;
	void	*adr_plw;
	void	*adr_pla;
	void	*adr_pls;
	void	*adr_pld;
	char	f_view;
	char	f_move;
	int		pl_x;
	int		pl_y;
	int		pl_speed;
	char	f_winner;
	void	*coll;
	void	*adr_coll;
	void	*ex;
	void	*ex2;
	void	*ex3;
	void	*adr_ex;
	int		bpp_small;
	int		ll_small;
	int		e_small;
	int		w_s;
	int		h_s;
	char	flg_big_map;
	void	*wnr;
	void	*adr_wnr;
	void	*img;
	void	*adr_img;
	int		bpp_img;
	int		ll_img;
	int		e_img;
}	t_data;

typedef struct s_map_parameters
{
	char	**map;
	char	f_correct;
	size_t	lines;
	size_t	width;
	size_t	tmp_width;
	int		i_border;
	int		j_border;
	char	f_e;
	char	f_p;
	size_t	f_c;
	t_data	*gd;
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	size_t	pl_x;
	size_t	pl_y;
	size_t	mv_count;
	size_t	tmp_mv_count;
}	t_par;

void	null_mp_p(t_par *mp_p);
void	parse_map(int fd, t_par *mp_p);
void	free_map(t_par *mp_p);
char	*write_buf_to_s(char *buf, size_t res_read, char *s, t_par *mp_p);
int		print_error(t_par *mp_p);
void	ft_split(char *s, t_par *mp_p);
void	lets_play(t_par *mp_p);
void	quit_game(t_par *mp_p, char flg);
void	prepare(t_par *m);
char	norm_game(t_par *m);
void	count_offset_w(t_par *m, t_data *gd);
void	count_offset_h(t_par *m, t_data *gd);
int		count_borders(t_par *m, t_data *gd, char flg, char flg_first);
void	open_all_images(t_par *m, t_data *gd);
void	get_adr_images(t_data *gd);
int		draw_frame(t_par *m);
void	draw_image(t_par *m, t_data *gd, char flg_first);
void	put_small(int i, int j, t_data *gd, unsigned int *adr);
void	put_player(t_par *m, t_data *gd);
void	game_play(t_par *m, t_data *gd);
int		check_wall(char c, t_par *m, t_data *gd, char w);
int		check_w(t_par *m, t_data *gd, char w);
int		check_s(t_par *m, t_data *gd, char w);
int		check_a(t_par *m, t_data *gd, char w);
int		check_d(t_par *m, t_data *gd, char w);
void	check_collect(t_par *m, t_data *gd);
void	check_exit(t_par *m, t_data *gd);
int		press(int key, t_par *m);
int		release(int key, t_par *m);
int		red_cross(t_par *m);
void	destroy_images(t_par *m);
#endif
