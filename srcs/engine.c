/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 22:41:49 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/18 22:54:46 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*

2 options : 
Soit on fait un premier loop qui save toutes les possibilities et ensuite
on calcule la meilleure

Soit on fait un loop qui trouve toutes les possibilités et qui sauvegarde
juste celle avec la meilleure note a chaque fois, comme un ft_max en fait.

La 2e option est plus rapide, en terme de code, en terme de dev aussi, mais
pas sur que ca passe pour gagner tout le temps

*/
