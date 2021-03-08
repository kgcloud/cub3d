/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloud <cloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:20:35 by canjugun          #+#    #+#             */
/*   Updated: 2021/03/08 17:14:42 by cloud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**ft_realloc(t_cub *cub)
{
	int		i;
	int		j;
	char	**new_ptr;

	i = 0;
	j = cub->y;
	new_ptr = malloc(sizeof(char*) * cub->y);
	while (--j)
	{
		new_ptr[i] = cub->map[i];
		i++;
	}
	new_ptr[i] = ft_strdup(cub->line);
	free(cub->map);
	return (new_ptr);
}