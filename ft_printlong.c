/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printlong(va_list ap, t_flags *flag)
{
	unsigned long int 		nb;
	char			*c;
	int				plus;

	nb = va_arg(ap, unsigned long int);
	plus = 0;
	c = ft_utoa_long(nb);
	plus += ft_putzero(flag, c, nb);
	ft_putstr(c);
	return (ft_strlen(c) + plus);
}
