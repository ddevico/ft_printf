/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printoct(va_list ap, t_flags *flag)
{
	char			*p;
	uintmax_t		nb;
	int				i;
	int				plus;

	plus = 0;
	nb = ft_printf_get_unsigned_from_length(ap, flag);
	p = ft_octtoa(nb);
	i = 0;
	plus += ft_put_special_space(flag, p);
	plus += ft_put_special_space_hashtag(flag, p, 1);
	plus += ft_putplus_special(flag, p);
	if (flag->hashtag != 0)
	{
		if (p[0] != '0')
		{
			ft_putchar('0');
			plus += 1;
		}
	}
	plus += ft_putzero_special(flag, p, 1);
	if (flag->point && !flag->hashtag && !flag->numberzero && p[0] == '0')
		return (plus);
	ft_putstr(p);
	plus += ft_putminus_special(flag, ft_strlen(p), 1, 0, p);
	return (ft_strlen(p) + plus);
}
