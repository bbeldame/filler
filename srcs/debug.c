/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 22:22:08 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/16 19:40:40 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	debug_print_map(t_fill *env)
{
	int		y;
	int		x;

	y = 0;
	ft_putendl_fd("================< MAP_DEBUG >=================", env->fd);
	while (y < env->board.max_y)
	{
		x = 0;
		while (x < env->board.max_x)
		{
			ft_putnbr_fd(env->board.tab[y][x], env->fd);
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
	while (y < env->piece.max_y)
	{
		x = 0;
		while (x < env->piece.max_x)
		{
			ft_putnbr_fd(env->piece.tab[y][x], env->fd);
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
