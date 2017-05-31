/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:07:23 by ycao              #+#    #+#             */
/*   Updated: 2017/05/15 16:29:20 by ycao             ###   ########.fr       */
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

char	**ft_pre_buf(char* buf, t_list *list, int ret)
{
	int		i;
	int		j;
	int		z;
	int		n;

	if (list == NUll)
		return (NULL);
	if ((buf[4] != '/n') || (buf[9] != '/n') || (buf[14] != '/n') || (buf[20] != '/n'))
		return (NULL);
	if (ret == 21 && buf[21] != '/n')
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

t_list *ft_pre_openfile(char *filename, t_list *list)
{
	int fd;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((fd = open(filename, O_DIRECTORY)) >= 0)
		return (NULL);
	if ((list = ft_pre_readfile(list, fd, num)) == NULL)
		return (NULL);
	return (list);
}

t_list	*ft_pre_readfile(t_list *list, int fd, int num)
{
	int		ret;
	int		lastret;
	char	*buf;
	t_list	*start;

	num = 0;
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
		num++; /* global variables for the num of tetriminos*/
	}
	if (lastret != 20 || ret != 0)
		return (NULL);
	return (start);
}

/* this part is to make t_list to t_data */

t_data	*ft_init_data(t_data *data)
{
	int		i;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	i = -1;
	while (++i < 4)
		data->point[i] = 0;
	data->next = NULL;
	return (data);
}

t_data	*ft_pre_newdata(t_data *data)
{
	t_data	*newdata;
	int		i;

	newdata = (t_data*)malloc(sizeof(t_data));
	if (!newdata)
		return (NULL);
	i = -1;
	while (++i < 4)
		newdata->point[i] = 0;
	newdata->next = NULL;
	data->next = newdata;
	data = newdata; /* I have problem here */
	return (data);
}

int		*ft_list_to_data_point(t_data data, int i, int j)
{
	if(data->point[0] > i)
		data->point[0] = i;
	if(data->point[1] > j)
		data->point[1] = j;
	if(data->point[2] < i)
		data->point[2] = i;
	if(data->point[3] < j)
		data->point[3] = j;
	return(data);
}

t_data *ft_list_to_data(t_list list, t_data data)
{
	int		i;
	int		j;
	int		lline;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			t_data->tetr[i][j] = t_list->tetr[i][j];
			if (list->tetr[i][j] == '#')
				data = ft_list_to_data_point(data, i, j); /*this part is not sure */
		}
	}
} /* next didn't copy here */
