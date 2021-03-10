/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:46:32 by cloud             #+#    #+#             */
/*   Updated: 2021/03/10 15:29:24 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		recupinfo(t_cub *cub, char **av)
{
	if ((cub->fd = open(av[1], O_DIRECTORY)) != -1)
		return (-1);
	if ((cub->fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	while (cub->ret)
    {
        cub->ret = get_next_line(cub->fd, &cub->line);
		if (transit(cub) == -1)	
			return (-1);
		free(cub->line);
		if (cub->R == 1 && cub->NO == 1 && cub->SO == 1 && cub->WE == 1 
		&& cub->EA == 1 && cub->S == 1 && cub->F == 1 && cub->C == 1)
		{	
			while(cub->ret)
			{
				cub->ret = get_next_line(cub->fd, &cub->line);
				if (ft_strlen(cub->line) > cub->x)
					cub->x = ft_strlen(cub->line);
				cub->y++;
				cub->map = ft_realloc(cub);
				free(cub->line);
			}
		}
    }
	return (0);
}

int		argumenterr(int ac, char **av)
{
	if (ac != 2)
		if (ft_strcmp(av[2], "--save") != 0)
			return (0);	
	return(1);
}

int			error(t_cub *cub)
{
	printf("Error\nretry again");
	free(cub);
	return (0);
}

int			main(int ac, char **av)
{
    t_cub *cub;

	if (!(cub = malloc(sizeof(t_cub))))
		return (-1);
	initcub(cub);
	if ((argumenterr(ac,av) == 0) ||
	(ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), ".cub") != 0)
	 || (recupinfo(cub, av) == -1)) 
		return (error(cub)); 
	printtest(cub);
	checkmap(cub);
	check_wall(cub);
	printtest(cub);
}