#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>

typedef int value_t;
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
Sorted_list * filter( Sorted_list * old_list_detail, int  (*f)(value_t)){
	Sorted_list * temp= (Sorted_list *)malloc(sizeof(Sorted_list));

	Sorted_list * new_list;
	temp->head=old_list_detail->head;

        if(temp->head == NULL){
		 new_list=(Sorted_list *)malloc(sizeof(Sorted_list));
		return new_list;
	}
	else{
		temp->head=temp->head->next;
		new_list= filter(temp,*f);
	}


	struct Node* node=old_list_detail->head;
	if((*f)(node->value))
	{
			append(new_list,node->value,node->key);		
	}
	free(temp);
	return new_list;


}


/* function description
 * map the values using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t) function pointer
 * @return Sorted_list pointer of new link list.
 */
Sorted_list * map( Sorted_list * old_list_detail, value_t (*f)(value_t)){
	Sorted_list * new_list= (Sorted_list *)malloc(sizeof(Sorted_list));
	struct Node* old_node;

	//new_list->size=old_list_detail->size;
	old_node = old_list_detail->head;
        //printf("print_all:  Insertion Order \n");
    	while (old_node != NULL) {
        
		//struct Node * new_node=(Node*)malloc(sizeof(struct Node));
		//	printf("     %d  %d\n", node->key, node->value);
		value_t value;
		value=(*f)(old_node->value);
		append(new_list,value,old_node->key);
        	old_node = old_node->next;

		
    	}
	return new_list;
	

}

/* function description
 * reduce the values of link list using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t)(value_t) function pointer
 * @param value_t init
 * @param int order specify order while reducing 
 * @return value_t single value after reduce
 */

value_t reduce( Sorted_list * list_detail, value_t (*f)(value_t,value_t),value_t init,int order){
        struct Node* node;
	value_t value = init;
	if(order == INSERTED_ORDER){
        	node = list_detail->head;
        	while (node != NULL) {
    
                	value=(*f)(value,node->value);
                	node = node->next;
        	}
        	return value;
	}
	else if(order ==SORTED_ORDER)
	{      node = list_detail->head_sort;
                while (node != NULL) {

                        value=(*f)(value,node->value);
                        node = node->sort;
                }
                return value;
	}   
	return 1; //to avoid warning NOTE: function execution will not reach here.
}

/* function description
 * first applying map, and then reduce using function pointers for both
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*map_fn)(value_t) function pointer for map
 * @param value_t (*reduce_fn)(value_t)(value_t) function pointer for reduce
 * @param value_t init
 * @param int order specify order while reducing
 * @return value_t return single value.
 */

value_t map_reduce( Sorted_list * list_detail, value_t (*map_fn)(value_t), value_t (*reduce_fn)(value_t,value_t),value_t init,int order){
        struct Node* node;
        value_t value = init;
        if(order == INSERTED_ORDER){
                node = list_detail->head;
                while (node != NULL) {
			value_t tempvalue;
    			tempvalue=(*map_fn)(node->value);
                        value=(*reduce_fn)(value,tempvalue);
                        node = node->next;
                }
                return value;
        }
        else if(order ==SORTED_ORDER)
        {      node = list_detail->head_sort;
                while (node != NULL) {
			value_t tempvalue;
                        tempvalue=(*map_fn)(node->value);
                        value=(*reduce_fn)(value,tempvalue);
                        node = node->sort;
                }
                return value;
        }
	return 1; //to avoid warning NOTE: function execution will not reach here.
}
/* function description
 * first applying map, and then reduce using function pointers for both
 * @param Sorted_list * first Sorted_list pointer 
 * @param Sorted_list * second Sorted_list pointer
 * @param value_t (*map_fn)(value_t) function pointer for map
 * @param int order specify order while reducing
 * @return value_t * return array of value_t.
 */

value_t * map_2_array( Sorted_list * list1,Sorted_list * list2, value_t (*map_fn)(value_t,value_t),int order){
        if(list2->size != list1->size)
		return NULL;

	struct Node* node1,*node2;
	value_t value ;
 value_t * array=(value_t*)malloc(sizeof(value_t)*list1->size);
	if(order == INSERTED_ORDER){
        	node1 = list1->head;
		node2= list2->head;
		
        	while (node1 != NULL && node2 != NULL) {
    
                	value=(*map_fn)(node1->value,node2->value);
                	//array[counter]=value;
			
                	*array=value;
			//counter++;
			array++;
			node1 = node1->next;
			node2= node2->next;
        	}
	     	return --array;
	}
	else if(order ==SORTED_ORDER)
	{      node1 = list1->head_sort;
	      node2 = list2->head_sort;
                while (node1 != NULL && node2 != NULL) {

                        
                        value=(*map_fn)(node1->value,node2->value);
			//array[counter]=value;
			
                	*array=value;
			array++;
			//counter++;
                        node1 = node1->sort;
                        node2 = node2->sort;
                }
                return --array;
	}   
	return NULL; //to avoid warning NOTE: function execution will not reach here.
}

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

