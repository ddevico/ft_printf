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

int			ft_printstr(va_list ap, t_flags *flag)
{
	char	*c;
	int		plus;

	plus = 0;
	c = va_arg(ap, char *);
	if ((c == NULL || !c) && !flag->zero)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	if (flag->point)
		c = ft_putpoint_special(flag, c);
	plus += ft_putzero_special(flag, c, 0);
	plus += ft_put_special_space_str(flag, c);
	ft_putstr(c);
	plus += ft_putminus_special(flag, ft_strlen(c), 0, 0, c);
	return (ft_strlen(c) + plus);
}
