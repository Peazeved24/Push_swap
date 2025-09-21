/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapOp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:18:30 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/03 15:23:49 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"



static void ft_swap(t_list **stack)
{
    if(!stack || !*stack)
        return;
    t_list *node = *stack;
    t_list *node2 = (*stack)->next; // (*is the way!!!)
    node->next = node2->next;
    node2->next = node;
    *stack = node2;
}

void ft_sa(t_list **stacka)
{
    ft_swap(stacka);
    printf("sa\n");
}


void ft_sb(t_list **stackb)
{
    ft_swap(stackb);
    printf("sb\n");
}


void ft_ss(t_list **stacka, t_list **stackb)
{
    ft_swap(stacka);
    ft_swap(stackb);
    printf("ss\n");
}