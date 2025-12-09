/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opRotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:53:09 by peazeved          #+#    #+#             */
/*   Updated: 2025/12/09 13:34:33 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"


static void ft_rotate(t_list **stack)
{
    t_list *node = *stack;
    t_list *last = *stack;

    if(!*stack || !(*stack)->next)
        return;
    
    while(last->next)
    {
        last = last->next;
    }
    *stack = node->next;
    node->next = NULL;
    last->next = node;
}

void ft_ra(t_list **stacka)
{
    ft_rotate(stacka);   
    write(1, "ra\n", 3); 
}

void ft_rb(t_list **stackb)
{
    ft_rotate(stackb);
    write(1, "rb\n", 3); 
}

void ft_rr(t_list **stacka, t_list **stackb)
{
    ft_rotate(stacka);
    ft_rotate(stackb);
    write(1, "rr\n", 3); 
}