value_t  map_2_reduce( Sorted_list * list1,Sorted_list * list2, value_t (*map_fn)(value_t,value_t),value_t (*reduce_fn)(value_t,value_t),value_t init,int order){


       	struct Node* node1,*node2;
        value_t value = init;
        if(order == INSERTED_ORDER){
                node1 = list1->head;
		node2= list2->head;

                while (node1 != NULL && node2 != NULL) {
			value_t tempvalue;
                        tempvalue=(*map_fn)(node1->value,node2->value);
                        value=(*reduce_fn)(value,tempvalue);
                        node1 = node1->next;

                        node2 = node2->next;
                }
                return value;
        }
        else if(order ==SORTED_ORDER)
        {
                node1 = list1->head;
		node2= list2->head;

                while (node1 != NULL && node2 != NULL) {
			value_t tempvalue;
                        tempvalue=(*map_fn)(node1->value,node2->value);
                        value=(*reduce_fn)(value,tempvalue);
                        node1 = node1->next;

                        node2 = node2->next;
                }
		return value; 
        }
	return 1; //to avoid warning NOTE: function execution will not reach here.
}
//need to remove add2 fn after all completion
value_t add2(value_t x)
{
	return x+2;
}

/* function description
 * function to add 2 numbers (used to pass as function pointer)
 * @param value_t first number
 * @param value_t second number
 * @return value_t return sum of numbers.
 */

value_t add_2_number(value_t x,value_t y)
{
	return x+y;
}

/* function description
 * function to subtract 2 numbers (used to pass as function pointer)
 * @param value_t first number
 * @param value_t second number
 * @return value_t return diffrence of numbers.
 */

value_t subtract_2_number(value_t x,value_t y)
{
	return x-y;
}

/* function description
 * function to square a number used to pass as function pointer
 * @param value_t  number
 * @return value_t return square of number.
 */

value_t square_Of_A_Number(value_t x)
{
	return x*x;
}

/* function description
 * function to square second argument then add square to first argument used to pass as function pointer
 * @param value_t first number
 * @param value_t second number
 * @return value_t return sum of number after square of second argument.
 */

value_t square_and_add_number(value_t x,value_t y)
{
	return x + square_Of_A_Number(y);
}

value_t sum(Sorted_list * list,int order){
   return reduce(list,add_2_number,0,order);

}

/* function description
 * print array
 * @param value_t * arr arr to print
 * @param int size size of array
 * @return void.
 */

void print_array(value_t * arr, int size){

    	for(int z=0;z<size;z++){
            printf("\n     %d",*arr);
            arr--;
    	}

}

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

value_t * diff (Sorted_list * list1,Sorted_list *list2, int order)
{
	if(list1->size != list2->size)
	{ return NULL;}
	
  //    value_t *arr=(value_t *)malloc(sizeof(value_t)*(list2->size));
	return map_2_array(list1,list2,subtract_2_number,order);
//	print_array(arr,list2->size);	
}
/* function description
 * takes a sorted list and produces a new sorted list whose value at a node equals 
 * the original value (not key) squared
 * @param Sorted_list * list
 * @return Sorted_list * return pointer to new Sorted_list
 */


Sorted_list * square(Sorted_list *list)
{
	return map(list,square_Of_A_Number);
}



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
void * sum_of_sq_diff(Sorted_list *list1,Sorted_list* list2,int order)
{
	  if(list1->size != list2->size)
	        { return NULL;}
	  printf("%d",map_2_reduce(list1,list2,subtract_2_number,square_and_add_number,0,order));

	return NULL; //to avoid warning NOTE: function execution will not reach here.
}

void printList_square(Sorted_list * list_detail)  
{  
    struct Node* node;
    
    node = list_detail->head;
    while (node != NULL) {  
        printf("     %d\n", node->value);  
        node = node->next; 
    }

}

