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

int					ft_printhexa(va_list ap, int i, t_flags *flag)
{
	char			*p;
	int				plus;
	uintmax_t		nbr;

	plus = 0;
	nbr = ft_printf_get_unsigned_from_length(ap, flag);
	if (flag->length)
		p = ft_hexatoalong(nbr);
	else
		p = ft_hexatoa(nbr);
	if (i == 1)
		ft_toupper(p);
	plus += ft_put_special_space(flag, p);
	plus += ft_put_special_space_hashtag(flag, p, 2);
	plus += ft_puthashtag(flag, p, nbr, i);
	plus += ft_putplus_special(flag, p);
	plus += ft_putzero_special(flag, p, 1);
	if (flag->point && !flag->numberzero && p[0] == '0')
	{
		return (plus);
	}
	ft_putstr(p);
	plus += ft_putminus_special(flag, ft_strlen(p), 1, 1, p);
	return (ft_strlen(p) + plus);
}
