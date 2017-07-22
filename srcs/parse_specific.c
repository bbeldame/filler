/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specific.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 00:33:29 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/23 00:32:08 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		parse_char_to_int(t_fill *env, char c)
{
	if (c == '*')
		return (1);
	else if (c == 'O' || c == 'o')
		return (env->player == 1) ? 1 : 2;
	else if (c == 'X' || c == 'x')
		return (env->player == 2) ? 1 : 2;
	return (0);
}

int		*parse_piece_line(t_fill *env, char *line)
{
	int		*parsed_line;
	int		i;

	if (!(parsed_line = (int *)malloc(sizeof(int) * PIECE.max_x)))
		return (NULL);
	i = 0;
	while (i < PIECE.max_x)
	{
		parsed_line[i] = parse_char_to_int(env, line[i]);
		i++;
	}
	return (parsed_line);
}

int		*parse_board_line(t_fill *env, char *line, int index)
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
		parsed_line[i] = parse_char_to_int(env, line[i + 4]);
		i++;
	}
	return (parsed_line);
}
