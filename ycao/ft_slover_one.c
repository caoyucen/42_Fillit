/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:56:02 by ycao              #+#    #+#             */
/*   Updated: 2017/06/24 16:18:13 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

int		ft_minmapsize(int num)
{
	if (num == 1)
		return (2);
	if (num == 2)
		return (3);
	if (num <= 4)
		return (4);
	if (num <= 6)
		return (5);
	if (num <= 9)
		return (6);
	if (num <= 12)
		return (7);
	if (num <= 16)
		return (8);
	if (num <= 20)
		return (9);
	if (num <= 25)
		return (10);
	return (11);
}

char	**ft_init_map(int mapsize)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = (char**)malloc(sizeof(char*) * mapsize + 1);
	map[mapsize] = NULL;
	while (++i < mapsize)
	{
		j = -1;
		map[i] = (char*)malloc(sizeof(char) * (mapsize + 1));
		while (++j < mapsize)
			map[i][j] = '.';
		map[i][mapsize] = '\0';
	}
	return (map);
}

void	ft_free_map(char **map, int mapsize)
{
	int		i;

	i = -1;
	while (++i < mapsize)
		free(map[i]);
	free(map);
}

char	ft_point_check(char a_data, char b_map)
{
	if (b_map != '.' && a_data != '.')
		return (0);
	if (b_map != '.' && a_data == '.')
		return (b_map);
	else
		return (a_data);
}

char	**ft_map_clean(char **map, int n, int mapsize)
{
	int i;
	int j;

	i = -1;
	while (++i < mapsize)
	{
		j = -1;
		while (++j < mapsize)
		{
			if (map[i][j] == g_letter[n])
				map[i][j] = '.';
		}
	}
	return (map);
}
