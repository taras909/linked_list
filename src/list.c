#include "list.h"


// List of template funtions *********************************************
static void print_int( void * p_data)
{
    printf("%d\n",(int)p_data);
}


static void print_string(void * p_data)
{
    printf("%s\n",(char*)p_data);
}


static int compare_int(void * a, void * b)
{
    return (int*)a == (int*)b;
}


static int comare_string(void * a, void * b)
{
    return !strcmp((char*)a, (char*)b);
}
// End of template functions definitions *********************************************

void init(struct List * list)
{
    list->head = NULL;
    list->tail = NULL;

    int_func.is_equal = &compare_int;
    int_func.print = &print_int;

    string_func.is_equal = &comare_string;
    string_func.print = &print_string;
}


void push_back(struct List * list, void * data, struct function * p_functions )
{
    struct List * current_list = list;
    if(!current_list->head)
    {
//        if current list->head is equal to NULL, than set the first element to node
        current_list->head = malloc(sizeof(struct Node));
        current_list->head->data = data;
        current_list->head->fun = p_functions;
        current_list->head->prev = NULL;
        current_list->head->next = NULL;
    }
    else
    {
        struct Node * current_node = list->head;
        while(current_node->next)
        {
//             looking for the end of list
            current_node = current_node->next;
        }

        current_node->next = malloc(sizeof(struct Node));
        current_node->next->data = data;
        current_node->next->fun = p_functions;
        current_node->next->next = NULL;
        current_node->next->prev = current_node;
        list->tail = current_node->next;
    }
}


void push_front(struct List * list, void * data, struct function * p_functions )
{
    struct List * current_list = list;
    if(!current_list->tail)
    {
        current_list->tail = malloc(sizeof(struct Node));
        current_list->tail->data = data;
        current_list->tail->fun = p_functions;
        current_list->tail->prev = NULL;
        current_list->tail->next = NULL;
    }
    else
    {
        struct Node * current_node = list->tail;
        while(current_node->prev)
        {
            current_node = current_node->prev;
        }

        current_node->prev = malloc(sizeof(struct Node));
        current_node->prev->data = data;
        current_node->prev->fun = p_functions;
        current_node->prev->prev = NULL;
        current_node->prev->next= current_node;
        list->head = current_node->prev;
    }
}


void print(struct List * list)
{
    struct Node * current = list->head;
    while(current)
    {
        current->fun->print(current->data);
        if(current->next)
            current = current->next;
        else
            break;
    }
    printf("********************************************************\n");
}


struct Node * find_node(struct List * list, void * data,int (*is_equal)() )
{
     struct Node * current = list->head;
     while(current)
     {
//   if node use a required function for comparing then proceed and try to compare, otherwise move to the next node
         if(current->fun->is_equal == is_equal)
         {
             if(current->fun->is_equal(current->data,data))
                 return current;
         }
         if(current->next)
             current = current->next;
         else
             break;
     }
     return NULL;
}


void remove_node(struct List * list, void * data,int (*is_equal)() )
{
    struct Node * current = list->head;
    while(current)
    {
        if(current->fun->is_equal == is_equal)
        {
            if(current->fun->is_equal(current->data,data))
            {
                if(!current->next && !current->prev)
                {
                    free(list->head);
                    list->head = NULL;
                    break;
                }
                else
                if(!current->next) // need to remove tail node
                {
                    list->tail = current->prev;
                    list->tail->next = NULL;
                    free(current);
                    current = NULL;
                    break;
                }
                else
                {
                    if(!current->prev) // need to remove head node
                    {
                        list->head = current->next;
                        list->head->prev = NULL;
                        free(current);
                        current = NULL;
                        break;
                    }
                    else // remove some middle node
                    {
                        struct Node * temp = current;
                        current->next->prev = current->prev;
                        current->prev->next = temp->next;
                        free(current);
                        current = NULL;
                        break;
                    }
                }
            }
        }
        if(current->next)
            current = current->next;
        else
            break;
    }
}


void set_instead(struct List * list, void * find_data, int (*is_equal)(), void * new_data, struct function * new_p_functions )
{
    // get node, if node was not found than current Node will be equal to NULL
    struct Node * current = find_node(list,find_data,is_equal);

    if(current)
    {
        current->data = new_data;
        current->fun = new_p_functions;
    }
}


void insert_before(struct List * list, void * before_data, int (*is_equal)(), void * data, struct function * new_p_functions)
{
    struct Node * current = find_node(list,before_data,is_equal);

    if(current)
    {
        if(!current->prev) // is a head of list
        {
            current->prev = malloc(sizeof(struct Node));
            current->prev->data = data;
            current->prev->fun = new_p_functions;
            current->prev->prev = NULL;
            current->prev->next = current;
            list->head = current->prev;
        }
        else
        {
            struct Node * new_node = malloc(sizeof(struct Node));
            new_node->data = data;
            new_node->fun = new_p_functions;
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
}
