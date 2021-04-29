/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:53:15 by cloud             #+#    #+#             */
/*   Updated: 2021/04/29 13:27:35 by canjugun         ###   ########.fr       */
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
	char	*f;
	char	*c;
	char	check;
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
int		check_wall(t_cub *cub);
int		recursivemap(t_cub *cub, int x, int y, int space);
char	*ft_strchr(char *str, int c);
void	*ft_memset(void *b, int c, size_t len);
int		transit(t_cub *cub);
int			error(t_cub *cub);
int		argumenterr(int ac, char **av);
int			start(int ac, char **av, t_cub *cub);

#endif
