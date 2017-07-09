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

static int 		ft_search_char(const char *str, t_flags *flag)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (str[i])
	{
		if (str[i] == 'c')
			if (!flag->zero)
				ok++;
		i++;
	}
	return (ok);
}

const char		*ft_checknumberzero(const char *str, t_flags *flag)
{
	int			nb;
	int			c;
	int 		ok;

	ok = ft_search_char(str, flag);
	nb = ft_atoi(str);
	c = ft_countnumber(str);
	if (!ok)
		flag->zero = 1;
	if (flag->zero == 1 && !flag->number && nb)
	{
		flag->number = flag->numberzero;
		flag->numberzero = nb;
	}
	else if (!flag->numberzero && nb)
		flag->numberzero = nb;
	str += c - 1;
	return (str);
}

const char		*ft_checknumber(const char *str, t_flags *flag)
{
	int		nb;
	int		c;

	nb = ft_atoi(str);
	c = ft_countnumber(str);
	if (flag->zero && !flag->space && !flag->numberzero && !flag->minus)
	{
		flag->numberzero = nb;
	}
	else if (!flag->number)
	{
		flag->number = nb;
	}
	str += c - 1;
	return (str);
}
