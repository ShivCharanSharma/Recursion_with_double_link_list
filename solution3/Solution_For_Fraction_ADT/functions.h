#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>
#include "a.h"
typedef Fraction value_t;
typedef double key_lt;
#include "sorted_list.h"
#define INSERTED_ORDER 1
#define SORTED_ORDER 2

/* function description
 * filter the values using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t) test function pointer
 * @return Sorted_list pointer of new link list with filtered values.
 */
Sorted_list * filter( Sorted_list * old_list_detail, int  (*f)(value_t));

/* function description
 * map the values using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t) function pointer
 * @return Sorted_list pointer of new link list.
 */
Sorted_list * map( Sorted_list * old_list_detail, value_t (*f)(value_t));

/* function description
 * reduce the values of link list using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t)(value_t) function pointer
 * @param value_t init
 * @param int order specify order while reducing 
 * @return value_t single value after reduce
 */

value_t reduce( Sorted_list * list_detail, value_t (*f)(value_t,value_t),value_t init,int order);

/* function description
 * first applying map, and then reduce using function pointers for both
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*map_fn)(value_t) function pointer for map
 * @param value_t (*reduce_fn)(value_t)(value_t) function pointer for reduce
 * @param value_t init
 * @param int order specify order while reducing
 * @return value_t return single value.
 */

value_t map_reduce( Sorted_list * list_detail, value_t (*map_fn)(value_t), value_t (*reduce_fn)(value_t,value_t),value_t init,int order);
 
/* function description
 * first applying map, and then reduce using function pointers for both
 * @param Sorted_list * first Sorted_list pointer 
 * @param Sorted_list * second Sorted_list pointer
 * @param value_t (*map_fn)(value_t) function pointer for map
 * @param int order specify order while reducing
 * @return value_t * return array of value_t.
 */

value_t * map_2_array( Sorted_list * list1,Sorted_list * list2, value_t (*map_fn)(value_t,value_t),int order);
/* function description
 * first applying map, and then reduce using function pointers for both
 * @param Sorted_list * first Sorted_list pointer
 * @param Sorted_list * second Sorted_list pointer
 * @param value_t (*map_fn)(value_t) function pointer for map
 * @param value_t (*reduce_fn)(value_t)(value_t) function pointer for reduce
 * @param value_t init
 * @param int order specify order while reducing
 * @return value_t return single value.
 */

value_t  map_2_reduce( Sorted_list * list1,Sorted_list * list2, value_t (*map_fn)(value_t,value_t),value_t (*reduce_fn)(value_t,value_t),value_t init,int order);

//need to remove add2 fn after all completion
value_t add2(value_t x);
/* function description
 * function to add 2 numbers (used to pass as function pointer)
 * @param value_t first number
 * @param value_t second number
 * @return value_t return sum of numbers.
 */

value_t add_2_number(value_t x,value_t y);
/* function description
 * function to subtract 2 numbers (used to pass as function pointer)
 * @param value_t first number
 * @param value_t second number
 * @return value_t return diffrence of numbers.
 */

value_t subtract_2_number(value_t x,value_t y);

/* function description
 * function to square a number used to pass as function pointer
 * @param value_t  number
 * @return value_t return square of number.
 */

value_t square_Of_A_Number(value_t x);
/* function description
 * function to square second argument then add square to first argument used to pass as function pointer
 * @param value_t first number
 * @param value_t second number
 * @return value_t return sum of number after square of second argument.
 */

value_t square_and_add_number(value_t x,value_t y);


value_t sum(Sorted_list * list,int order);

/* function description
 * print array
 * @param value_t * arr arr to print
 * @param int size size of array
 * @return void.
 */

void print_array(value_t * arr, int size);

/* function description
 *takes two sorted lists of the same size, returns NULL if the sizes are different
 *produces an array whose values are the differences of the values in the sorted lists args
 *third argument that can be set to SORTED_ORDER or INSERTED_ORDER 
 *in order to follow the appropriate links.
 * @param Sorted_list * list1 
 * @param Sorted_list * list2
 * @param int order
 * @return value_t * pointer to array of diffrence.
 */

value_t * diff (Sorted_list * list1,Sorted_list *list2, int order);

/* function description
 * takes a sorted list and produces a new sorted list whose value at a node equals 
 * the original value (not key) squared
 * @param Sorted_list * list
 * @return Sorted_list * return pointer to new Sorted_list
 */


Sorted_list * square(Sorted_list *list);



/* function description
 * takes two sorted lists of the same size
 *returns NULL if the sizes are different produces a value computed as follows:
 * 1. at each node position, take the difference between the values
 * 2. square the resulting difference
 * 3. sum across all nodes into a single result
 * third argument that can be set to SORTED_ORDER or INSERTED_ORDER
 * in order to follow the appropriate links
 * @param Sorted_list * list1
 * @param Sorted_list * list2
 * @param int order
 * @return void * because we need to return NULL if size of link lists is different .
 */
void * sum_of_sq_diff(Sorted_list *list1,Sorted_list* list2,int order);
void printList_square(Sorted_list * list_detail);

#endif
