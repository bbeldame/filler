/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:33:08 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/13 17:23:27 by bbeldame         ###   ########.fr       */
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

void	trim_piece(t_env *env)
{
	t_cleaner	cleaner;
	int			y;
	int			x;

	cleaner = get_piece_cleaner(env);
	if (!(TRIM.tab = (int **)malloc(sizeof(int *) * TRIM.max_y)))
		return ;
	y = cleaner.min_y;
	while (y <= cleaner.max_y)
	{
		x = cleaner.min_x;
		TRIM.tab[y - cleaner.min_y] = (int *)malloc(sizeof(int) * TRIM.max_x);
		while (x <= cleaner.max_x)
		{
			TRIM.tab[y - cleaner.min_y][x - cleaner.min_x] = 0;
			if (PIECE.tab[y][x])
			{
				TRIM.tab[y - cleaner.min_y][x - cleaner.min_x] = 1;
			}
			x++;
		}
		y++;
	}
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

void	parse_player(t_env *env, char *str)
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

void	parse_board(t_env *env, char *line)
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

void	parse_piece(t_env *env, char *line)
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
	trim_piece(env);
	debug_print_piece(env);
}
