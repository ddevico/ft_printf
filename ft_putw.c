/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:40:09 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 13:53:53 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_put_w_3(char str[4], wint_t c, int ok, int rt, t_flags *flag)
{
	int number;

	number = flag->numberzero;
	str[0] = ((c >> 18) + 0xF0);
	str[1] = (((c >> 12) & 0x3F) + 0x80);
	str[2] = (((c >> 6) & 0x3F) + 0x80);
	str[3] = ((c & 0x3F) + 0x80);
	if ((number && (rt + 4) <= number) || (!number && !flag->point))
	{
		if (ok)
			ft_putwchar(str, 4);
		return (4);
	}
	return (0);
}

static	int	ft_put_w_2(char str[4], wint_t c, int ok, int rt, t_flags *flag)
{
	int number;

	number = flag->numberzero;
	str[0] = ((c >> 12) + 0xE0);
	str[1] = (((c >> 6) & 0x3F) + 0x80);
	str[2] = ((c & 0x3F) + 0x80);
	if ((number && (rt + 3) <= number) || (!number && !flag->point))
	{
		if (ok)
			ft_putwchar(str, 3);
		return (3);
	}
	return (0);
}

static	int	ft_put_w_1(char str[4], wint_t c, int ok, int rt, t_flags *flag)
{
	int number;

	number = flag->numberzero;
	str[0] = ((c >> 6) + 0xC0);
	str[1] = ((c & 0x3F) + 0x80);
	if ((number && (rt + 2) <= number) || (!number && !flag->point))
	{
		if (ok)
			ft_putwchar(str, 2);
		return (2);
	}
	return (0);
}

int			ft_put_w(wint_t c, int count, int ok, t_flags *flag)
{
	char	str[4];
	int		rt;

	rt = 1;
	if (flag->point)
	{
		if ((count < flag->numberzero && ok))
			ft_putwchar(&c, 1);
	}
	else if (c <= 0x7F && ok)
		ft_putwchar(&c, 1);
	else if (c <= 0x7FF)
		rt = ft_put_w_1(str, c, ok, count, flag);
	else if (c <= 0xFFFF)
		rt = ft_put_w_2(str, c, ok, count, flag);
	else if (c <= 0x10FFFF)
		rt = ft_put_w_3(str, c, ok, count, flag);
	return (rt);
}

void		ft_putwchar(void *mem, int size)
{
	char	*str;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		write(1, str + i, 1);
		i++;
	}
}
