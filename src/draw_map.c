/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:27:40 by abestaev          #+#    #+#             */
/*   Updated: 2022/03/14 18:45:45 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//fonction qui affiche une seul case
int	ft_draw_tile(t_game *game, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			color = mlx_get_pixel(img, i, j);
			my_mlx_pixel_put(game->mlx_img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->tab[i])
	{
		j = 0;
		while (game->tab[i][j])
		{
			if (game->tab[i][j] == '1')
				ft_draw_tile(game, game->wall, j * SIZE, i * SIZE);
			if (game->tab[i][j] == '0')
				ft_draw_tile(game, game->background, j * SIZE, i * SIZE);
			if (game->tab[i][j] == 'C')
				ft_draw_tile(game, game->gold, j * SIZE, i * SIZE);
			if (game->tab[i][j] == 'P')
				ft_draw_tile(game, game->player, j * SIZE, i * SIZE);
			if (game->tab[i][j] == 'E')
				ft_draw_tile(game, game->exit, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
}
