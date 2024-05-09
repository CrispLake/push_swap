#include "op_store.h"

operations *new_op_store()
{
    operations *tmp;

    tmp = ft_calloc(sizeof(operations), 1);
    if (!tmp)
        return NULL;
    tmp->op = ft_calloc(sizeof(char), 1000);
    if (tmp->op)
        return tmp;
    free(tmp);
    return NULL;
}

_Bool add_op(operations* head, enum ops o)
{
    while (head->opcount == 1000 && head->next)
        head = head->next;
    if (head->opcount == 1000)
    {
        head->next = new_op_store();
        if (!head->next)
            return 0;
        head->next->op[0] = o;
        head->next->opcount++;
    }
    else
    {
        head->op[head->opcount++] = o;
    }
    return 1;
}

_Bool add_wrap(operations* head, enum ops o)
{
    operations *tmp;

    if (!add_op(head, o))
    {
        while (head)
        {
            tmp = head;
            head = head->next;
            free(tmp->op);
            free(tmp);
            return 0;
        }
    }
    return 1;
}

void print_ops(operations* head)
{
    char *op_names[] = {
    "sa",
    "sb",
    "ss",
    "pa",
    "pb",
    "ra",
    "rb",
    "rr",
    "rra",
    "rrb",
    "rrr" };

    while (head)
    {
        for (int i = 0; i < head->opcount; i++)
            ft_printf("%s\n", op_names[(int)head->op[i]]);
        head = head->next;
    }
}