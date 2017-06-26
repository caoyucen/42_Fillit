/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:52:28 by ycao              #+#    #+#             */
/*   Updated: 2017/06/24 16:05:21 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

t_data	*ft_init_data(t_data *data)
{
	int i;
	int j;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->point[0] = 9;
	data->point[1] = 9;
	data->point[2] = 0;
	data->point[3] = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			data->tetr[i][j] = 'w';
		data->tetr[i][j] = 0;
	}
	data->next = NULL;
	data->before = NULL;
	return (data);
}

t_data	*ft_pre_newdata(t_data *data)
{
	t_data	*newdata;
	int		i;
	int		j;

	newdata = (t_data*)malloc(sizeof(t_data));
	if (!newdata)
		return (NULL);
	newdata->point[0] = 9;
	newdata->point[1] = 9;
	newdata->point[2] = 0;
	newdata->point[3] = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			newdata->tetr[i][j] = 'w';
		newdata->tetr[i][j] = 0;
	}
	newdata->next = NULL;
	data->next = newdata;
	newdata->before = data;
	data = newdata;
	return (data);
}

t_data	*ft_list_to_data_point(t_data *data, int i, int j)
{
	if (data->point[0] > i)
		data->point[0] = i;
	if (data->point[1] > j)
		data->point[1] = j;
	if (data->point[2] < i)
		data->point[2] = i;
	if (data->point[3] < j)
		data->point[3] = j;
	return (data);
}

t_data	*ft_list_to_data(t_list *list, t_data *data, char c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			data->tetr[i][j] = list->tetr[i][j];
			if (data->tetr[i][j] == '#')
			{
				data = ft_list_to_data_point(data, i, j);
				data->tetr[i][j] = c;
			}
		}
	}
	return (data);
}

t_data	*ft_give_me_data(t_list *list, t_data *data)
{
	int		i;
	t_data	*start;

	start = data;
	i = 0;
	while (i < g_num)
	{
		data = ft_list_to_data(list, data, g_letter[i]);
		data->n = i;
		i++;
		list = list->next;
		if (i < g_num)
			data = ft_pre_newdata(data);
	}
	return (start);
}
