/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:01:58 by ddevico           #+#    #+#             */
/*   Updated: 2015/12/07 14:20:55 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_put_special_flag_zero(t_flags *flag, int len, int ok, char *p)
{
	int			plus;
	int			i;

	plus = 0;
	i = 0;
	if ((flag->hashtag && flag->minus) || flag->plus || p[0] == '-')
		i++;
	if (flag->zero && ok && (flag->numberzero - len) >= 0 && !flag->hashtag)
	{
		while (i < (flag->number - len) - (flag->numberzero - len))
		{
			ft_putchar(' ');
			plus += 1;
			i++;
		}
	}
	else
	{
		if (p[0] == '-')
			i--;
		while (i < (flag->number - len))
		{
			ft_putchar(' ');
			plus += 1;
			i++;
		}
	}
	return (plus);
}

int				ft_put_special_space_hashtag(t_flags *flag, char *p, int nb)
{
	int			plus;
	int			i;

	plus = 0;
	i = 0;
	if ((flag->number && flag->hashtag) && !flag->minus)
	{
		while (i < (flag->number - (int)ft_strlen(p) - nb))
		{
			ft_putchar(' ');
			plus += 1;
			i++;
		}
	}
	return (plus);
}

int				ft_put_special_space_wstr(t_flags *flag, int count)
{
	int			plus;
	int			i;

	plus = 0;
	i = 0;
	if ((flag->number && flag->plus != 1 && !flag->minus 
		&& !flag->space && !flag->hashtag))
	{
		while (i < (flag->number - count))
		{
			ft_putchar(' ');
			plus += 1;
			i++;
		}
	}
	return (plus);
}

int				ft_put_special_space_str(t_flags *flag, char *p)
{
	int			plus;
	int			i;

	plus = 0;
	i = 0;
	if ((flag->number && flag->plus != 1 && !flag->minus 
		&& !flag->space && !flag->hashtag))
	{
		while (i < (flag->number - (int)ft_strlen(p)))
		{
			ft_putchar(' ');
			plus += 1;
			i++;
		}
	}
	return (plus);
}

int				ft_put_special_space(t_flags *flag, char *p)
{
	int			plus;
	int			i;

	plus = 0;
	i = 0;
	if ((flag->number && !flag->plus && !flag->minus 
		&& !flag->space && !flag->hashtag))
	{
		plus += ft_put_special_flag_zero(flag, ft_strlen(p), 1, p);
	}
	return (plus);
}
