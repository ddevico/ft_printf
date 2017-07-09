/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddevico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:01:03 by ddevico           #+#    #+#             */
/*   Updated: 2016/01/19 11:58:21 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int			ft_printarg(va_list ap, char c, t_flags *flag)
{
	int i;
	i = 0;

	flag->option = c;
	if (c == 'd' || c == 'i')
		i = ft_printnbr(ap, flag);
	else if (c == 'D')
		i = ft_printlnbr(ap, flag);
	else if (c == 'c' && !flag->length)
		i = ft_printchar(ap, flag);
	else if (c == 'C' || (c == 'c' && flag->length == 2))
		i = ft_printwchar(ap, flag);
	else if (c == 's' && !flag->length)
		i = ft_printstr(ap, flag);
	else if (c == 'S' || (c == 's' && flag->length == 2))
		i = ft_printwstr(ap, flag);
	else if (c == 'u')
		i = ft_printunsigned(ap, flag);
	else if (c == 'U')
		i = ft_printlong(ap, flag);
	else if (c == 'p')
		i = ft_printvoid(ap, flag);
	else if (c == 'x')
		i = ft_printhexa(ap, 0, flag);
	else if (c == 'X')
		i = ft_printhexa(ap, 1, flag);
	else if (c == 'o')
		i = ft_printoct(ap, flag);
	else if (c == 'O')
		i = ft_printloct(ap, flag);
	else if (c == '%' || c >= 'A' || c <= 'Z')
		i = ft_printpourcent(c, flag);
	else if (c)
		i = ft_putchar(c);
	return (i);
}

int				ft_printf(char const *str, ...)
{
	int			count;
	va_list		ap;
	t_flags 	*flag;

	count = 0;
	va_start (ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!*(str + 1))
				return(count);
			str++;
			flag = ft_new_flags();
			if (*str != '%')
				str = ft_findflag(str, flag);
			count += ft_printarg(ap, *str, flag);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end (ap);
	return (count);
}

/*int main()
{
	//wchar_t texte[50] = {L'S', L'a', L'l', L'u', L't', L' ', L'G', 130, L'r', L'a', L'r', L'd', L' ', L'!', L'\0'};
	//char *a = (char *)malloc(2 * sizeof(char));
	//ft_printf("%d\n", ft_printf("%10x", 42));
	//printf("%d\n\n", printf("%x", -42));
	ft_printf("%d\n",  ft_printf("%4.1S", L"Jambon"));
	printf("%d\n\n", printf("%4.1S", L"Jambon"));
	//printf( "% c\n% d\n", ' ', -547 );
	//printf("%-d\n", 4917);
	return (0);
}*/

/*int main ()
{
	my_printf("%d\n", my_printf("1octal 1 %o octal 2 %o\n", 42, -42));
  printf("%d\n\n", printf("1octal 1 %o octal 2 %o\n\n", 42, -42));

  my_printf("%d\n", my_printf("2octal 1 %   o octal 2 % o\n", 42, -42));
  printf("%d\n\n", printf("3octal 1 %   o octal 2 % o\n\n", 42, -42));

  my_printf("%d\n", my_printf("4octal 1 %12o octal 2 %12o\n", 42, -42));
  printf("%d\n\n", printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42));

  my_printf("%d\n", my_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));
  printf("%d\n\n", printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42));

  my_printf("%d\n", my_printf("5octal 1 %0o octal 2 %0o\n", 42, -42));
  printf("%d\n\n", printf("5octal 1 %0o octal 2 %0o\n\n", 42, -42));

  my_printf("%d\n", my_printf("6octal 1 %012o octal 2 %012o\n", 42, -42));
  printf("%d\n\n", printf("6octal 1 %012o octal 2 %012o\n\n", 42, -42));

  my_printf("%d\n", my_printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));
  printf("%d\n\n", printf("7octal 1 %-012o octal 2 %012o\n\n", 42, -42));

  my_printf("%d\n", my_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));
  printf("%d\n\n", printf("8octal 1 %*o octal 2 %*o\n\n", 42, 6, 6, 6));

  my_printf("%d\n", my_printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("9octal 1 %+o octal 2 %+o\n\n", 42, 6, -42, 6));

  my_printf("%d\n", my_printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));
  printf("%d\n\n", printf("10octal 1 %+12o octal 2 %+12o\n\n", 42, 6, -42, 6));

  my_printf("%d\n", my_printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));
  printf("%d\n\n", printf("11octal 1 %*12o octal 2 %*12o\n\n", 42, -6, -42, 6));

  my_printf("%d\n", my_printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));
  printf("%d\n\n", printf("12octal 1 %-+5o octal 2 %-+5o\n\n", 42, -42));

  my_printf("%d\n", my_printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));
  printf("%d\n\n", printf("13octal 1 %-+05o octal 2 %-+05o\n\n", 42, -42));

  my_printf("%d\n", my_printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));
  printf("%d\n\n", printf("14octal 1 %+-5o octal 2 %+-5o\n\n", 42, -42));

  my_printf("%d\n", my_printf("15octal 1 %.o octal 2 %.o\n", 42, -42));
  printf("%d\n\n", printf("15octal 1 %.o octal 2 %.o\n\n", 42, -42));

  my_printf("%d\n", my_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
  printf("%d\n\n", printf("16octal 1 %.6o octal 2 %.6o\n\n", 42, -42));
  return (0);
}*/