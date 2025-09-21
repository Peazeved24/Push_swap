/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opRotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:53:09 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/06 16:42:17 by peazeved         ###   ########.fr       */
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
    node->next = NULL; //  o meu primeiro e o ultimo!
    last->next = node;
}

void ft_ra(t_list **stacka)
{
    ft_rotate(stacka);   
    printf("ra\n");
}

void ft_rb(t_list **stackb)
{
    ft_rotate(stackb);
    printf("rb\n");
}

void ft_rr(t_list **stacka, t_list **stackb)
{
    ft_rotate(stacka);
    ft_rotate(stackb);
    printf("rr\n");
}