/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 22:19:50 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/19 19:25:33 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Send the coordonate of the piece to the VM
*/


int		trimmer(t_fill *env)
{
	int x;
	int y;
	int min_x;
	int min_y;
	int max_x;
	int max_y;

	y = 0;
	min_x = 0;
	min_y = 0;
	while (y < env->piece.max_y)
	{
		x = 0;
		while (x < env->piece.max_x)
		{
			if (env->piece.tab[y][x])
			{	
				if (min_x < x)
					min_x = x;
				if (min_y < y)
					min_y = y;
			}
			x++;
		}
		y++;
	}
	//ft_putstr_fd("\n", env->fd);
	//ft_putstr_fd("---->octavio", env->fd);
	max_x = env->piece.max_x;
	max_y = env->piece.max_y;
	y = env->piece.max_y - 1;
	while (y >= 0)
	{
		x = env->piece.max_x -1;
		while (x >= 0)
		{
			if (env->piece.tab[y][x])
			{
				if (max_x < x)
					max_x = x;
				if (max_y < y)
					max_y = y;
			}
			x--;
		}
		y--;
	}
	//ft_putstr_fd("\n", env->fd);
	//ft_putstr_fd("---->octavio", env->fd);

	

	return (1);
}

int			piece_isplacable(t_fill *env, int x, int y)
{
	int x1;
	int y1;

	x1 = 0;
	y1 = 0;

	while (y1 < x)
	{
		x1 = 0;
		while (x1 < y)
		{
			x1++;
		}
		y1++;
	}
	x1 = env->piece.max_x;
	return (0);
}

int			filler_isplacable(t_fill *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->board.max_y)
	{
		x = 0;
		while (x < env->board.max_x)
		{
			if (piece_isplacable(env, x, y))
			{
				send_coor(x, y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		send_coor(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void		loop(t_fill *env)
{
	char	*str;

	env->nb_loop += 1;
	debug_new_round(env);
	get_next_line(0, &str);
	parse_board(env, str);
	get_next_line(0, &str);
	parse_piece(env, str);
	//filler_isplacable(env);
	if (trimmer(env))		
		send_coor(8, 2);
	else
		send_coor(8, 2);
}

void		init(t_fill *env)
{
	env->nb_loop = 0;
	env->board.max_x = 0;
	env->board.max_y = 0;
	env->board.tab = NULL;
	env->piece.max_x = 0;
	env->piece.max_y = 0;
	env->trimmed_piece.max_x = 0;
	env->trimmed_piece.max_y = 0;
}

int			main(void)
{
	char	*line;
	t_fill	env;

	env.fd = open("filler.log", O_WRONLY | O_CREAT);
	debug_init(&env);
	init(&env);
	get_next_line(0, &line);
	parse_player(&env, line);
	while (1)
		loop(&env);
	close(env.fd);
	return (0);
}
