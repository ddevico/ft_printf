/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putzero(t_flags *flag, char *p, int nb)
{
	int i;
	int len;
	int plus;

	i = 0;
	len = (int)ft_strlen(p);
	plus = 0;
	if (flag->plushere && !flag->number)
		i++;
	if ((flag->zero && !flag->minus) || 
		(flag->point && !flag->hashtag))
	{
		if ((nb < 0 && !flag->point))
		{
			while (i < (flag->numberzero - len - 1))
			{
				ft_putchar('0');
				plus += 1;
				i++;
			}
		}
		else
		{
			while (i < (flag->numberzero - len))
			{
				ft_putchar('0');
				plus += 1;
				i++;
			}
		}
	}
	return (plus);
}

int				ft_putminus(t_flags *flag, char *p, int nb, int ok)
{
	int i;
	int plus;

	i = 0;
	plus = 0;
	if (flag->minus || (flag->minus && flag->zero))
	{
		if (nb < 0)
		{
			if (flag->plus == 1)
				plus += ft_put_special_flag_zero(flag, (int)ft_strlen(p), ok, p);
			else
				plus += ft_put_special_flag_zero(flag, (int)ft_strlen(p) + 1, ok, p);
		}
		else
		{
			if (flag->plus == 1)
				plus += ft_put_special_flag_zero(flag, (int)ft_strlen(p) - flag->nbarg + 2, ok, p);
			else
				plus += ft_put_special_flag_zero(flag, (int)ft_strlen(p) - flag->nbarg + 1, ok, p);
		}	
	}
	return (plus);
}

int				ft_puthashtag(t_flags *flag, char *p, int nb, int i)
{
	int plus;

	plus = 0;
	if (nb != 0 && flag->hashtag != 0)
	{
		if (i == 1)
		{
			ft_toupper(p);
			ft_putstr("0X");
		}
		else
			ft_putstr("0x");
		plus += 2;
		flag->hashtag = 2;
	}
	return (plus);
}

int				ft_putplus(t_flags *flag, char *p)
{
	int plus;
	int i;

	plus = 0;
	i = 0;
	if (flag->plus != 0)
	{
		if ((flag->minus != 1 && flag->number != 0))
		{
			plus += ft_put_special_flag_zero(flag, (int)ft_strlen(p), 1, p);
		}
		if (p[0] != '+' && p[0] != '-')
		{
			ft_putchar('+');
			flag->plushere = 1;
			plus += 1;
		}
	}
	return (plus);
}

int				ft_putspace(t_flags *flag, char *p)
{
	int i;
	int plus;

	plus = 0;
	i = 0;
	if (flag->space && p[0] != '-' && !flag->minus)
	{
		plus += ft_put_special_flag_zero(flag, (int)ft_strlen(p), 1, p);
	}
	if ((flag->space != 0 && p[0] != '-') && flag->plus != 1 && flag->number == 0)
	{
		ft_putchar(' ');
		plus += 1;
	}
	return (plus);
}
