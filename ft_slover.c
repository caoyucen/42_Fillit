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

#include "fillit"

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

/* find the longest line*/
int     ft_longestline(t_data workeddata)
{
    int     n;

XXXXXXXXXXX

    return (n);
}

int     ft_slover_fill(t_data workeddata, char **map, int i, int j)
{
    char    **temmap;
    int     n;

    n = ft_longestline(t_data workeddata);
    /* initial map for n line*/

    while ()
    //temmap = map;


}