int  testfunction(value_t x){

	if(x>20){
		return 1;//1 denote true
	}else
	{
		return 0;//0 denote false
	}
}
/* Main function of the program*/
int main( int argc, char *argv[] )  
{  
	   /* initilizing head and head_sort for the linked list */
    Sorted_list * list[10];// = (Sorted_list *)malloc(sizeof(Sorted_list));
    int i = 0;    
 
    while(i<10){
    	list[i] = (Sorted_list *)malloc(sizeof(Sorted_list));
	list[i]->head=NULL;
    	list[i]->head_sort=NULL;
    	list[i]->tails=NULL;
    	list[i]->tails_sort=NULL;
	i++;
    }

    char commands[50][50];
    value_t value;
    key_lt key;
    int j = 0;
    char *a;
    i = 0;
    if(argc == 1){
    	printf("input commands. press ctrl+D to stop entering inputs\n");
	char *input_string;
                size_t input_string_length = 50;
                input_string = (char *) malloc(input_string_length);

                while(getline(&input_string, &input_string_length, stdin) != -1)
                {
                        input_string[strcspn(input_string, "\n")] = 0;
			strcpy(commands[i], input_string);
			i++;
		}
    }

    else if(argc > 2){
    	printf("Too many arguments supplied");
    }
    else{
        FILE *fp;
	fp = fopen(argv[1],"r");

	while(fgets(commands[i],50, fp) != NULL) {
	        commands[i][strlen(commands[i]) -1] = '\0';
		i++;
	}
    }

    while(j<i){
	a = commands[j];
	char *cmd = strtok(a, "|");
	int n;
		if(strcmp(cmd,"rem_first")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);
			remove_first(list[n], &value, &key);
			printf("rem_first|%d:  %0.2f %d \n",n, key, value);
		}
		else if(strcmp(cmd,"rem_last")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);
			remove_first(list[n], &value, &key);
			printf("rem_last|%d:  %0.2f %d \n",n, key, value);
		}
		else if(strcmp(cmd,"rem_small")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);
			remove_smallest_key(list[n], &value, &key);
			printf("rem_small|%d:  %0.2f %d \n",n, key, value);
		}
		else if(strcmp(cmd,"rem_large")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);	
			remove_largest_key(list[n],&value,&key);
			printf("rem_large|%d:  %0.2f %d\n",n, key, value);
		}
		else if(strcmp(cmd,"print_all")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);	
			printList(list[n]);
		}
		else if(strcmp(cmd,"print_sort")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);	
			printList_sort(list[n]);
		}
	
		else if((cmd[0] == 'p')){
			key_lt tempk;
		        value_t	tempv;
			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &n);	
			
			cmd = strtok(NULL, " ");
			sscanf(cmd, "%lf", &tempk);

			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &tempv);
			
			printf("p|%d:          %0.2f  %d\n",n, tempk, tempv);
			push(list[n], tempv, tempk);
		}

		else if((cmd[0] == 'a')){
			value_t  tempv;
			key_lt tempk;
			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &n);	
			
			cmd = strtok(NULL, " ");
			sscanf(cmd, "%lf", &tempk);

			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &tempv);
			
			printf("a|%d:          %0.2f  %d\n",n, tempk, tempv);
			append(list[n], tempv, tempk);
		}

		else if(strcmp(cmd, "size")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);	

			printf("size|%d:       List size = %d\n",n, list[n]->size);
		}

		else if(strcmp(cmd, "empty")==0){
			cmd = strtok(NULL, "\0");
			sscanf(cmd, "%d", &n);	

			empty_list(list[n]);
			printf("empty|%d:      size = %d\n",n, list[n]->size);

		}
		else if(strcmp(cmd, "sum")==0){
			value_t sum_val;

			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &n);	
			
			cmd = strtok(NULL, " ");

			if(strcmp(cmd, "SORTED_ORDER") == 0){
				sum_val = sum(list[n],SORTED_ORDER);
			}
			else if(strcmp(cmd, "INSERTED_ORDER") == 0){
				sum_val = sum(list[n],INSERTED_ORDER);
			}

			printf("sum:        list = %d, result = %d\n",n, sum_val);

		}

		else if(strcmp(cmd, "square")==0){
			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &n);
			printf("square:     list = %d\n",n);	
			printList_square(square(list[n]));
		}

		else if(strcmp(cmd, "diff")==0){
			int m;
			cmd = strtok(NULL, ":");
			sscanf(cmd, "%d", &n);
			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &m);
			cmd = strtok(NULL, "\0");

			printf("\ndiff:       list1 = %d, list2 = %d", n, m);
			if(strcmp(cmd, "SORTED_ORDER") == 0){
				print_array(diff(list[n],list[m],SORTED_ORDER),list[m]->size);
			}
			else if(strcmp(cmd, "INSERTED_ORDER") == 0){
				print_array(diff(list[n],list[m],INSERTED_ORDER),list[m]->size);
			}
	
		}

		else if(strcmp(cmd, "sum_sq_d")==0){
			int m;
			cmd = strtok(NULL, ":");
			sscanf(cmd, "%d", &n);
			cmd = strtok(NULL, " ");
			sscanf(cmd, "%d", &m);
			cmd = strtok(NULL, "\0");
			
			if(strcmp(cmd, "SORTED_ORDER") == 0){
				printf("\nsum_sq_d:   list1 = %d, list2 = %d, result = ",n,m);
				sum_of_sq_diff(list[n],list[m],SORTED_ORDER);
			}
			else if(strcmp(cmd, "INSERTED_ORDER") == 0){
				printf("\nsum_sq_d:   list1 = %d, list2 = %d, result = ",n,m);
				sum_of_sq_diff(list[n],list[m],INSERTED_ORDER);
			}
	
		}

	j++;
    }
    //getchar();  
    return 0;  
}  
