/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opRadix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:44:58 by peazeved          #+#    #+#             */
/*   Updated: 2025/12/09 13:34:57 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void ft_index(t_list *node)
{
    t_list *i, *j;
    int index;

    i = node;
    while(i != NULL)
    {
        index = 0;
        j = node;
        while(j != NULL)
        {
            if(*(int*)j->data < *(int*)i->data)
                index++;
            j = j->next;
        }
        i->index = index;
        i = i->next;
    }
}

void ft_radixsort(t_list **stacka, t_list **stackb, int size)
{
    if(!*stacka || ft_list_size(*stacka) < 5)
        return;
    int mb;
    int i = 0;

    mb = 0;
    while ((size - 1) >> mb)
        mb++;
    while (i < mb)
    {
        int j = 0;
        while (j < size)
        {
            int num = (*stacka)->index;
            if (((num >> i) & 1) == 0)
                ft_pb(stacka, stackb); 
            else
                ft_ra(stacka);
            j++;
        }
        while (*stackb != NULL)
            ft_pa(stacka, stackb);
        i++;
    }
}