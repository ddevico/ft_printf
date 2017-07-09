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

static const char		*ft_checkflag2(const char *str, t_flags *flag)
{
	if (flag->length == 0)
	{
		if (*str == 'h' && *(str + 1) == 'h')
			flag->length = 6;
		else if (*str == 'l' && *(str + 1) == 'l')
			flag->length = 5;
		else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		{
			if (*str == 'h')
				flag->length = 1;
			else if (*str == 'l')
				flag->length = 2;
			else if (*str == 'j')
				flag->length = 3;
			else if (*str == 'z')
				flag->length = 4;
		}
		str++;
		flag->nbarg += 1;
	}
	else
		str++;
	return (str);
}

static const char		*ft_checkenum(const char *str, t_flags *flag)
{
	int tmp;
	tmp = 0;
	while (*str)
	{
		if (ft_strchr(NUM, *str))
			str = ft_checknumber(str, flag);
		else if (*str == '.')
		{
			//flag->zero = 1;
			str = ft_checknumberzero(++str, flag);
			flag->point = 1;
		}
		else
			break ;
		str++;
	}
	return (str);
}


static const char		*ft_checkflag1(const char *str, t_flags *flag)
{
	if (*str == '#')
		flag->hashtag = 1;
	else if (*str == '0')
	{
		flag->zero = 1;
		str = ft_checknumberzero(++str, flag);
	}
	else if (*str == '-')
	{
		flag->minus = 1;
		str = ft_checknumber(++str, flag);
		flag->nbarg += 1;
	}
	else if (*str == '+')
	{
		flag->plus = 1;
		flag->nbarg += 1;
	}
	else if (*str == ' ')
	{
		flag->space = 1;
		str = ft_checkspace(str);
	}
	str++;
	return (str);
}

const char		*ft_findflag(const char *str, t_flags *flag)
{
	while (*str)
	{
		if (*str == '#' || *str == '+' || *str == '-'
			|| *str == ' ' || *str == '0')
			str = ft_checkflag1(str, flag);
		else if (*str == 'h' || *str == 'l' || *str == 'j'
			|| *str == 'z')
			str = ft_checkflag2(str, flag);
		else if (ft_strchr(NUM, *str) || *str == '.')
			str = ft_checkenum(str, flag);
		else
			break ;
	}
	if (!*str)
		exit(0);
	return (str);
}