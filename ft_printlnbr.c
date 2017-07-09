/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printlnbr(va_list ap, t_flags *flag)
{
	long long int	c;
	char		*p;
	int			plus;

	plus = 0;
	c = va_arg(ap, long long int);
	p = ft_itoalong(c);
	plus += ft_putplus(flag, p);
	plus += ft_putzero(flag, p, c);
	plus += ft_putspace(flag, p);
	ft_putstr(p);
	return ((ft_strlen(p) + plus));
}
