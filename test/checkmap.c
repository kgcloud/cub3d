/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:53:04 by canjugun          #+#    #+#             */
/*   Updated: 2021/03/07 17:26:09 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkmap(t_cub *cub)
{
	int i;
	int	j;

	i = cub->y;
	j = 0;
	while (i--)
	{
		while (cub->map[j++])
		{	
			if (cub->map[j] != '0' && cub->map[j] != '1' && cub->map[j] != '2' && cub->map[j])
			{
				while (cub->map[j] == ' ')
				if (cub->map == 'N' || cub->map == 'O' || cub->map == 'E' || cub->map == 'S')
				{
					cub->px = j;
					cub->py = i;
				}
				else
					return (-1)
			}
		j = 0;
		}
	}
	return (0);
}