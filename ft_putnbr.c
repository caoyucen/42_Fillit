/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:24:37 by ycao              #+#    #+#             */
/*   Updated: 2017/03/23 17:56:28 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
# include "global.h"

static void	ft_put_positive(int n)
{
	if (n < 10)
	{
		ft_putchar(n + 48);
		return ;
	}
	ft_put_positive(n / 10);
	ft_putchar(n % 10 + 48);
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_put_positive(n);
}
