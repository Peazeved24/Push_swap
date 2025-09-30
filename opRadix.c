/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opRadix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:44:58 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/30 13:56:42 by peazeved         ###   ########.fr       */
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
                index++; //sempre que um digito for infeior a outro 
            j = j->next;
        }
        i->index = index;
        i = i->next;
    }
}

void ft_radixsort(t_list **stacka, t_list **stackb, int size) // 
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
            int num = (*stacka)->index; // pega índice do nó do topo
            if (((num >> i) & 1) == 0)
                ft_pb(stacka, stackb); // bit = 0 → manda para B
            else
                ft_ra(stacka);         // bit = 1 → rotaciona
            j++;
        }
        while (*stackb != NULL)
            ft_pa(stacka, stackb);     // devolve tudo para A
        i++;
    }
}
// analisa 3 coisas :
    // o lsd - ultimo digito (unidades)
        // analisa depois as casas decimais se n tiver marca com 0
        // por fim analisa as centenas !