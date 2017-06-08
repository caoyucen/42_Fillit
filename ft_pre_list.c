/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:07:23 by ycao              #+#    #+#             */
/*   Updated: 2017/05/15 16:29:20 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

t_list	*ft_init_list(t_list *list)
{
	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL)
	list->next = NULL;
	return (list);
}

t_list	*ft_pre_newlist(t_list *list)
{
	t_list *newlist;

	newlist = (t_list*)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->next = NULL;
	list->next = newlist;
	list = newlist;
	return (list);
}

t_list	*ft_pre_buf(char *buf, t_list *list, int ret)
{
	int		i;
	int		j;
	int		z;
	int		n;

	if (list == NULL)
		return (NULL);
	if ((buf[4] != '/n') || (buf[9] != '/n') || (buf[14] != '/n') || (buf[20] != '/n'))
		return (NULL);/*this part is wrong */
	if ((ret == 21) && (buf[21] != '/n'))
		return (NULL);
	i = -1;
	z = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((z = 4) || (z = 9) || (z = 14))
				z++;
			if (buf[z] != '#' && buf[z] != '.' )
				return (NULL);
			list->tetr[i][j] = buf[z];
			if (buf[z] == '#')
				n++; /* check if there is only 4 # in a tetr */
			z++;
		}
		if (n > 4)
			return (NULL);
	}
	return (list);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

t_list	*ft_pre_readfile(t_list *list, int fd)
{
	int		ret;
	int		lastret;
	char	*buf;
	t_list	*start;

	buf = ft_strnew(21);
	start = list; /* I have question here */
	while ((ret = read(fd, buf, 21)))
	/* ret is the actual number of chars in buf */
	{
		lastret = ret; /* to ckeck the last ret is 20 or not */
		if (start != list)
			list = ft_pre_newlist(list);
		if ((list = ft_pre_buf(buf, list, ret)) == NULL)
			return (NULL);
		num++;/* global variables for the num of tetriminos*/
	}
	if (lastret != 20 || ret != 0)
		return (NULL);
	return (start);
}

t_list	*ft_pre_openfile(char *filename, t_list *list)
{
	int fd;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);/*do I need to cout what is the error??? */
	if ((fd = open(filename, O_DIRECTORY)) >= 0)
		return (NULL);
	if ((list = ft_pre_readfile(list, fd, num)) == NULL)
		return (NULL);
	return (list);
}

/* I need to check the wrong data here*/
