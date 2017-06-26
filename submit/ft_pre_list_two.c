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

t_list	*ft_pre_buf(char *buf, t_list *list, int ret)
{
	int n;

	n = 0;
	if (list == NULL)
		return (NULL);
	if ((buf[4] != '\n') || (buf[9] != '\n')
			|| (buf[14] != '\n') || (buf[19] != '\n'))
		return (NULL);
	if ((ret == 21) && (buf[20] != '\n'))
		return (NULL);
	if (!ft_pre_buf_part2(buf, list, n))
		return (NULL);
	if (ft_invaild_list(list) == 0)
		return (NULL);
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
	{
		lastret = ret;
		if (g_num > 0)
		{
			list = ft_pre_newlist(list);
		}
		list = ft_pre_buf(buf, list, ret);
		if (list == NULL)
			return (NULL);
		g_num++;
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
