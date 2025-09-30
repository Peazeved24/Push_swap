/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peazeved <peazeved@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:36:59 by peazeved          #+#    #+#             */
/*   Updated: 2025/09/30 14:55:47 by peazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void ft_picksort(t_list **stacka, t_list **stackb, int size)
{
    if(ft_is_sorted(*stacka)) // ja esta sorted
        return;
    if(size <= 5)
    {
        if(size == 2)
            ft_sort2(stacka);
        else if(size == 3)
            ft_sort3(stacka);
        else if(size == 4)
            ft_sort4(stacka, stackb);   
        else if(size == 5)
            ft_sort5(stacka, stackb); 
    }
    else
    {
        ft_index(*stacka);
        ft_radixsort(stacka, stackb, ft_list_size(*stacka));
    }
}

int main(int ac, char **av)
{
    int i = 1;
    t_list *stacka = NULL;
    t_list *stackb = NULL;
    int val;

    if(ac <= 2)
        return 0; 
    while(i < ac) // processamento de dados!
    {

        if(!ft_save_atoi(av[i], &val)) // 3 coisas - gera numeros, verifica os meus chars e ve overflows
            return 1;
        if(ft_repeat_elem(stacka, val))
            return 1;
        ft_append(&stacka, &val, sizeof(int)); // apos a validacao - cria!
        i++; 
    }
    ft_picksort(&stacka, &stackb , ft_list_size(stacka));
    ft_freelist(&stacka);
    ft_freelist(&stackb);
    return 0;
} 