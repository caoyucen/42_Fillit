/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:07:23 by ycao              #+#    #+#             */
/*   Updated: 2017/04/27 18:54:06 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_data	workeddata;

char	**map;

char	**ft_pre_list(char* buf)
{
	char**	list[4][4];
	int		i;
	int		j;
	int		z;






t_list	*ft_pre(char* filename)
{
	int		fd;
	t_list	*new;
	int		ret;
	int		line_num;
	char*	buf[21];

	new = NUll;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buf, 21)))
	{
		while(

