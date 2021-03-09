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