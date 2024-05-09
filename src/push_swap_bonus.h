/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:51:11 by emajuri           #+#    #+#             */
/*   Updated: 2023/02/17 17:15:27 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "push_swap.h"
#include <unistd.h>

typedef struct s_vec
{
    char    *operations;
    int        count;
    int        len;
}    t_vec;

enum e_operations
{
    BSA = 1,
    BSB = 2,
    BSS = 3,
    BPA = 4,
    BPB = 5,
    BRA = 6,
    BRB = 7,
    BRR = 8,
    BRRA = 9,
    BRRB = 10,
    BRRR = 11
};

void    bsa(t_vars *s_vars);
void    bsb(t_vars *s_vars);
void    bss(t_vars *s_vars);
void    bpa(t_vars *s_vars);
void    bpb(t_vars *s_vars);
void    bra(t_vars *s_vars);
void    brb(t_vars *s_vars);
void    brr(t_vars *s_vars);
void    brra(t_vars *s_vars);
void    brrb(t_vars *s_vars);
void    brrr(t_vars *s_vars);
void    create_stack_bonus(char **numbers, t_vars *s_vars);
void    exit_on_error(t_vars *s_vars, char *operations);
int        check_rotate(char *line);
int        check_operation(char *line);
void    add_operation(t_vars *s_vars, t_vec *vec, int operation);

#endif
