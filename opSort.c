#include "struct.h"

static int ft_cmp(void *d1, void *d2)
{
    return *(int*)d1 - *(int*)d2;
}

static void ft_shortbreak(t_list **stack, t_list *node, int size)
{
    int pos = 0;
    t_list *tmp = *stack;

    // Descobre a posição do nó
    while (tmp && tmp != node)
    {
        tmp = tmp->next;
        pos++;
    }

    // Escolhe rota mais curta
    if (pos <= size / 2)
        while (*stack != node)
            ft_ra(stack);
    else
        while (*stack != node)
            ft_rra(stack);
}

void ft_sort2(t_list **stacka)
{
    
    if(!stacka || !*stacka || !(*stacka)->next) // condicao principal
        return;
    
    t_list *node = *stacka;

    if(ft_cmp(node->data, node->next->data) < 0) //SORTED
        return;
    if(ft_cmp(node->data, node->next->data) > 0)
            ft_sa(stacka);
}

void ft_sort3(t_list **stacka) 
{
    if(!stacka || !*stacka || !(*stacka)->next || !(*stacka)->next->next)
        return;
    t_list *node;   
    int first;
    int second;
    int third;
    
    node = *stacka;
    first = *(int*)node->data;
    second = *(int*)node->next->data;
    third= *(int*)node->next->next->data;
    if(first < second && second < third)    
        return;
    else if(first > second && second < third && first > third) // 312
        ft_ra(stacka);
    else if(first < second && second > third && first > third) //231 x
        ft_rra(stacka);
    else if(first > second && second < third && third > first) //213
        ft_sa(stacka);
    else if(first > second && second > third) //321 x
        (ft_ra(stacka), ft_sa(stacka));
    else if(first < second && second > third && first < third) //132 x
        (ft_sa(stacka), ft_ra(stacka));
}

void ft_sort5(t_list **stacka, t_list **stackb) // pegar os 2 mais pequenos e dar sort aos 3 restantes.
{
    t_list *min;
    t_list *tmp; // meu proximo valor
    int i;
    int size;

    size = 0;
    i = 0;
    while(i++ < 2)
    {
        tmp = *stacka; // a cada chamada tmp pega o primeiro valor
        min = tmp;// o meu min e o meu valor atual
        size = 0;
        while(tmp) //enqaunto n chegar ao fim!
        {   
            if(*(int*)tmp->data < *(int*)min->data) // se for inferior 
                min = tmp; // meu valor inferior.
            tmp = tmp->next; // passa para o proximo.
            size++;
        }
        ft_shortbreak(stacka, min,size);
        ft_pb(stacka, stackb);
    }
    ft_sort3(stacka);
    ft_pa(stacka, stackb);
    ft_pa(stacka, stackb);
}   