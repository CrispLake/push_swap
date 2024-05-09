/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:56:17 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 15:51:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_exit(t_vars *s_vars)
{
    ft_printf_fd(2, "Error\n");
    free(s_vars->numbers);
    free(s_vars->data);
    exit(-1);
}

int    check_number(t_vars *s_vars, char *nb)
{
    int    i;
    int    len;

    i = 0;
    if (nb[i] == '-')
        i++;
    while (nb[i])
        if (!ft_isdigit(nb[i++]))
            return (-1);
    i = 0;
    if (nb[i] == '-')
        len = ft_strlen(nb + 1);
    else
        len = ft_strlen(nb);
    if (!len)
        error_exit(s_vars);
    if (len < 10)
        return (0);
    else if (len > 10)
        return (-1);
    if (nb[i] == '-' && (ft_strncmp(nb + 1, "2147483648", 10) > 0))
        return (-1);
    else if (ft_strncmp(nb, "2147483647", 10) > 0)
        return (-1);
    return (0);
}

int    check_duplicate_n_sort(t_vars *s_vars, int nb)
{
    int    i;

    i = 0;
    while (i < s_vars->size_sorted)
    {
        if (s_vars->sorted[i] == nb)
            return (-1);
        if (s_vars->sorted[i] > nb)
        {
            push_nb_on_top(&(s_vars->sorted[i]), nb, s_vars->size_sorted - i);
            s_vars->size_sorted++;
            return (0);
        }
        i++;
    }
    s_vars->sorted[i] = nb;
    s_vars->size_sorted++;
    return (0);
}

void    check_sorted(int *ptr, int *ptr2, int size, t_vars *s_vars)
{
    int    i;

    i = 0;
    while (i < size)
    {
        if (ptr[i] == ptr2[i])
            i++;
        else
            return ;
    }
    free(s_vars->data);
    free(s_vars->numbers);
    exit(-1);
}

void    create_stack(char **numbers, t_vars *s_vars)
{
    int    len;
    int    i;

    len = 0;
    i = 0;
    while (numbers[len] != NULL)
        len++;
    s_vars->data = ft_calloc(len * 4, sizeof(int));
    if (!s_vars->data)
        error_exit(s_vars);
    s_vars->a = s_vars->data;
    s_vars->b = s_vars->data + len;
    s_vars->sorted = s_vars->data + len * 2;
    s_vars->median = s_vars->data + len * 3;
    while (i < len)
    {
        if (check_number(s_vars, numbers[i]))
            error_exit(s_vars);
        s_vars->a[i] = ft_atoi(numbers[i]);
        s_vars->size_a++;
        if (check_duplicate_n_sort(s_vars, s_vars->a[i]))
            error_exit(s_vars);
        i++;
    }
    check_sorted(s_vars->a, s_vars->sorted, s_vars->size_a, s_vars);
}
