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

int					ft_printnbr(va_list ap, t_flags *flag)
{
	char			*p;
	int				plus;
	intmax_t		nbr;

	nbr = ft_printf_get_signed_from_length(ap, flag);
	plus = 0;
	if (flag->length)
		p = ft_itoalong(nbr);
	else
		p = ft_itoa(nbr);
	plus += ft_put_special_space(flag, p);
	plus += ft_putspace(flag, p);
	plus += ft_putplus(flag, p);
	if (p[0] == '-')
	{
		plus += 1;
		ft_putchar('-');
		p++;
	}
	if (flag->point && !flag->numberzero && p[0] == '0')
		return (plus);
	if (nbr == 0 && !flag->plus && !flag->point)
		flag->numberzero -= 1;
	plus += ft_putzero(flag, p, nbr);
	ft_putstr(p);
	plus += ft_putminus(flag, p, nbr, 1);
	return (ft_strlen(p) + plus);
}
