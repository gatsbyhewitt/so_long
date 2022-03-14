/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abestaev <abestaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:28:13 by abestaev          #+#    #+#             */
/*   Updated: 2022/03/14 17:44:55 by abestaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_move_valid(t_game *game, char tile)
{
	if (tile == '1')
		return (1);
	if (tile == 'C')
		game->collect -= 1;
	if (tile == 'E' && game->collect == 0)
		ft_escape(game);
	if (tile == 'E' && game->collect > 0)
		return (1);
	game->count++;
	return (0);
}

void	ft_print_move(t_game *game)
{
	ft_putstr_fd(" move count : ", 1);
	ft_putnbr_fd(game->count, 1);
	ft_putstr_fd(" \r", 1);
}
