/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:27:33 by abestaev          #+#    #+#             */
/*   Updated: 2022/03/14 18:47:22 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_element(t_game *game)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (game->tab[i])
	{
		j = 0;
		while (game->tab[i][j])
		{
			c = game->tab[i][j];
			if (c != '1' && c != '0' && c != 'P' && c != 'E'
				&& c != 'C' && c != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_len(t_game *game)
{
	int	i;

	i = 0;
	while (game->tab[i])
	{
		if (ft_strlen(game->tab[i]) != game->len)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_wall_top(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->tab[i][j])
	{
		if (game->tab[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	ft_init_data(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tab[i])
	{
		j = 0;
		while (game->tab[i][j])
		{
			if (game->tab[i][j] == 'P')
			{
				game->joueur += 1;
				game->i_pl = i;
				game->j_pl = j;
			}
			else if (game->tab[i][j] == 'E')
				game->exit_count += 1;
			else if (game->tab[i][j] == 'C')
				game->collect += 1;
			j++;
		}
		i++;
	}
	game->height = i;
	return (0);
}

int	ft_check_map(t_game *game)
{
	if (ft_check_element(game))
		ft_send_error(game, "Error\nmap invalide (element inconnu)");
	if (ft_check_len(game))
		ft_send_error(game, "Error\nmap is not a rectangle");
	if (ft_check_wall(game))
		ft_send_error(game, "Error\nmap is not surrounded by walls");
	if (game->collect < 1 || game->exit_count < 1 || game->joueur != 1)
	{
		ft_send_error(game, "Error\nmap invalid (no element C, J or E) or J > 1");
	}
	return (0);
}
