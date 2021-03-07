#include "cub3d.h"

void	printtest(t_cub *cub)
{
	int i;
	int j;

	i = cub->y;
	j = 0;
	printf("cub->no %s\n", cub->no);
	printf("cub->so %s\n", cub->so);
	printf("cub->we %s\n", cub->we);
	printf("cub->ea %s\n", cub->ea);
	printf("cub->s %s\n", cub->s);
	printf("rx - > %d, ry -> %d\n", cub->rx, cub->ry);
	printf("x - > %d, y -> %d\n\n", cub->x, cub->y);
	while (i--)
	{
		printf("%s\n", cub->map[j]);
		j++;
	}
}