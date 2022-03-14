/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:28:21 by abestaev          #+#    #+#             */
/*   Updated: 2022/03/14 17:45:47 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *mlx_img, int x, int y, int color)
{
	char	*dst;

	dst = mlx_img->data + (y * mlx_img->size_line + x * (mlx_img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

//fonction  pour loads les textures
void	ft_load(t_game *game, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	(**img).width = width;
	(**img).height = height;
}

void	ft_load_images(t_game *game)
{
	ft_load(game, &game->background, "images/background.xpm");
	ft_load(game, &game->exit, "images/exit.xpm");
	ft_load(game, &game->gold, "images/gold.xpm");
	ft_load(game, &game->player, "images/player.xpm");
	ft_load(game, &game->wall, "images/wall.xpm");
}
