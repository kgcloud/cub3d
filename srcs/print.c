/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:49:18 by canjugun          #+#    #+#             */
/*   Updated: 2021/03/10 14:49:19 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printtest(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	/*printf("cub->no %s\n", cub->no);
	printf("cub->so %s\n", cub->so);
	printf("cub->we %s\n", cub->we);
	printf("cub->ea %s\n", cub->ea);
	printf("cub->s %s\n", cub->s);
	printf("rx - > %d, ry -> %d\n", cub->rx, cub->ry);
	printf("x - > %d, y -> %d\n\n", cub->x, cub->y);*/
	while (i < cub->y)
	{
		printf("%s\n", cub->map[i]);
		i++;
	}
}