/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:41:41 by cloud             #+#    #+#             */
/*   Updated: 2021/03/07 14:01:36 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long long	digit;

	i = 0;
	digit = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-') ? -1 : 1;
	while (str[i] > 47 && str[i] < 58)
	{
		digit = digit * 10 + (str[i++] - '0');
		if (digit >= 9223372036854775807)
			return ((neg == -1) ? 0 : -1);
	}
	return (digit * neg);
}
