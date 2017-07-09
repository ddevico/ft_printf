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

intmax_t			ft_printf_get_signed_from_length(va_list ap,
		t_flags *flag)
{
	intmax_t	nbr;

	nbr = va_arg(ap, intmax_t);
	if (flag->length == 6)
		nbr = (char)nbr;
	else if (flag->length == 1)
		nbr = (short int)nbr;
	else if (flag->length == 2)
		nbr = (long int)nbr;
	else if (flag->length == 5)
		nbr = (long long int)nbr;
	else if (flag->length == 3)
		nbr = (intmax_t)nbr;
	else if (flag->length == 4)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t			ft_printf_get_unsigned_from_length(va_list ap,
		t_flags *flag)
{
	uintmax_t	nbr;

	nbr = va_arg(ap, uintmax_t);
	if (flag->length == 6)
		nbr = (unsigned char)nbr;
	else if (flag->length == 1)
		nbr = (unsigned short int)nbr;
	else if (flag->length == 2)
		nbr = (unsigned long int)nbr;
	else if (flag->length == 5)
		nbr = (unsigned long long int)nbr;
	else if (flag->length == 3)
		nbr = (uintmax_t)nbr;
	else if (flag->length == 4)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
