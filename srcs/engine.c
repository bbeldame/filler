/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:31:05 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/13 17:33:33 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		compute_dist(t_env *env, int y, int x)
{
	int		map_x;
	int		map_y;
	int		min_dist_from_enemy;
	int		tmp;

	map_y = 0;
	min_dist_from_enemy = -1;
	while (map_y < BOARD.max_y)
	{
		map_x = 0;
		while (map_x < BOARD.max_x)
		{
			if (BOARD.tab[map_y][map_x] >= 2)
			{
				tmp = ft_abs(map_y - y) + ft_abs(map_x - x);
				tmp -= BOARD.tab[map_y][map_x];
				if (min_dist_from_enemy == -1 || tmp < min_dist_from_enemy)
					min_dist_from_enemy = tmp;
			}
			map_x++;
		}
		map_y++;
	}
	return (min_dist_from_enemy);
}

/*
** y and x are the coordinate inside the board
** we count if the piece touch the board, if it touch
** only once, we can place it, if it touch the enemy,
** it can't be placed, so we add 2 to the touch_counter
*/

static int		piece_can_be_placed(t_env *env, int y, int x)
{
	int			touch_counter;

	PIECE.current_y = 0;
	touch_counter = 0;
	while (PIECE.current_y < PIECE.max_y)
	{
		PIECE.current_x = 0;
		while (PIECE.current_x < PIECE.max_x)
		{
			if (PIECE.tab[PIECE.current_y][PIECE.current_x] &&
				PIECE.current_x + x < BOARD.max_x &&
				PIECE.current_y + y < BOARD.max_y &&
				PIECE.max_x + x <= BOARD.max_x &&
				PIECE.max_y + y <= BOARD.max_y)
			{
				if (BOARD.tab[y + PIECE.current_y][x + PIECE.current_x] == 1)
					touch_counter++;
				if (BOARD.tab[y + PIECE.current_y][x + PIECE.current_x] >= 2)
					touch_counter += 2;
			}
			PIECE.current_x++;
		}
		PIECE.current_y++;
	}
	return (touch_counter == 1) ? 1 : 0;
}

t_choice		find_placement(t_env *env)
{
	int			x;
	int			y;
	t_choice	choice;
	int			tmp_dist;

	choice.x = 0;
	choice.y = 0;
	choice.dist = -1;
	y = -1;
	while (y++ < BOARD.max_y && (x = -1) == -1)
		while (x++ < BOARD.max_x)
			if (piece_can_be_placed(env, y, x))
			{
				tmp_dist = compute_dist(env, y, x);
				if (tmp_dist < choice.dist || choice.dist == -1)
				{
					choice.x = x;
					choice.y = y;
					choice.dist = tmp_dist;
					debug_print_score(env, choice);
				}
			}
	return (choice);
}
