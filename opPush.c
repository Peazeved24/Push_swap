/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opPush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:00:46 by peazeved          #+#    #+#             */
/*   Updated: 2025/12/09 13:35:45 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void ft_pa(t_list **stacka, t_list **stackb)
{
    t_list *node;

    if (!stackb || !*stackb)
        return;
    node = *stackb;
    *stackb = (*stackb)->next;
    node->next = *stacka;
    *stacka = node;       
    write(1, "pa\n", 3);
}

void ft_pb(t_list **stacka, t_list **stackb)
{
    t_list *node;

    if (!stacka || !*stacka)
        return;
    node = *stacka;
    *stacka = (*stacka)->next;
    node->next = *stackb;
    *stackb = node;
    write(1, "pb\n", 3);
}
