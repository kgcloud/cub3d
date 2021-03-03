/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:14:29 by canjugun          #+#    #+#             */
/*   Updated: 2021/03/03 16:27:51 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	printtab(int tab[8][8])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		while (j < 8)
		{
			printf("%d",tab[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

int		recursive(int tab[8][8], int x, int y)
{
	if (x < 1 || y < 1 || x > 7 || y > 7 || tab[x][y] != 0)
	{
		return (-1);
	}
	if (tab[x][y] == 0 && (tab[x - 1][y] == ' ' || tab[x + 1][y] == ' ' ||tab[x][y - 1] == ' ' || tab[x][y + 1] == ' ' || tab[x + 1][y + 1] == ' ' || tab[x - 1][y - 1] == ' ' || tab[x + 1][y - 1] == ' ' || tab[x - 1][y + 1] == ' '))
		return (-1);
	tab[x][y] = 9;
	recursive(tab, x - 1, y);
	recursive(tab, x + 1, y);
	recursive(tab, x, y - 1);
	recursive(tab, x, y + 1);
	recursive(tab, x + 1, y + 1);
	recursive(tab, x - 1, y - 1);
	recursive(tab, x + 1, y - 1);
	recursive(tab, x - 1, y + 1);
	return (0);
}

int		recursivetab(int tab[8][8])
{
	int x = 4;
	int y = 3;
	
	printf("%d\n", recursive(tab,x,y));
	return (0);
}

int			main()
{
	int tab[8][8] = {
					{1,1,1,1,1,1,1,1},
					{1,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,1},
					{1,1,1,1,1,1,1,1}
					};

	printtab(tab);
	recursivetab(tab);
	printtab(tab);
}