/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:07:17 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/24 14:56:05 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void ft_freelist(t_list **head) // free no fim !
{
    t_list *node = *head;
    while(node)
    {
        t_list *tmp = node->next;
        free(node->data);
        free(node);
        printf("#");
        node = tmp;
    }
    *head = NULL;
}

void ft_append(t_list **begin, void *data, size_t size) // gera elementos
{
    
    t_list *new = add_elem(data, size);
    if(!*begin)
    {
        *begin = new;
    }
    else
    {
        t_list *node = *begin;
        while(node->next) // 
        {
            node = node->next;
        }
        node->next = new;
    }
}

int ft_list_size(t_list *begin) //condicao de seguranca.
{
    int i;

    i = 0;
    while(begin)
    {
        begin =begin->next;
        i++;
    }
    return i;
}

int ft_is_sorted(t_list *node) // condicao para a stacka
{
    if(!node)
        return 1;
    while(node->next) // 
    {
        int val1 = *(int*)node->data; // primeiro elemot
        int val2 = *(int*)node->next->data; // proximo elemnto
        
        if(val1 > val2)
            return 1;
        node = node->next;  
    }
    write(1 ,"isSorted\n", 10);
    return 0; // esta fixe 
}