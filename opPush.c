/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opPush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:00:46 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/21 18:11:11 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void ft_pa(t_list **stacka, t_list **stackb)
{
    t_list *node2 = *stackb;
    
    if(!stackb || !*stackb)
        return;
    
    *stackb = (*stackb)->next;
    node2->next = *stacka;
    *stacka = node2;
    write(1, "pa\n", 3);
}

void ft_pb(t_list ** stacka, t_list **stackb)
{
    
    t_list *node =  *stacka; //minha cabeva 

    if(!stacka || !*stacka)
        return;
    *stacka = (*stacka)->next;
    node->next = *stackb; // cabeca agora aponta para B
    *stackb = node; // valor 1 de b e node(valor inicial de b)
     write(1, "pb\n", 3);
}