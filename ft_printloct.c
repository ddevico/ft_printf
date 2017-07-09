/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printloct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printloct(va_list ap, t_flags *flag)
{
	char			*p;
	long long int	nb;
	int				i;
	int				plus;

	plus = 0;
	i = 0;
	nb = va_arg(ap, long long int);
	p = ft_octtoa(nb);
	plus += ft_put_special_space(flag, p);
	if (flag->hashtag != 0)
	{
		if (p[0] != '0')
		{
			ft_putchar('0');
			plus += 1;
		}
	}
	if (flag->point && !flag->hashtag && !flag->numberzero && p[0] == '0')
		return (plus);
	plus += ft_putzero(flag, p, nb);
	ft_putstr(p);
	return (ft_strlen(p) + plus);
}
