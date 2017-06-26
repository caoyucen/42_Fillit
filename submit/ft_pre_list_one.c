/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:07:23 by ycao              #+#    #+#             */
/*   Updated: 2017/06/24 17:24:10 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

t_list	*ft_init_list(t_list *list)
{
	int i;
	int j;

	i = -1;
	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			list->tetr[i][j] = 'w';
		list->tetr[i][j] = 0;
	}
	list->next = NULL;
	return (list);
}

t_list	*ft_pre_newlist(t_list *list)
{
	int		i;
	int		j;
	t_list	*newlist;

	i = -1;
	newlist = (t_list*)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			newlist->tetr[i][j] = 'w';
		newlist->tetr[i][j] = 0;
	}
	newlist->next = NULL;
	list->next = newlist;
	list = newlist;
	return (list);
}

int		ft_invaild_list_around(t_list *list, int i, int j)
{
	int n;

	n = 0;
	if (list->tetr[i - 1][j] == '#')
		n++;
	if (list->tetr[i + 1][j] == '#')
		n++;
	if (list->tetr[i][j + 1] == '#')
		n++;
	if (list->tetr[i][j - 1] == '#')
		n++;
	return (n);
}

int		ft_invaild_list(t_list *list)
{
	int i;
	int j;
	int n;
	int temp;

	n = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (list->tetr[i][j] == '#')
			{
				temp = 0;
				if (!(temp = ft_invaild_list_around(list, i, j)))
					return (0);
				if (temp == 1)
					n++;
			}
		}
	}
	if (n == 4)
		return (0);
	return (1);
}

int		ft_pre_buf_part2(char *buf, t_list *list, int n)
{
	int		i;
	int		j;
	int		z;

	i = -1;
	z = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((z == 4) || (z == 9) || (z == 14))
				z++;
			if (buf[z] != '#' && buf[z] != '.')
				return (0);
			list->tetr[i][j] = buf[z];
			if (list->tetr[i][j] == '#')
				n++;
			z++;
		}
	}
	if (n != 4)
		return (0);
	return (1);
}
