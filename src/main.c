/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:49:07 by emajuri           #+#    #+#             */
/*   Updated: 2024/04/12 18:40:00 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    get_next(int *ptr, int nb)
{
    int    i;

    i = 0;
    while (ptr[i] != nb)
        i++;
    return (i - 1);
}

int    is_sorted(int *ptr, int size, char stack)
{
    int    i;

    i = 0;
    if (stack == 'a')
    {
        while (i < size - 1)
        {
            if (ptr[i] > ptr[i + 1])
            {
                return (0);
            }
            i++;
        }
    }
    if (stack == 'b')
    {
        while (i < size - 1)
        {
            if (ptr[i] < ptr[i + 1])
                return (0);
            i++;
        }
    }
    return (1);
}

int    do_median(t_vars *s_vars, int nb)
{
    int    i;

    i = 0;
    while (i < s_vars->size_median)
    {
        if (s_vars->median[i] > nb)
        {
            push_nb_on_top(&(s_vars->median[i]), nb, s_vars->size_median - i);
            s_vars->size_median++;
            return (0);
        }
        i++;
    }
    s_vars->median[i] = nb;
    s_vars->size_median++;
    return (0);
}

void    create_median(t_vars *s_vars, int *ptr, int size)
{
    int    i;

    i = 0;
    s_vars->size_median = 0;
    while (i < size)
        do_median(s_vars, ptr[i++]);
}

int    main(int argc, char **argv)
{
    t_vars    s_vars;
    int storage_size;

    if (argc < 2)
        return (0);
    ft_bzero(&s_vars, sizeof(t_vars));
    if (argc == 2)
    {
        s_vars.numbers = ft_split_one_malloc(argv[1], ' ');
        create_stack(s_vars.numbers, &s_vars);
        free(s_vars.numbers);
        s_vars.numbers = NULL;
    }
    else
        create_stack(argv + 1, &s_vars);
    s_vars.ops_head = new_op_store();
    if (!s_vars.ops_head)
        error_exit(&s_vars);
    while (s_vars.size_a > 120)
        partitions_size(&s_vars, 60);
    while (s_vars.size_a > 3)
        partitions_half(&s_vars);
    sort_a(&s_vars);
    storage_size = sort_stack_b(&s_vars);
    push_all(&s_vars, storage_size);
    optimize_ops(&s_vars.ops_head);
    if (s_vars.ops_head)
        print_ops(s_vars.ops_head);
    free_ops(s_vars.ops_head);
    free(s_vars.data);
    return (0);
}
