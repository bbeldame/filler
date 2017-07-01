/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 17:34:17 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/01 18:02:59 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualiser.h"

int		main(void)
{
	char	*str;
	int		white_liners;

	while (get_next_line(0, &str))
	{
		if (str[0] == '0')
		{
			if (str[1] == '0' && str[2] == '0')
			{
				white_liners = 100;
				while (white_liners-- > 0)
					ft_putchar('\n');
			}
			ft_putstr(str);
			ft_putchar('\n');
		}
	}
	return (1);
}