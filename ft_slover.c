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

t_data  ft_cleandate(t_list list)
{
    t_data cdata;


    return (cdata);
}

int     ft_slover_check(char a_data, char b_map)
{
    if(b_map == '.')
        return (a_data);
    if(b_map != '.' && a_data != '.')
        return (0);
    if(b_map != '.' && a_data == '.')
        return (b_map);
}

int     ft_slover_fill(t_data workeddata, char **map, int i, int j)
{
    char    **temmap;
    int     n;



}
