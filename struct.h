/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:23:03 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/21 18:10:19 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h> // clasico
#include <unistd.h> // write!
#include <stdlib.h> // malloc
#include <stdarg.h> // argc + argv
#include <limits.h> // ft_save_atoi


typedef struct s_list // nossa estrutura.
{
    void *data;
    struct s_list *next;
}t_list;


int ft_save_atoi(const char *str, int *out); // parcing principal + gerador de numeros
int ft_repeat_elem(t_list *begin, int value); // parcing

void ft_runlist(t_list *begin); // rrun list ! (testes)
t_list *add_elem(void *data, size_t size); // cria nodes
void ft_freelist(t_list **head); // liberta nodes e data
void ft_append(t_list **begin, void *data, size_t size); // adiciona novos elem
int ft_list_size(t_list *begin); // contagem de elem para saber qual sort usar!!!!.s

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
// fim dos comandos;

//sort
void ft_sort2(t_list **stacka);
void ft_sort3(t_list **stacka);
void ft_sort5(t_list **stacka, t_list **stackb);
#endif