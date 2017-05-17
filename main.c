/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:02:14 by ycao              #+#    #+#             */
/*   Updated: 2017/04/27 14:07:05 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	ft_init_list(t_list *list)
{
	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL)
	list->next = NULL;
	return (list);
}

void	fillit(int argc, char** argv)
{
	t_list	*list;

	list = ft_init_list(list);
	if (argc == 2)
	{
		if ((list = ft_pre_openfile(argv[1], list) != NULL)
		{


			return;
		}
	}
	ft_putstr("error/n");
}

int		main(int argc, char** argv)
{
	fillit(argc, argv);
	return (0);
}