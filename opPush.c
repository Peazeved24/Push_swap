/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opPush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:00:46 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/28 13:11:24 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void ft_pa(t_list **stacka, t_list **stackb)
{
    t_list *node;

    if (!stackb || !*stackb)
        return;
    node = *stackb;              // pega o topo de B
    *stackb = (*stackb)->next;   // avança B
    node->next = *stacka;        // liga no topo de A
    *stacka = node;              // agora A aponta para o novo topo
    write(1, "pa\n", 3);
}

void ft_pb(t_list **stacka, t_list **stackb)
{
    t_list *node;

    if (!stacka || !*stacka)
        return;
    node = *stacka;              // pega o topo de A
    *stacka = (*stacka)->next;   // avança A
    node->next = *stackb;        // liga no topo de B
    *stackb = node;              // agora B aponta para o novo topo
    write(1, "pb\n", 3);
}
