/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:40:49 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 17:01:25 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countnumber(const char *str)
{
	int		c;
	int nb;

	c = 0;
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb + *str++ - '0';
		if (*str >= '0' && *str <= '9')
			nb = nb * 10;
		c++;
	}
	return (c);
}

int		ft_atoi(const char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb + *str++ - '0';
		if (*str >= '0' && *str <= '9')
			nb = nb * 10;
	}
	return (nb * sign);
}
