/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:01:58 by ddevico           #+#    #+#             */
/*   Updated: 2015/12/07 14:20:55 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_utoa_long(uintmax_t nb)
{
	char				*str;
	int					size;
	uintmax_t			x;

	x = nb;
	size = 0;
	while (x /= 10)
		size++;
	if ((str = (char *)malloc(sizeof(str) * (size + 1))) == NULL)
		return (NULL);
	str[size + 1] = '\0';
	while (size >= 0)
	{
		x = nb % 10;
		str[size] = 48 + x;
		nb = nb / 10;
		size--;
	}
	return (str);
}

char					*ft_utoa(unsigned int nb)
{
	char				*str;
	int					size;
	unsigned int	x;

	x = nb;
	size = 0;
	while (x /= 10)
		size++;
	if ((str = (char *)malloc(sizeof(str) * (size + 1))) == NULL)
		return (NULL);
	str[size + 1] = '\0';
	while (size >= 0)
	{
		x = nb % 10;
		str[size] = 48 + x;
		nb = nb / 10;
		size--;
	}
	return (str);
}
