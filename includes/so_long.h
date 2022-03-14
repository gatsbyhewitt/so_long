/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:26:09 by abestaev          #+#    #+#             */
/*   Updated: 2022/03/14 18:49:34 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../minilibX/mlx.h"
# include "../minilibX/mlx_int.h"

# define SIZE 64

# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;
	char	**tab;
	int		collect;
	int		joueur;
	int		exit_count;
	int		count;
	int		i_pl;
	int		j_pl;
	int		len;
	int		height;
	t_img	*background;
	t_img	*player;
	t_img	*gold;
	t_img	*wall;
	t_img	*exit;
}		t_game;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
}		t_data;

int				ft_check_args(int argc, char **argv);
int				ft_check_map(t_game *game);
int				ft_check_wall(t_game *game);
int				ft_check_wall_top(t_game *game);
int				ft_check_len(t_game *game);
int				ft_check_element(t_game *game);
void			ft_send_error(char *str);

char			*ft_ber_to_str(char *map);
void			ft_str_to_tab(t_game *game, char *map);
void			ft_init(t_game *game);
int				ft_init_data(t_game *game);

int				ft_draw_tile(t_game *game, t_img *img, int x, int y);
void			ft_draw_map(t_game *game);
void			my_mlx_pixel_put(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_get_pixel(t_img *mlx_img, int i, int j);

void			ft_load(t_game *game, t_img **img, char *path);
void			ft_load_images(t_game *game);

int				ft_no_event(t_game *game);
int				ft_escape(t_game *game);
int				ft_key_press(int k, t_game *game);

int				ft_move(int key, t_game *game);
int				ft_move_right(t_game *game);
int				ft_move_left(t_game *game);
int				ft_move_up(t_game *game);
int				ft_move_down(t_game *game);

int				ft_is_move_valid(t_game *game, char tile);
void			ft_print_move(t_game *game);

#endif
