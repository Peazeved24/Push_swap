/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:07:17 by peazeved          #+#    #+#             */
/*   Updated: 2025/12/09 13:21:38 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void ft_freelist(t_list **head)
{
    t_list *node = *head;
    while(node)
    {
        t_list *tmp = node->next;
        free(node->data);
        free(node);
        node = tmp;
    }
    *head = NULL;
}

void ft_append(t_list **begin, void *data, size_t size)
{
    
    t_list *new = add_elem(data, size);
    if(!*begin)
    {
        *begin = new;
    }
    else
    {
        t_list *node = *begin;
        while(node->next) 
        {
            node = node->next;
        }
        node->next = new;
    }
}

int ft_list_size(t_list *begin) 
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

int ft_is_sorted(t_list *node)
{
    if(!node)
        return 0;
    while(node->next)
    {
        int val1 = *(int*)node->data;
        int val2 = *(int*)node->next->data;
        
        if(val1 > val2)
            return 0;
        node = node->next;  
    }
    return 1;
}