#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  *@brief Structure to keep template function pointers
  * A structure to keep template function pointers
  * in a future this pointers will be refer to a different functions.
  * Functions will be used for camparing and printing data from current node.
  * @code
  * int
  * char*
  * @endcode
  * types.
  */
struct function
{
    /*@{*/
    int (*is_equal)(void * p_data, void * p_data1);/**< compare type (char* or int)*/
    void (*print)(void * p_data);/**< printing node data (char* or int) */
    /*@}*/
};

struct function int_func, string_func;


/**
  *@brief A structure to keep template function pointers
  */

struct Node
{
    /**
     * @name Node data
     */
    /*@{*/
    void * data;/**< hold node data (char* or int) */
    /*@{*/

    /**
     * @name Functions
     */
    /*@{*/
    struct function * fun;/**< hold a specific functions */
    /*@{*/

    /**
     * @name Next and prev nodes
     * @details If current node is a head of list then prev node is equal to NULL,
     * and if current node is a tail then next node will be equal to NULL.
     */
    /*@{*/
    struct Node *next;/**< hold next node of current node */
    struct Node *prev;/**< hold prev node of current node */
    /*@{*/
};

/**
  *@brief A base list structure
  */


struct List
{
    /*@{*/
    struct Node * head;/**< head of list */
    struct Node * tail;/**< tail of list */
    /*@{*/
};


/*!
  Function will construct a list, set NULL in to next and prev node.
  This function should be used every time when new list was created.
  @param[in]  list    List to initializate
  */
void init(struct List * list);


/*!
  Appends the given element value to the end of the list.
  @param[in]  list         Actual list
  @param[in]  data         Value to set
  @param[in]  p_functions    Function to use
  */
void push_back(struct List * list, void * data, struct function * p_functions);


/*!
  Appends the given element value to the beginning of the list.
  @param[in]  list         Actual list
  @param[in]  data         Value to set
  @param[in]  p_functions    Function to use
  */
void push_front(struct List * list, void * data, struct function * p_functions);


/*!
  Print all elements of list.
  @param[in]  list         Actual list
  */
void print(struct List * list);


/*!
  Looking for needed node by value.
  @param[in]  list         Actual list
  @param[in]  data         Data for searching the node
  @param[in]  is_equal     Pointer to a function for comparing two types
  @return                  If node was found valid pointer will be returned, otherwise NULL will be returned
  */
struct Node * find_node(struct List * list, void * data,int (*is_equal)());


/*!
  Remove node by value
  @param[in]  list         Actual list
  @param[in]  data         Data for searching the node
  @param[in]  is_equal     Pointer to a function for comparing two types
  */
void remove_node(struct List * list, void * data,int (*is_equal)());


/*!
  Set new value in to already exist node
  @param[in]  list         Actual list
  @param[in]  find_data    Data for searching the node
  @param[in]  is_equal     Pointer in to the function for comparing two types
  @param[in]  new_data     New node data
  @param[in]  new_fun      New funcion for new data, some other type could be seted, this is a reason why new functions should be used
  */
void set_instead(struct List * list, void * find_data, int (*is_equal)(), void * new_data, struct function * new_p_functions);


/*!
  Set new node before
  @param[in]  list           Actual list
  @param[in]  before_data    The new node will be inserted before node with current data
  @param[in]  is_equal       Pointer to the function for comparing two types
  @param[in]  data           New node data
  @param[in]  fun            New funcion for new type, value some other type could be setted, this is a reason why new functions should be used
  */
void insert_before(struct List * list, void * before_data, int (*is_equal)(), void * data, struct function * new_p_functions);
