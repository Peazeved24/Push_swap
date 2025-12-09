/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:23:03 by peazeved          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:53 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <limits.h> 


typedef struct s_list 
{
    void *data;
    struct s_list *next;
    int index;
}t_list;

//srcs
int ft_save_atoi(const char *str, int *out);
int ft_repeat_elem(t_list *begin, int value);
t_list *add_elem(void *data, size_t size);
void ft_append(t_list **begin, void *data, size_t size); 
void ft_freelist(t_list **head); 
int ft_list_size(t_list *begin);
void ft_runlist(t_list *begin); 
int ft_is_sorted(t_list *node); 

//COMANDOS
void ft_pa(t_list **stacka, t_list **stackb);
void ft_pb(t_list ** stacka, t_list **stackb);
void ft_ra(t_list **stacka);
void ft_rb(t_list **stackb);
void ft_rr(t_list **stacka, t_list **stackb);
void ft_sa(t_list **stacka);
void ft_sb(t_list **stackb);
void ft_ss(t_list **stacka, t_list **stackb);
void ft_rra(t_list **stacka);
void ft_rrb(t_list **stackb);
void ft_rrr(t_list **stacka, t_list **stackb);

//sort
void ft_sort2(t_list **stacka);
void ft_sort3(t_list **stacka);
void ft_sort4(t_list **stacka, t_list **stackb); 
void ft_sort5(t_list **stacka, t_list **stackb);
void ft_radixsort(t_list **stacka, t_list **stackb, int size);
void ft_index(t_list *node);

#endif