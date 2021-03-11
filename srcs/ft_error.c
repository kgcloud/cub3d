/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloud <cloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:13:13 by cloud             #+#    #+#             */
/*   Updated: 2021/03/11 14:14:14 by cloud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		argumenterr(int ac, char **av)
{
	if (ac == 2)
		return (1);
	else if (ac == 3)
		if (ft_strcmp(av[2], "--save") == 0)
			return (1);	
	return(0);
}

int			error(t_cub *cub)
{
	printf("Error\nretry again");
	if (cub->line)
		free(cub->line);
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	if (cub->s)
		free(cub->s);
	if (cub->f)
		free(cub->f);
	if (cub->c)
		free(cub->c);
	if (cub->map)
	{	
		cub->i = -1;
		while(cub->map[++cub->i])
			free(cub->map[cub->i]);
		free(cub->map);
	}
	free(cub);
	return (0);
}