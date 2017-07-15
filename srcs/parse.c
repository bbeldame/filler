/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:33:08 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/16 00:35:39 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Trim the piece, from 00
**						11
**						00
** it will return : 11
** Basically it deletes every useless lines and columns from the piece
*/

int		**trim_piece(t_fill *env)
{
	return (env->fd); //todo
}

/*
** Save the max y and max x of the map or piece
*/

void	parse_y_x(int *max_y, int *max_x, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (!ft_isdigit(str[i]))
	{
		i++;
	}
	*max_y = ft_atoi(str + i);
	tmp = ft_itoa(*max_y);
	i += ft_strlen(tmp);
	free(tmp);
	*max_x = ft_atoi(str + i);
}

/*
** In the first line of the firs call
** get the player number, one or two
*/

void	parse_player(t_fill *env, char *str)
{
	if (str[10] == '1')
		env->player = 1;
	else if (str[10] == '2')
		env->player = 2;
	else
		err_found("bad player");
}

/*
** Save the board as a **int, free the previous board on each call
*/

void	parse_board(t_fill *env, char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (env->board.max_y == 0 || env->board.max_x == 0)
		parse_y_x(&env->board.max_y, &env->board.max_x, line);
	else
		free(env->board.tab);
	get_next_line(0, &str); // useless line with "    0123456789.."
	env->board.tab = (int **)malloc(sizeof(int *) * env->board.max_y);
	while (i < env->board.max_y)
	{
		get_next_line(0, &str);
		env->board.tab[i] = parse_board_line(env, str);
		i++;
	}
	debug_print_map(env);
}

/*
** Save the piece as a **int, free the previous piece on each call
*/

void	parse_piece(t_fill *env, char *line)
{
	char	*str;
	int		i;

	i = 0;
	parse_y_x(&env->piece.max_y, &env->piece.max_x, line);
	env->piece.tab = (int **)malloc(sizeof(int *) * env->piece.max_y);
	while (i < env->piece.max_y)
	{
		get_next_line(0, &str);
		env->piece.tab[i] = parse_piece_line(env, str);
		i++;
	}
	debug_print_piece(env);
}