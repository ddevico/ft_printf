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

int					ft_printunsigned(va_list ap, t_flags *flag)
{
	uintmax_t		nbr;
	char			*p;
	int				plus;

	plus = 0;
	nbr = ft_printf_get_unsigned_from_length(ap, flag);
	if (flag->length)
		p = ft_utoa_long(nbr);
	else
		p = ft_utoa_long(nbr);
	plus += ft_put_special_space(flag, p);
	plus += ft_putplus_special(flag, p);
	plus += ft_putzero_special(flag, p, 1);
	if (flag->point && !flag->numberzero)
		return (plus);
	ft_putstr(p);
	plus += ft_putminus_special(flag, ft_strlen(p), 1, 0, p);
	return (ft_strlen(p) + plus);
}
