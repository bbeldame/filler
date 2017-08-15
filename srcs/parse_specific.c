/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specific.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 00:33:29 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/13 17:39:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** We save the position of the enemy with an int
** from 2 to 9, 9 being the last piece positioned, etc
*/

int		get_enemy_number_placement(t_env *env, int y, int x)
{
	if (env->nb_loop == 1 || BOARD.tab[y][x] == 0)
		return (9);
	if (BOARD.tab[y][x] > 2)
		return (BOARD.tab[y][x] - 1);
	return (2);
}

int		parse_char_to_int(t_env *env, char c, int y, int x)
{
	if (c == '*')
		return (1);
	else if (c == 'O' || c == 'o')
		return (env->player == 1) ? 1 : get_enemy_number_placement(env, y, x);
	else if (c == 'X' || c == 'x')
		return (env->player == 2) ? 1 : get_enemy_number_placement(env, y, x);
	return (0);
}

int		*parse_piece_line(t_env *env, char *line)
{
	int		*parsed_line;
	int		i;

	if (!(parsed_line = (int *)malloc(sizeof(int) * PIECE.max_x)))
		return (NULL);
	i = 0;
	while (i < PIECE.max_x)
	{
		parsed_line[i] = parse_char_to_int(env, line[i], 0, 0);
		i++;
	}
	return (parsed_line);
}

int		*parse_board_line(t_env *env, char *line, int index)
{
	int		*parsed_line;
	int		i;

	if (env->nb_loop == 1)
	{
		if (!(parsed_line = (int *)malloc(sizeof(int) * BOARD.max_x)))
			return (NULL);
	}
	else
		parsed_line = BOARD.tab[index];
	i = 0;
	while (i < BOARD.max_x)
	{
		parsed_line[i] = parse_char_to_int(env, line[i + 4], index, i);
		i++;
	}
	return (parsed_line);
}
