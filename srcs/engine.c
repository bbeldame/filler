/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 00:04:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/23 01:21:38 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				compute_score(t_fill *env, int y, int x)
{
	return (1);
}

int				piece_can_be_placed(t_fill *env, board_y, board_x)
{
	int			touch_counter;

	BOARD.current_x = board_x;
	BOARD.current_y = board_y;
	PIECE.current_y = 0;
	touch_counter = 0;
	while (PIECE.current_y < PIECE.max_y)
	{
		PIECE.current_x = 0;
		while (PIECE.current_x < PIECE.max_x)
		{
			if (PIECE.tab[PIECE.current_y][PIECE.current_x] &&
				PIECE.current_x + BOARD.current_x < BOARD.max_x &&
				PIECE.current_y + BOARD.current_y < BOARD.max_y &&
				PIECE.max_x + BOARD.current_x <= BOARD.max_x && // do on trimmed piece
				PIECE.max_y + BOARD.current_y <= BOARD.max_y) // do on trimmed piece
			{
				if (BOARD.tab[BOARD.current_y + PIECE.current_y][BOARD.current_x + PIECE.current_x] == 1)
					touch_counter++;
				if (BOARD.tab[BOARD.current_y + PIECE.current_y][BOARD.current_x + PIECE.current_x] == 2)
					touch_counter += 2;
			}
			PIECE.current_x++;
		}
		PIECE.current_y++;
	}
	return (touch_counter == 1) ? 1 : 0;
}

t_choice		find_placement(t_fill *env)
{
	int			x;
	int			y;
	t_choice	choice;
	int			tmp_score;

	choice.score = 0;
	y = 0;
	while (y < BOARD.max_y)
	{
		x = 0;
		while (x < BOARD.max_x)
		{
			if (piece_can_be_placed(env, y, x))
			{
				tmp_score = compute_score(env, y, x);
				if (tmp_score > choice.score)
				{
					choice.x = x;
					choice.y = y;
					choice.score = tmp_score;
					debug_print_score(env, choice);
				}
			}
			x++;
		}
		y++;
	}
	return (choice);
}
