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

int			ft_printchar(va_list ap, t_flags *flag)
{
	char	c;
	int		plus;

	plus = 0;
	c = va_arg(ap, int);
	plus += ft_put_special_space(flag, "1");
	plus += ft_putplus_special(flag, "1");
	if ((!c || flag->point) && !flag->zero)
		plus += ft_putzero_special(flag, "1", 0);
	else
		plus += ft_putzero_special(flag, "1", 1);
	ft_putchar(c);
	plus += ft_putminus_special(flag, 1, 1, 0, "1");
	return (1 + plus);
}
