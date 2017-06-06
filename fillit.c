/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:52:10 by ycao              #+#    #+#             */
/*   Updated: 2017/06/06 11:52:15 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

void init_global()
{
	int i;

	num = 0;
	i = 0;
	while (i < 26)
	{
		letter[i] = 'A' + i;
		i++;
	}
}

void	fillit(int argc, char** argv)
{
	t_list	*list;
	t_data	*data;
	char		**map;

	list = ft_init_list(list);
	data = ft_init_data(data);
	init_global();
	if (argc == 2)
	{
		if ((list = ft_pre_openfile(argv[1], list) != NULL)
		{
			/* solve part */
			/*print part */



			return;
		}
	}
	ft_putstr("error/n");
}
