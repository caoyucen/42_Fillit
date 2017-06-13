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

# include "fillit.h"
# include "global.h"

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
	int		j;

	i = -1;
	map = (char**)malloc(sizeof(char*) * mapsize);
	while(++i < mapsize)
	{
		j = -1;
		map[i] = (char*)malloc(sizeof(char) * (mapsize + 1));
		while(++j < mapsize)
			map[i][j] = '.';
		map[i][mapsize] = '\0';
	}
	return (map);
}

void ft_free_map(char **map, int mapsize)
{
	int		i;

	i = -1;

	while(++i < mapsize)
		free(map[i]);
		/*mark */
	ft_putstr(" something is wrong here, free map here we go\n");
		/*mark */
	free(map);
}

char     ft_point_check(char a_data, char b_map)
{

	if(b_map != '.' && a_data != '.')
		return (0); /* then clean data */
	if(b_map != '.' && a_data == '.')
		return (b_map);
/* else --->  if(b_map == '.') */
	return (a_data);
}

char		**ft_map_clean(char **map, int n, int mapsize)/*clean in every layer */
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < mapsize)
	{
		while (++j < mapsize)
		{
			if (map[i][j] == letter[n])
				map[i][j] = '.';
		}
	}
	return (map);
}

char	**ft_putmap_check(t_data *data, char **map, int i, int j, int mapsize)
{
	int a;
	int b;
	char temp;

	a = -1;
	while (++a <= (data->point[2] - data->point[0]))
	{
		b = -1;
		while (++b <= (data->point[3] - data->point[1]))
		{
			temp = ft_point_check(data->tetr[data->point[0] + a][data->point[1] + b], map[i + a][j + b]); /* can put it or not */
			if (temp)
				map[a + i][b + j] = temp;
			if (!temp)
			{
				ft_map_clean(map, data->n, mapsize);
				return (NULL);
			}
		}
	}
	return (map);
}

char		**ft_try_map(t_data *data, char** map, int mapsize)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < mapsize)
	{
		while (++j < mapsize)
		{
			if(((i + (data->point[2] - data->point[0])) > mapsize) || ((j + (data->point[3] - data->point[1])) > mapsize))
				continue;/* I have question here, have to ask zhuzhu ^-^ */
			if (ft_putmap_check(data, map, i, j, mapsize))
				{
					map = ft_putmap_check(data, map, i, j, mapsize);
					if (!data->next)
						return (map);
					if (ft_try_map(data->next, map, mapsize)) /*data->next ?? what is it? */
						return (map);
				}
		}
	}
	ft_map_clean(map, data->n, mapsize);
	return (NULL);
}

char	**ft_checkmap_samemapsize(t_data *data, int mapsize)
{
	char	**map;

	map = ft_init_map(mapsize);
	if (ft_try_map(data, map, mapsize))
		return (map);
	else
		return (NULL);
}

char	**ft_give_me_map(t_list *list, t_data *data)
{
	int		mapsize;
	char	**map;

	mapsize = ft_minmapsize(num); /* min mapsize, then add it one by one */
	data = ft_give_me_data(list, data);

 	while ((map = ft_checkmap_samemapsize(data, mapsize)) == NULL)
	{
		/*mark */
		// ft_putstr("map3here we go\n");
		/*mark */

		ft_free_map(map, mapsize);

		/*mark */
		ft_putstr("map4here we go\n");
		/*mark */

		mapsize++;
		/*mark */
		char c = 48 + mapsize;
		ft_putchar(c);
		/*mark */
	}
	return (map);
}
