/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:12:39 by ycao              #+#    #+#             */
/*   Updated: 2017/04/18 16:14:18 by ycao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct  s_list
{
    char            **data[4][4];
    int             topleft;
    int             topright;
    int             bottomleft;
    int             bottomright;
    struct  s_list  *next;
}               t_data;

typedef struct  s_list
{
    char            **data[4][4];
    struct  s_list  *next;
}               t_list;
