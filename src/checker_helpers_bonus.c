/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:32:34 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/20 17:32:35 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    exit_on_error(t_vars *s_vars, char *operations)
{
    ft_printf_fd(2, "Error\n");
    free(s_vars->data);
    free(operations);
    exit(-1);
}

int    check_rotate(char *line)
{
    if (line[2] == '\n')
    {
        if (line[1] == 'a')
            return (BRA);
        if (line[1] == 'b')
            return (BRB);
        if (line[1] == 'r')
            return (BRR);
    }
    else if (line[3] == '\n')
    {
        if (line[1] == 'r' && line[2] == 'a')
            return (BRRA);
        if (line[1] == 'r' && line[2] == 'b')
            return (BRRB);
        if (line[1] == 'r' && line[2] == 'r')
            return (BRRR);
    }
    return (0);
}

int    check_operation(char *line)
{
    if (line[0] == 's')
    {
        if (line[1] == 'a' && line[2] == '\n')
            return (BSA);
        if (line[1] == 'b' && line[2] == '\n')
            return (BSB);
        if (line[1] == 's' && line[2] == '\n')
            return (BSS);
    }
    else if (line[0] == 'p')
    {
        if (line[1] == 'a' && line[2] == '\n')
            return (BPA);
        if (line[1] == 'b' && line[2] == '\n')
            return (BPB);
    }
    else if (line[0] == 'r')
        return (check_rotate(line));
    return (0);
}

void    add_operation(t_vars *s_vars, t_vec *vec, int operation)
{
    if (!vec->len)
        vec->len = 1;
    if (vec->len <= vec->count + 1)
    {
        vec->len *= 2;
        vec->operations = ft_realloc(vec->operations, \
                vec->len * sizeof(char), vec->count);
        if (!vec->operations)
            exit_on_error(s_vars, vec->operations);
    }
    vec->operations[vec->count] = operation;
    vec->count++;
}
