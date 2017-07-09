/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflagchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:23:51 by ddevico           #+#    #+#             */
/*   Updated: 2015/11/30 14:00:35 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_putpoint_special(t_flags *flag, char *p)
{
	char *str;
	int i;

	if (!(str = (char*)malloc(sizeof(char) * flag->numberzero)))
		return (NULL);
	i = 0;
	if (flag->point != 0)
	{
		while (i < flag->numberzero)
		{
			str[i] = p[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

int				ft_putzero_special(t_flags *flag, char *p, int ok)
{
	int i;
	int len;
	int plus;

	i = 0;
	len = (int)ft_strlen(p);
	plus = 0;
	if ((flag->point && !ok))
		return (plus);
	if ((flag->zero && !flag->minus) || (flag->point && flag->minus))
	{
		if ((flag->hashtag && !flag->point) || (flag->option == 'p' && !flag->point))
		{
			while (i < (flag->numberzero - len - 2))
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

int				ft_putplus_special(t_flags *flag, char *p)
{
	int plus;
	int i;

	plus = 0;
	i = 0;
	if (flag->plus != 0 && p[0] != '+' && p[0] != '-')
	{
		if ((flag->minus != 1 && flag->number != 0))
		{
			while (i < (flag->number - (int)ft_strlen(p)))
			{
				ft_putchar(' ');
				plus += 1;
				i++;
			}
		}
	}
	return (plus);
}

int				ft_putminus_special(t_flags *flag, int count, int ok, int b, char *p)
{
	int plus;

	plus = 0;
	if ((flag->hashtag == 0 && flag->minus != 0) || (flag->minus != 0 
		&& flag->zero != 0))
		plus += ft_put_special_flag_zero(flag, count, ok, p);
	else if ((((b && flag->number) || flag->numberzero) != 0 && (flag->hashtag == 1 
		&& flag->minus != 0)) || (flag->minus != 0 && flag->zero != 0))
		plus += ft_put_special_flag_zero(flag, count + 1, ok, p);
	else if ((flag->number != 0 || flag->numberzero != 0) && ((flag->hashtag == 1 
		&& flag->minus != 0) || (flag->minus != 0 && flag->zero != 0)))
		plus += ft_put_special_flag_zero(flag, count, ok, p);
	else if (flag->minus != 0 || (flag->minus != 0 && flag->zero != 0 
		&& flag->hashtag == 1))
		plus += ft_put_special_flag_zero(flag, count + 1, ok, p);
	return (plus);
}
