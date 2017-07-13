/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/13 18:12:20 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main()
{
	int		fd;
	int		ret;
	char	buf[9999 + 1];
	char	*tab;

	fd = open("filler.log", O_WRONLY | O_CREAT);
	ret = read(0, buf, 9999);
	buf[ret] = '\0';
	write(fd, "----------\n", 12);
	write(fd, buf, ret);
	close(fd);
	tab = ft+strdup(buf);
	return (0);
}
