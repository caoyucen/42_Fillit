/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:56:02 by ycao              #+#    #+#             */
/*   Updated: 2017/05/01 14:56:25 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

int	ft_minmapsize(int num)
{
	if (num == 1)
		return (2);
	if (num == 2)
		return (3);
	if (num == 4)
		return (4);
	if (num == 6)
		return (5);
	if (num == 9)
		return (6);
	if (num == 12)
		return (7);
	if (num <= 16)
		return (8);
	if (num <= 20)
		return (9);
	if (num <= 25)
		return (10);
	return (11); /* how to calculate: int(sqrt(num * 4)), if it more than 25, just let it go  */
}

char **ft_init_map(int mapsize)
{
	char **map;
	int		i;

	map = (char**)malloc(sizeof(char*) * (mapsize + 1));
	map[mapsize] = NULL;
	while(++i < mapsize)
	{
		j = -1;
		map[i] = (char*)malloc(sizeof(char) * (mapsize + 1));
		while(++j < mapsize)
			map[i][j] = '.';
		map[i][mapsize] = NULL;
	}
	return (map);
}

void ft_free_map(char **map; int mapsize)
{
	int		i;

	i = -1;
	while(++i < mapsize + 1)
		free(map[i]);
	free(map);
}

t_data  ft_cleandata(t_data data, char **map)
{
	t_data start;


	return (start);
}

int     ft_slover_check(char a_data, char b_map)
{
	if(b_map == '.')
		return (a_data);
	if(b_map != '.' && a_data != '.')
		return (0); /* then clean data */
	if(b_map != '.' && a_data == '.')
		return (b_map);
}

char	**ft_checkmap_samemapsize(t_list list, t_data data, int mapsize)
{
	int		n;
	int		i;
	char	**map;

	map = ft_init_map(mapsize);
	i = -1;
	while (++i < mapsize * mapsize)


	return (map);
}

char	**ft_give_me_map(t_list list, t_data data)
{
	int		mapsize;
	char	**map;
	int		i;

	mapsize = ft_minmapsize(num); /* min mapsize, then add it one by one */
	data = ft_give_me_data(list, data);
	i = -1;
 	while ((map = ft_checkmap_samemapsize(XXXXXXXXXXXX) != NULL)
	{
		
	}

	return (map);
}
