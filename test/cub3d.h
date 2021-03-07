/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:53:15 by cloud             #+#    #+#             */
/*   Updated: 2021/03/07 17:24:52 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define BUFFER_SIZE 100

typedef struct	s_cub
{
	char	**map;
	char	*line;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		fone;
	int		ftwo;
	int		fthree;
	int		cone;
	int		ctwo;
	int		cthree;
	int		rx;
	int		ry;
	int		fd;
    int		ret;
	int		x;
	int		y;
	int		R;
	int		NO;
	int		SO;
	int		WE;
	int		EA;
	int		S;
	int		F;
	int		C;
	int		i;
	int		px;
	int		py;
}				t_cub;

int		get_next_line(int const fd, char **line);
char	*ft_strn(size_t size);
size_t	ft_len(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	initcub(t_cub *cub);
int		recupinfo(t_cub *cub, char **av);
int		ft_atoi(const char *str); 
char	*ft_itoa(int n);
void	printtest(t_cub *cub);
char	**ft_realloc(t_cub *cub);
int		checkmap(t_cub *cub);

#endif
