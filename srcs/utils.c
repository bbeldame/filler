/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/15 19:45:21 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_cleaner	get_piece_cleaner(t_env *env)
{
	int			x;
	int			y;
	t_cleaner	cleaner;

	y = 0;
	cleaner.min_x = PIECE.max_x;
	cleaner.min_y = PIECE.max_y;
	cleaner.max_x = 0;
	cleaner.max_y = 0;
	while (y < PIECE.max_y)
	{
		x = -1;
		while (++x < PIECE.max_x)
			if (PIECE.tab[y][x])
			{
				cleaner.min_x = (x <= cleaner.min_x) ? x : cleaner.min_x;
				cleaner.min_y = (y <= cleaner.min_y) ? y : cleaner.min_y;
				cleaner.max_x = (x >= cleaner.max_x) ? x : cleaner.max_x;
				cleaner.max_y = (y >= cleaner.max_y) ? y : cleaner.max_y;
			}
		y++;
	}
	TRIM.max_x = cleaner.max_x - cleaner.min_x + 1;
	TRIM.max_y = cleaner.max_y - cleaner.min_y + 1;
	return (cleaner);
}

void		free_board_or_piece(t_mop *mop)
{
	int i;

	i = 0;
	while (i < mop->max_y)
		free(mop->tab[i++]);
	free(mop->tab);
}
