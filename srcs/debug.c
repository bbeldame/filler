/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 22:22:08 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/23 00:55:33 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	debug_print_map(t_fill *env)
{
	int		y;
	int		x;

	y = 0;
	ft_putendl_fd("================< MAP_DEBUG >=================", env->fd);
	while (y < BOARD.max_y)
	{
		x = 0;
		while (x < BOARD.max_x)
		{
			ft_putnbr_fd(BOARD.tab[y][x], env->fd);
			x++;
		}
		ft_putchar_fd('\n', env->fd);
		y++;
	}
	ft_putendl_fd("===============<\\ MAP_DEBUG />================", env->fd);
}

void	debug_print_piece(t_fill *env)
{
	int		y;
	int		x;

	y = 0;
	ft_putendl_fd("===============< PIECE_DEBUG >================", env->fd);
	while (y < PIECE.max_y)
	{
		x = 0;
		while (x < PIECE.max_x)
		{
			ft_putnbr_fd(PIECE.tab[y][x], env->fd);
			x++;
		}
		ft_putchar_fd('\n', env->fd);
		y++;
	}
	ft_putendl_fd("==============<\\ PIECE_DEBUG />===============", env->fd);
}

void	debug_new_round(t_fill *env)
{
	ft_putendl_fd("\n", env->fd);
	ft_putendl_fd("==============================================", env->fd);
	ft_putendl_fd("================< NEW ROUND >=================", env->fd);
	ft_putendl_fd("==============================================", env->fd);
}

void	debug_init(t_fill *env)
{
	ft_putendl_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", env->fd);
	ft_putendl_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", env->fd);
	ft_putendl_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", env->fd);
	ft_putendl_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", env->fd);
	ft_putendl_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", env->fd);
	ft_putendl_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", env->fd);
	ft_putendl_fd("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", env->fd);
}

void	debug_print_score(t_fill *env, t_choice choice)
{
	ft_putendl_fd("===============< CHOICE_DEBUG >================", env->fd);
	ft_putstr_fd("x = ", env->fd);
	ft_putnbr_fd(choice.x, env->fd);
	ft_putstr_fd("\ny = ", env->fd);
	ft_putnbr_fd(choice.y, env->fd);
	ft_putstr_fd("\nscore = ", env->fd);
	ft_putnbr_fd(choice.score, env->fd);
	ft_putstr_fd("\n", env->fd);
	ft_putendl_fd("==============<\\ CHOICE_DEBUG />===============", env->fd);
}
