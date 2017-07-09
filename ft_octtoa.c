/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:01:58 by ddevico           #+#    #+#             */
/*   Updated: 2015/12/07 14:20:55 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_octtoa(uintmax_t n)
{
	char				*p;
	int					size;
	uintmax_t			x;

	x = n;
	size = 0;
	while (x > 7)
	{
		x = x / 8;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			p[size] = 48 + x;
			n = n / 8;
			size--;
		}
	}
	return (p);
}
