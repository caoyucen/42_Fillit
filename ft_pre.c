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

t_list	list;
int 	num;
/* inital list */
XXXXXX

char	**ft_pre_buf(char* buf, t_list list, int ret)
{
	int		i;
	int		j;
	int		z;

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
			list->data[i][j] = buf[z];
			z++;
		}
	}
	return (list);
}

t_list *ft_pre_openfile(char *filename, t_list list)
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

t_list	*ft_pre_readfile(t_list list, int fd, int num)
{
	int		ret;
	int		lastret;
	char	*buf;

	buf = ft_strnew(21);
	while ((ret = read(fd, buf, 21)))
	/* ret is the actual number of chars in buf */
	{
		lastret = ret;
		ft_pre_buf(char* buf, t_list list, int ret)
			

