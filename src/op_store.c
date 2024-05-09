#include "op_store.h"

void free_ops(operations *head)
{
    operations *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->op);
        free(tmp);
    }
}

operations *new_op_store()
{
    operations *tmp;

    tmp = ft_calloc(sizeof(operations), 1);
    if (!tmp)
        return NULL;
    tmp->op = ft_calloc(sizeof(ops), 1000);
    if (tmp->op)
        return tmp;
    free(tmp);
    return NULL;
}

_Bool add_op(operations *head, ops o)
{
    while (head->opcount == 1000 && head->next)
        head = head->next;
    if (head->opcount == 1000)
    {
        head->next = new_op_store();
        if (!head->next)
            return FALSE;
        head->next->op[0] = o;
        head->next->opcount++;
    }
    else
    {
        head->op[head->opcount++] = o;
    }
    return TRUE;
}

_Bool add_wrap(operations *head, ops o)
{
    if (!add_op(head, o))
    {
        free_ops(head);
        return FALSE;
    }
    return TRUE;
}

void print_ops(operations *head)
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
            ft_printf("%s\n", op_names[head->op[i]]);
        head = head->next;
    }
}

static _Bool check_set(ops *set, operations *head, int index)
{
    for (int i = 0; set[i] != END; i++)
    {
        if (index >= head->opcount)
        {
            head = head->next;
            if (!head)
                return FALSE;
            index = 0;
        }
        if (head->op[index] != set[i])
            return FALSE;
        index++;
    }
    return TRUE;
}

static int check_sets(operations *head, int index, ops *sets[])
{
    for (int i = 0; sets[i][0] != END; i++)
    {
        if (check_set(sets[i], head, index))
        {
            return i;
        }
    }
    return -1;
}

_Bool copy_shortened(operations *new_ops, int set_num)
{
    ops *shortened[] = {
        (ops[]){SS, END},
        (ops[]){SS, END},
        (ops[]){RR, END},
        (ops[]){RR, END},
        (ops[]){RRR, END},
        (ops[]){RRR, END},
        (ops[]){END},
    };
    int i = 0;
    for (; shortened[set_num][i] != END; i++)
    {
        if (!add_op(new_ops, shortened[set_num][i]))
        {
            return FALSE;
        }
    }
    return TRUE;
}

void advance(operations **head, int *i, ops *set)
{
    int len = 0;
    while (set[len] != END)
        len++;
    (*i) += len - 1;
    if (*i >= (*head)->opcount)
    {
        (*i) -= (*head)->opcount;
        (*head) = (*head)->next;
    }
}

_Bool optimize_ops(operations **head_p)
{
    ops *sets[] = {
        (ops[]){SA, SB, END},
        (ops[]){SB, SA, END},
        (ops[]){RA, RB, END},
        (ops[]){RB, RA, END},
        (ops[]){RRA, RRB, END},
        (ops[]){RRB, RRA, END},
        (ops[]){END},
    };

    operations *head = *head_p;
    operations *new_ops;
    new_ops = new_op_store();
    if (!new_ops)
    {
        free_ops(head);
        return FALSE;
    }
    operations *save_new = new_ops;
    while (head)
    {
        for (int i = 0; head && i < head->opcount; i++)
        {
            int set_num = check_sets(head, i, sets);
            if (set_num == -1)
            {
                if (!add_op(new_ops, head->op[i]))
                {
                    free_ops(save_new);
                    free_ops(*head_p);
                    *head_p = NULL;
                    return FALSE;
                }
            }
            else
            {
                if (!copy_shortened(new_ops, set_num))
                {
                    free_ops(save_new);
                    free_ops(*head_p);
                    *head_p = NULL;
                    return FALSE;
                }
                advance(&head, &i, sets[set_num]);
            }
        }
        if (head)
            head = head->next;
    }
    free_ops(*head_p);
    (*head_p) = save_new;
    return TRUE;
}