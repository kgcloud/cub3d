/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloud <cloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:46:32 by cloud             #+#    #+#             */
/*   Updated: 2021/03/11 15:18:32 by cloud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		recupinfo(t_cub *cub, char **av)
{
	if ((cub->fd = open(av[1], O_DIRECTORY)) != -1)
		return (0);
	if ((cub->fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	while (cub->ret)
    {
        cub->ret = get_next_line(cub->fd, &cub->line);
		if (transit(cub) == -1)	
			return (0);
		free(cub->line);
		if (cub->R == 1 && cub->NO == 1 && cub->SO == 1 && cub->WE == 1 
		&& cub->EA == 1 && cub->S == 1 && cub->F == 1 && cub->C == 1)	
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
	return (1);
}

int			main(int ac, char **av)
{
    t_cub *cub;

	if (!(cub = malloc(sizeof(t_cub))))
		return (-1);
	initcub(cub);
	if (!argumenterr(ac,av) ||
	ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), ".cub")
	 || !recupinfo(cub, av)) 
		return (error(cub)); 
//	printtest(cub);
	checkmap(cub);
	printf("%d\n", check_wall(cub));
//	printtest(cub);
}