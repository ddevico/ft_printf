/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:01:58 by ddevico           #+#    #+#             */
/*   Updated: 2015/12/07 14:20:55 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_hexa(int x)
{
	if (x >= 0 && x <= 9)
		return (48 + x);
	else if (x >= 10 && x <= 15)
	{
		x = x - 10;
		return (97 + x);
	}
	return (0);
}

char			*ft_hexatoalong(uintmax_t n)
{
	char			*str;
	int				size;
	uintmax_t		tmpn;

	tmpn = n;
	size = 0;
	/*if (n == 4294967296 && (flag->j || flag->l || flag->ll) != 1)
		return ("0");*/
	while (tmpn >= 16)
	{
		tmpn = tmpn / 16;
		size++;
	}
	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			tmpn = n % 16;
			str[size] = ft_hexa(tmpn);
			n = n / 16;
			size--;
		}
	}
	return (str);
}

char			*ft_hexatoa(unsigned int n)
{
	char			*str;
	int				size;
	unsigned int	tmpn;

	tmpn = n;
	size = 0;
	while (tmpn >= 16)
	{
		tmpn = tmpn / 16;
		size++;
	}
	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			tmpn = n % 16;
			str[size] = ft_hexa(tmpn);
			n = n / 16;
			size--;
		}
	}
	return (str);
}
