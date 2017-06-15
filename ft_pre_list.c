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

# include "fillit.h"
# include "global.h"

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
	int i;
	int j;
	t_list *newlist;

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

t_list	*ft_pre_buf(char *buf, t_list *list, int ret)
{
	int		i;
	int		j;
	int		z;
	int		n;

	if (list == NULL)
		return (NULL);
	if ((buf[4] != '\n') || (buf[9] != '\n') || (buf[14] != '\n') || (buf[19] != '\n'))
		return (NULL);
	if ((ret == 21) && (buf[20] != '\n'))
		return (NULL);
	i = -1;
	z = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			n = 0;
			if ((z == 4) || (z == 9) || (z == 14))
				z++;
			if (buf[z] != '#' && buf[z] != '.' )
				return (NULL);
			list->tetr[i][j] = buf[z];
			if (buf[z] == '#')
			{
				n++; /* check if there is only 4 # in a tetr */
			}
			z++;
		}
		 /*I need something mor here */
	}
	// if (n != 4)
	// {
	// 	ft_putnbr(n);
	// 	return (NULL);
	// }
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
	start = list;

	while ((ret = read(fd, buf, 21)))
	/* ret is the actual number of chars in buf */
	{
		lastret = ret; /* to ckeck the last ret is 20 or not */
		if (num > 0)
		{
			list = ft_pre_newlist(list);
		}
		list = ft_pre_buf(buf, list, ret);
		if (list == NULL)
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
		return (NULL);
	if ((list = ft_pre_readfile(list, fd)) == NULL)
		return (NULL);
	return (list);
}

/* I need to check the wrong data here !!!!! */
