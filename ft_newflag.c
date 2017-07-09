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

t_flags				*ft_new_flags(void)
{
	t_flags			*flag;

	flag = (t_flags *)malloc(sizeof(t_flags));
	if (flag == NULL)
		return (NULL);
	flag->minus = 0;
	flag->plus = 0;
	flag->plushere = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->hashtag = 0;
	flag->nbhashtag = 0;
	flag->number = 0;
	flag->numbertwo = 0;
	flag->numberzero = 0;
	flag->nbarg = 0;
	flag->point = 0;
	flag->length = 0;
	flag->option = '1';
	return (flag);
}
