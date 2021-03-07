#include "cub3d.h"

void	printtest(t_cub *cub)
{
	printf("cub->no %s\n", cub->no);
	printf("cub->so %s\n", cub->so);
	printf("cub->we %s\n", cub->we);
	printf("cub->ea %s\n", cub->ea);
	printf("cub->s %s\n", cub->s);
	printf("rx - > %d, ry -> %d\n", cub->rx, cub->ry);
	printf("x - > %d, y -> %d\n", cub->x, cub->y);
}