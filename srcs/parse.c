/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:33:08 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/14 00:40:03 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	parse_y_x_map(t_fill *env, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (!ft_isdigit(str[i]))
	{
		i++;
	}
	env->map_y = ft_atoi(str + i);
	write(env->fd, "map_y is : ", 12);
	write(env->fd, ft_itoa(env->map_y), 3);
	write(env->fd, "\n", 2);
	tmp = ft_itoa(env->map_y);
	i += ft_strlen(tmp);
	env->map_x = ft_atoi(str + i);

	write(env->fd, "map_x is : ", 12);
	write(env->fd, ft_itoa(env->map_x), 3);
	write(env->fd, "\n", 2);
}

void	parse_y_x_piece(t_fill *env, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (!ft_isdigit(str[i]))
	{
		i++;
	}
	env->piece_y = ft_atoi(str + i);
	write(env->fd, "piece_y is : ", 14);
	write(env->fd, ft_itoa(env->piece_y), 2);
	write(env->fd, "\n", 2);
	tmp = ft_itoa(env->piece_y);
	i += ft_strlen(tmp);
	env->piece_x = ft_atoi(str + i);

	write(env->fd, "piece_x is : ", 14);
	write(env->fd, ft_itoa(env->piece_x), 2);
	write(env->fd, "\n", 2);
}

void	parse_player(t_fill *env, char *str)
{
	if (str[10] == '1')
	{
		env->player = 1;
		env->letter = P1;
	}
	else if (str[10] == '2')
	{
		env->player = 2;
		env->letter = P2;
	}
	else
		err_found("bad player");
}

void	parse_board(t_fill *env, char *line)
{
	char	*str;
	int		i;
	
	write(env->fd, line, ft_strlen(line));
	write(env->fd, "\n", 2);
	i = 0;
	if (env->map_y == 0 || env->map_x == 0)
		parse_y_x_map(env, line);
	else
		free(env->board);
	get_next_line(0, &str); // useless line with "    0123456789.."
	env->board = (char **)malloc(env->map_y);
	while (i < env->map_y)
	{
		get_next_line(0, &str);
		//env->board[i] = parse_board_line(env, str);
		write(env->fd, str, ft_strlen(str));
		write(env->fd, "\n", 2);
		i++;
	}
}

void	parse_piece(t_fill *env, char *line)
{
	char	*str;
	int		i;

	write(env->fd, line, ft_strlen(line));
	write(env->fd, "\n", 2);	
	i = 0;
	parse_y_x_piece(env, line);
	while (i < env->piece_y)
	{
		get_next_line(0, &str);
		write(env->fd, str, ft_strlen(str));
		write(env->fd, "\n", 2);
		i++;
	}
	ft_putstr_fd("PIECE PARSING OVER\n", env->fd);
}