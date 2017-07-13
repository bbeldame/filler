/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/14 00:43:23 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		loop(t_fill *env)
{
	char	*str;

	get_next_line(0, &str);
	write(env->fd, str, ft_strlen(str));
	write(env->fd, "\n", 2);
	parse_board(env, str);
	get_next_line(0, &str);
	parse_piece(env, str);
	ft_putstr("8 2\n");
	ft_putstr_fd("FIRST ROUND OVER\n", env->fd);
}

int			main()
{
	char	*line;
	t_fill	*env;

	env = (t_fill *)semalloc(sizeof(t_fill));
	env->map_y = 0;
	env->map_x = 0;
	env->fd = open("filler.log", O_WRONLY | O_CREAT);
	get_next_line(0, &line);
	parse_player(env, line);
	write(env->fd, "-----\n", 7);
	if (env->player == 1)
		ft_putstr_fd("IM THE 1ST PLAYER\n", env->fd);
	else if (env->player == 2)
		write(env->fd, "fuck\n", 5);
	while (1)
	{
		loop(env);
	}
	close(env->fd);
	return (0);
}
