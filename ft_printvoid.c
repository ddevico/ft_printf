/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printvoid(va_list ap, t_flags *flag)
{
	char			*p;
	unsigned long long	nb;
	int				plus;		

	plus = 0;
	nb = va_arg(ap, unsigned long long);
	p = ft_hexatoalong(nb);
	flag->number -= 2;
	plus += ft_put_special_space(flag, p);
	plus += ft_putplus_special(flag, p);
	ft_putstr("0x");
	if (flag->point && !flag->numberzero)
		return (2 + plus);
	plus += ft_putzero_special(flag, p, 1);
	ft_putstr(p);
	plus += ft_putminus_special(flag, ft_strlen(p), 1, 0, p);
	return (ft_strlen(p) + 2 + plus);
}
