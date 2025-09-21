/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opReverserotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:25:28 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/08 16:34:00 by peazeved         ###   ########.fr       */
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
    printf("rra\n"); 
}

void ft_rrb(t_list **stackb)
{
    reverse_rotate(stackb);
    printf("rrb\n");
}

void ft_rrr(t_list **stacka, t_list **stackb)
{
    reverse_rotate(stacka);
    reverse_rotate(stackb);
    printf("rrr\n");
}