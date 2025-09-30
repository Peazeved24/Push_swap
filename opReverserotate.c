/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opReverserotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:25:28 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/30 15:03:15 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void reverse_rotate(t_list **stack)
{
    t_list *prev = NULL;
    t_list *last  = *stack;
    

    if(!*stack || !(*stack)->next)
        return;
    while(last->next)
    {
        prev = last;
        last = last->next;   
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

void ft_rra(t_list **stacka)
{
    reverse_rotate(stacka);
    write(1, "rra\n", 4); 
}

void ft_rrb(t_list **stackb)
{
    reverse_rotate(stackb);
    write(1, "rrb\n", 4); 
}

void ft_rrr(t_list **stacka, t_list **stackb)
{
    reverse_rotate(stacka);
    reverse_rotate(stackb);
     write(1, "rrr\n", 4); 
}