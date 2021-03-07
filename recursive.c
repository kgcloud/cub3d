/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:14:29 by canjugun          #+#    #+#             */
/*   Updated: 2021/03/07 16:42:07 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	printtab(char tab[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		while (tab[i][j])
		{
			printf("%c",tab[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

int		recursive(char tab[9][9], int x, int y)
{
	if (x < 0 || y < 0 || x > 7 || y > 7)
		return (-1);
	if (tab[x][y] != '0')
	{
		if (tab[x][y] != '1' && tab[x][y] != '9')
			return (-1);
		else
			return (0);
	}
	tab[x][y] = '9';
	if (recursive(tab, x + 1, y) == - 1)
		return (-1);
	if (recursive(tab, x, y - 1) == - 1)
		return (-1);
	if (recursive(tab, x - 1, y) == - 1)
		return (-1);
	if (recursive(tab, x, y + 1) == - 1)
		return (-1);
	if (recursive(tab, x + 1, y + 1) == - 1)
		return (-1);
	if (recursive(tab, x - 1, y - 1) == - 1)
		return (-1);
	if (recursive(tab, x + 1, y - 1) == - 1)
		return (-1);
	if (recursive(tab, x - 1, y + 1) == - 1)
		return (-1);
	return (0);
}

int		recursivetab(char tab[9][9])
{
	int x = 2;
	int y = 2;
	
	printf("%d\n", recursive(tab,x,y));
	return (0);
}

int			main()
{
	char tab[9][9] = { 
						"11111111",
						"10001001",
						"10001001",
						"10001001",
						"10001",
						"11111111",
						"10000001",
						"11011111", 
								}	;
	
	printtab(tab);
	recursivetab(tab);
	printtab(tab);
}