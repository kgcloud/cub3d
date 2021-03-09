/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloud <cloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:46:32 by cloud             #+#    #+#             */
/*   Updated: 2021/03/09 18:36:38 by cloud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		transit(t_cub *cub)
{
	if (cub->line[0] == 'R' && cub->line[1] == ' ')
	{
		int space;

		space = 0;
		if (cub->R != 0)
			return (-1);
		cub->R = 1;
		cub->i = 0;
		while (cub->line[++cub->i] == ' ')
			;
		cub->rx = cub->i;
		while (cub->line[cub->i])
		{
			if (!(cub->line[cub->i] >= '0' && cub->line[cub->i] <= '9'))
			{
				if (cub->line[cub->i] != ' ' && space == 1)
					return (-1);
				while (cub->line[cub->i] == ' ' && space == 0)
					cub->i++;
				space = 1;
				cub->ry = cub->i - 1;
			}
			cub->i++;
		}
		cub->rx = ft_atoi(cub->line + cub->rx);
		cub->ry = ft_atoi(cub->line + cub->ry);
		if (cub->rx > 2147483647 || cub->rx <= 0 || 
			cub->ry > 2147483647 || cub->ry <= 0)
			return (-1);
	}
	else if (cub->line[0] == 'N' && cub->line[1] == 'O' && cub->line[2] == ' ')
	{
		if (cub->NO != 0)
			return (-1);
		cub->NO = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->no = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'S' && cub->line[1] == 'O' && cub->line[2] == ' ')
	{
		if (cub->SO != 0)
			return (-1);
		cub->SO = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->so = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'W' && cub->line[1] == 'E' && cub->line[2] == ' ')
	{
		if (cub->WE != 0)
			return (-1);
		cub->WE = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->we = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'E' && cub->line[1] == 'A' && cub->line[2] == ' ')
	{
		if (cub->EA != 0)
			return (-1);
		cub->EA = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->ea = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'S' && cub->line[1] == ' ')
	{
		if (cub->S != 0)
			return (-1);
		cub->S = 1;
		cub->i = 1;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->s = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'F' && cub->line[1] == ' ')
	{
		int	space;

		space = 0;
		if (cub->F != 0)
			return (-1);
		cub->F = 1;
		cub->i = 0;
		while (cub->line[++cub->i] == ' ')
			;
		cub->fone = cub->i;
		while (cub->line[cub->i])
		{
			if (!(cub->line[cub->i] >= '0' && cub->line[cub->i] <= '9'))
			{
				if (cub->line[cub->i] == ',')
					cub->i++;
				if (cub->line[cub->i] != ' ' && space == 2)
					return (-1);
				while (cub->line[cub->i] == ' ' && space != 2)
					cub->i++;
				space++;
				if (space == 1)
					cub->ftwo = (cub->i - 1);
				else
					cub->fthree = (cub->i - 1);
			}
			cub->i++;
		}
		
	}
	else if (cub->line[0] == 'C' && cub->line[1] == ' ')
	{
		if (cub->C != 0)
			return (-1);
		cub->C = 1;
	}
	//else if (cub->line[0] != '\n')
	//	return (-1);
	return (0);
}

int		recupinfo(t_cub *cub, char **av)
{
	if ((cub->fd = open(av[1], O_DIRECTORY)) != -1)
		return (-1);
	if ((cub->fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	//cub->map = malloc(sizeof(char*) * 1);
	//cub->map[0] = malloc(sizeof(char) * 1);
	while (cub->ret)
    {
        cub->ret = get_next_line(cub->fd, &cub->line);
		if (transit(cub) == -1)
			return (-1);
		free(cub->line);
		if (cub->R == 1 && cub->NO == 1 && cub->SO == 1 && cub->WE == 1 && cub->EA == 1 && cub->S == 1 && cub->F == 1 && cub->C == 1)
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
	return (0);
}

int		argumenterr(int ac, char **av)
{
	if (ac != 2)
	{	
		if (ac < 2)
		{
			printf("Error\npas assez d'arguments");
			return (0);
		}
		if (ac > 3)
		{
			printf("Error\nil y a trop d'arguments");
			return (0);
		}
		if (ac == 3)
		{
			if (ft_strcmp(av[2], "--save") != 0)
			{
				printf("Error\n2e arg != --save");
				return (0);
			}
		}
	}
	return(1);
}

int			main(int ac, char **av)
{
    t_cub *cub;

	if (argumenterr(ac,av) == 0)
		return (0);
	if (ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), ".cub") != 0)
	{
		printf("Error\n!= .cub");
		return (0);
	}
	if (!(cub = malloc(sizeof(t_cub))))
		return (-1);
	initcub(cub);
	if (recupinfo(cub, av) == -1)
	{
		printf("Error\nprob dans recup");
		return (0);
	}
	if (checkmap(cub) == -1)
	{
		printf("Error\nprob dans la map");
		return (0);
	}
	printtest(cub);
	printf("avant : px - > %d, py -> %d\n", cub->px, cub->py);
	cub->open = 0;
	if (check_wall(cub))
	{
		printf("Error\nrecursiv");
		//return (0);
	}
	
	printf("apres : px - > %d, py -> %d\n", cub->px, cub->py);
	printtest(cub);
}