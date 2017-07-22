/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:33:08 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/23 00:32:11 by bbeldame         ###   ########.fr       */
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
** Save the board as a **int
** we make an empty gnl to get rid off "    0123456789"
*/

void	parse_board(t_fill *env, char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (env->nb_loop == 1)
	{
		parse_y_x(&BOARD.max_y, &BOARD.max_x, line);
		if (!(BOARD.tab = (int **)malloc(sizeof(int *)
			* BOARD.max_y)))
			return ;
	}
	get_next_line(0, &str);
	while (i < BOARD.max_y)
	{
		get_next_line(0, &str);
		BOARD.tab[i] = parse_board_line(env, str, i);
		if (BOARD.tab[i] == NULL)
			return ;
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
	if (!(PIECE.max_y == 0 && PIECE.max_x == 0))
		free_board_or_piece(&PIECE);
	parse_y_x(&PIECE.max_y, &PIECE.max_x, line);
	if (!(PIECE.tab = (int **)malloc(sizeof(int *) * PIECE.max_y)))
		return ;
	while (i < PIECE.max_y)
	{
		get_next_line(0, &str);
		PIECE.tab[i] = parse_piece_line(env, str);
		if (PIECE.tab[i] == NULL)
			return ;
		i++;
	}
	debug_print_piece(env);
}
