#ifndef OP_STORE_H
# define OP_STORE_H

#include "libft.h"

#define TRUE 1
#define FALSE 0

typedef enum op
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
    RRR,
    END
} ops;

typedef struct s_operations
{
    ops *op;
    int opcount;
    struct s_operations *next;
}    operations;


operations *new_op_store();
_Bool add_op(operations *head, ops o);
_Bool add_wrap(operations *head, ops o);
void print_ops(operations *head);
_Bool optimize_ops(operations **head);
void free_ops(operations *head);

#endif