/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specific.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 00:33:29 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/14 00:39:22 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	*parse_board_line(t_fill *env, char *line)
{
	char	*parsed_line;
	int		i;
	
	parsed_line = (char *)malloc(sizeof(char) * env->map_x);
	i = 0;
	while (i < env->map_x)
	{
		parsed_line[i] = line[i + 4];
		i++;
	}
	parsed_line[i] = '\0';
	return parsed_line;
}