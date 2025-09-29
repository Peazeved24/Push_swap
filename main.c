/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:36:59 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/29 14:15:48 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int main(int ac, char **av)
{
    int i = 1;
    t_list *stacka = NULL;
    t_list *stackb = NULL;
    int val;

    if(ac <= 2)
    {
        printf("erro1");
        return 0; 
    }
    while(i < ac) // processamento de dados!
    {

        if(!ft_save_atoi(av[i], &val)) // 3 coisas - gera numeros, verifica os meus chars e ve overflows
        { 
            printf("error2");
            return 1;
        }
        if(ft_repeat_elem(stacka, val))
        {
            printf("error3");
            return 1;
        }
        ft_append(&stacka, &val, sizeof(int)); // apos a validacao - cria!
        i++; 
    }
    if(ft_list_size(stacka) <= 5)
    {
        if(ft_list_size(stacka) == 2)
        {
            ft_runlist(stacka);
            printf("\n");
            ft_sort2(&stacka);
            printf("\n");
            ft_runlist(stacka);
        }
        else if(ft_list_size(stacka) == 3)
        {
            ft_runlist(stacka);
            printf("\n");
            ft_sort3(&stacka);
            printf("\n");
            ft_runlist(stacka);
        }
        else if(ft_list_size(stacka) <= 5)
        {
            ft_runlist(stacka);
            printf("\n");
            ft_sort5(&stacka, &stackb);
            printf("\n");
            ft_runlist(stacka);   
        }
    }
    else
    {
        ft_runlist(stacka);
        printf("\n");
        ft_index(stacka);
        ft_radixsort(&stacka, &stackb, ft_list_size(stacka));
        printf("\n");
        ft_runlist(stacka);
        
    }
    printf("\n");
    ft_freelist(&stacka);
    ft_freelist(&stackb);
    printf("\n");
    return 0;
} 
