/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:46:32 by cloud             #+#    #+#             */
/*   Updated: 2021/03/29 15:43:24 by canjugun         ###   ########.fr       */
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

int			start(int ac, char **av)
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
	return (0);
}

#include <mlx.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "!CUB3D");
    img.img = mlx_new_image(mlx, 920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}