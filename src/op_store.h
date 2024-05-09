#ifndef OP_STORE_H
# define OP_STORE_H

#include "libft.h"

enum ops
{
    SA,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR
};

typedef struct s_operations
{
    char *op;
    int opcount;
    struct s_operations *next;
}    operations;


operations *new_op_store();
_Bool add_op(operations* head, enum ops);
_Bool add_wrap(operations* head, enum ops);
void print_ops(operations* head);

#endif