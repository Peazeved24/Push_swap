#include "struct.h"

static void ft_shortbreak(t_list **stack, t_list *node, int size) // para encontrar a posicao do node.
{
    int pos = 0; // index
    t_list *tmp = *stack; // tmp !-- primeiro valor.

    // Descobre a posição do nó
    while (tmp && tmp != node) // a b c e 
    {
        tmp = tmp->next; // vai alterando (i++ == listas)
        pos++;
    }
     // Escolhe rota mais curta
    if (pos <= size / 2)
        while (*stack != node) 
            ft_ra(stack); // ra -- o meu primeiro passa para ultimo
    else
        while (*stack != node)
            ft_rra(stack); // ultimo passa para o inicio.
}

void ft_sort2(t_list **stacka) // corrigido !! sem a cmp para ter mais espaco!!
{
    
    if(!stacka || ft_list_size(*stacka) < 2) // condicao principal
        return;
    if(ft_is_sorted(*stacka) == 0)
        return;
    t_list *node;
    node = *stacka;
    if(*(int*)node->data > *(int*)node->next->data) //caso n for
            ft_sa(stacka);
}

void ft_sort3(t_list **stacka, t_list **stackb)
{
    if(!stacka || ft_list_size(*stacka) < 2)
        return;
    if(ft_is_sorted(*stacka) == 0)
        return;
    t_list *node;
    t_list *max;

    max = *stacka;
    node = *stacka;
    while(node)
    {
        if(*(int*)max->data > *(int*)node->data)
            max = node;
        node = node->next;
    }
    ft_shortbreak(stacka, max, ft_list_size(*stacka));
    ft_pb(stacka, stackb);
    ft_sort2(stacka);
    ft_pa(stacka, stackb);
}

void ft_sort4(t_list **stacka, t_list **stackb)
{
    if(!stacka || ft_list_size(*stacka) < 4) // nul ou n tem o numero de elem.
        return;
    if(ft_is_sorted(*stacka) == 0) // ja esta sorted
        return;
    t_list *tmp = *stacka; // refernecia
    t_list *max = *stacka; // valores max
    
    while(tmp) // percorre a lista a procura do mair valor!
    {
        if(*(int*)max->data > *(int*)tmp->data)
            max = tmp; // meu novo valor maximo.
        tmp = tmp->next; // atualiza a lista.
    }
    ft_shortbreak(stacka, max, ft_list_size(*stacka));
    ft_pb(stacka, stackb);
    ft_sort3(stacka, stackb);
    ft_pa(stacka, stackb);
}

void ft_sort5(t_list **stacka, t_list **stackb) // pegar os 2 mais pequenos e dar sort aos 3 restantes.
{
    if(!stacka || ft_list_size(*stacka) < 5) // condicao principal
        return;
    if(ft_is_sorted(*stacka) == 0)
        return;
    t_list *min;
    t_list *tmp; // meu proximo valor
    int i;

    i = 0;
    while(i++ < 2) // 2 voltas -- atras de 2 numeros
    {
        tmp = *stacka; // a cada chamada tmp pega o primeiro valor
        min = tmp;// o meu min e o meu valor atual
        while(tmp) //enqaunto n chegar ao fim!
        {   
            if(*(int*)tmp->data < *(int*)min->data) // se for inferior 
                min = tmp; // meu valor inferior.
            tmp = tmp->next; // passa para o proximo.
        }
        ft_shortbreak(stacka, min,ft_list_size(*stacka));
        ft_pb(stacka, stackb); // passar os valores inferiores para o meu b!!
    }
    ft_sort3(stacka, stackb); /// os resntantes 3 --sort3
    ft_pa(stacka, stackb); // pega os meus 2 min e coloca em a
    ft_pa(stacka, stackb);
}