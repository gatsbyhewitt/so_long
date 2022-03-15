/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:25:36 by abestaev          #+#    #+#             */
/*   Updated: 2022/03/14 18:51:12 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_args(argc, argv);
	ft_str_to_tab(&game, argv[1]);
	ft_init(&game);
	ft_check_map(&game);
	if (ft_load_images(&game))
		ft_exit_properly(&game); //, "Error\nerror when loading image"
	ft_draw_map(&game);
	mlx_hook(game.mlx_win, 33, 1L << 17, &ft_escape, &game);
	mlx_loop_hook(game.mlx_win, &ft_no_event, &game);
	mlx_key_hook(game.mlx_win, &ft_key_press, &game);
	mlx_loop(game.mlx);
}
