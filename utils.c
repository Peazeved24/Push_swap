/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:42:19 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/24 14:52:57 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "struct.h"

int ft_save_atoi(const char *str, int *out) // GOD LIKE  algoritmo
{
    long long n = 0; 
    int s = 1;
    while(*str == ' ' || *str == '\t')
        str++;
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
            s = -1;
        str++;
    }
    if(!*str)
        return 0;
    while (*str)
    {
        if (*str < '0' || *str > '9') // caractere inválido
            return 0;
        n = n * 10 + (*str - '0');
        if ((n * s) > INT_MAX || (n * s) < INT_MIN)
            return 0; // overflow
        str++;
    }
    *out = (int)(n * s); // add to this pointer !
    return 1;
}
// atoi = assci - int
// parsing for non numeric
// overflow

void ft_runlist(t_list *begin) // run a lista (testes)
{
    t_list *node = begin;

    while(node)
    {
        printf("%i", *(int*)node->data);
        if(node->data)
            printf(" -> ");
        node = node->next;
    }
}

t_list *add_elem(void *data, size_t size) // add elem de forma dinamica
{
    size_t i = 0;
    t_list *node = malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node->data = malloc(size);
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

int ft_repeat_elem(t_list *begin, int value) //verifica se ha repeticoes.
{
    t_list  *node = begin;
    
    while(node)
    {
        if(*(int*)node->data == value)
            return 1;
        node= node->next;
    }
    return 0;
}