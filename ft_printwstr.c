/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_countwstr(wchar_t *c, int ok, t_flags *flag)
{
	size_t i;
	int count;

	i = 0;
	count = 0;
	while (c[i])
	{
		count += ft_put_w(c[i], count, ok, flag);
		i++;
	}
	return (count);
}

int					ft_printwstr(va_list ap, t_flags *flag)
{
	wchar_t			*c;
	int				count;
	int				plus;

	plus = 0;
	c = va_arg(ap, wchar_t*);
	if (!c || c == NULL)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	count = ft_countwstr(c, 0, flag);
	if (flag->numberzero == 1 && flag->point)
		count = 1;
	plus += ft_put_special_space_wstr(flag, count);
	count = ft_countwstr(c, 1, flag);
	plus += ft_putminus_special(flag, count, 0, 0, "");
	return (count + plus);
}
