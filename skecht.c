/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skecht.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:26:55 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/02 16:00:06 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void free_list(t_list *begin)
{
    t_list *node = begin;

    while(node)
    {
        t_list *tmp = node->next;
        free(node->data);
        free(node);
        node = tmp;
    }
}

t_list *add_element(void* data, size_t size) // adicionar o iagezimo elemento
{
    size_t i = 0;
    t_list *node = malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node->data = malloc((size));
    if(!node->data)
        return NULL;
    while(i < size)
    {
        ((char*)node->data)[i] = ((char*)data)[i];
        i++;
    }
    node->next = NULL;
    return node;
}

void ft_append(t_list **begin, void *data, size_t size) // adicona UM NOVO ELEM no fim
{
    t_list *new = add_element(data, size);
    
    if(!*begin)
    {
        *begin = new;
    }
    else
    {
        t_list *tmp = *begin;
        while(tmp->next)
        {
            tmp = tmp->next; // vamos ate ao fim.
        }
        tmp->next = new;
    }
        
}

void run_list(t_list *begin) // algo que corre a lista.
{
    t_list *node;

    node = begin;

    while(node)
    {
        printf("%i", *(int*)node->data);
        if(node->next)
            printf(" -> ");
        node = node->next;
    } 
    printf("\n");
}

int ft_atoi(char *str) // converter os meus argumentos em int
{
    int n = 0;
    int s = 1;

    while(*str == ' ' || *str == '\t')
        str++;
    if (*str == '+' || *str == '-')  // lê sinais
    {
        if (*str == '-')
            s = -s;
        str++;
    }
    while(*str >= '0' && *str <= '9')
        n = n * 10 + (*str++ - '0');
    return n * s;
}
