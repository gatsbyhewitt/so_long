/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:28:03 by abestaev          #+#    #+#             */
/*   Updated: 2022/03/14 17:46:21 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_escape(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->mlx_img);
	mlx_destroy_image(game->mlx, game->background);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->gold);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->mlx_win);
	i = 0;
	while (i < game->height)
		free(game->tab[i++]);
	free(game->tab);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	ft_exit_properly(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->mlx_img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	i = 0;
	while (i < game->height)
		free(game->tab[i++]);
	free(game->tab);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	ft_no_event(t_game *game)
{
	ft_putstr_fd("move count: ", 1);
	ft_putnbr_fd(game->count, 1);
	ft_putstr_fd(" \r", 1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
	return (1);
}

int	ft_key_press(int key, t_game *game)
{
	if (key == ESC)
		return (ft_escape(game));
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		return (ft_move(key, game));
	return (1);
}
