#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
typedef int value_t;
#include "sorted_list.h"

int count_down(int n)
{
	
	if(n ==0){

	printf("%d",n);
		return 0;
	}

	printf("%d, ",n);

	return count_down(n-1);
}



int count_up(int n)
{
	static int count=0;
	if(n ==count){
		
		printf("%d",2*count);
		count=0;
		return 0;
		
	}
	printf("%d, ",2*count);
	count++;
	
	return count_up(n);
}


/* function description
 * map the values using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t) function pointer
 * @return Sorted_list pointer of new link list.
 */
int  nth( Sorted_list * list,struct Node * node,int n){
	
	if(list->size -1 <n || n<0)
	{
		return 0;
	}

	if(n==0){
		printf("     %d  %d",node->key,node->value);
		return 0;
	}
	
	return nth(list,node->next,n-1);
}

/* function description
 * map the values using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t) function pointer
 * @return Sorted_list pointer of new link list.
 */
int  nth_sorted( Sorted_list * list, struct Node * node,int n){
	
	if(list->size -1 <n || n<0)
        {
                return 0;
        }



	if(n==0){
		printf("     %d  %d",node->key,node->value);
		return 0;
	}
	
	return nth_sorted(list, node->sort,n-1);
}


/* function description
 * map the values using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t) function pointer
 * @return Sorted_list pointer of new link list.
 */
int  remove_nth( Sorted_list * list, struct Node * node,int n){
   if(list->size-1 < n || n < 0){
                return 0;
        }
	

	if(n==0){
		struct Node * ptr;
		 ptr =node;
             value_t   deleted_Node_Value=node->value;
             value_t   deleted_Node_Key=node->key;
                //update head_sort
                if(node->prev_sorted != NULL && node->sort != NULL){
                        node->prev_sorted->sort=node->sort;
                        node->sort->prev_sorted= node->prev_sorted;
                }
                else  if( node->prev_sorted == NULL && node->sort != NULL)
                {
                        node->sort->prev_sorted= NULL;
                        list->head_sort=list->head_sort->sort;
                }
                else  if(node->prev_sorted != NULL && node->sort == NULL)
                {
                        node->prev_sorted->sort=NULL;
                        list->tails_sort=node->prev_sorted;
                }
		else if(node->next==NULL && node->prev== NULL)
		{
			list->head= NULL;
	                list->head_sort=NULL;
        	        list->tails=NULL;
                	list->tails_sort=NULL;

		}
                //update head



                if(node->prev != NULL && node->next != NULL){
                        node->prev->next=node->next;
                        node->next->prev=node->prev;
                }
                else if(node->prev == NULL && node->next != NULL)
                {
                        node->next->prev=NULL;
                        list->head=list->head->next;
                }
                else if(node->next ==NULL && node->prev != NULL)
                {
                        node->prev->next = NULL;
                        list->tails=list->tails->prev;
                }
		else if(node->next ==NULL && node->prev==NULL)
		{
			list->head_sort= NULL;
	                list->head=NULL;
        	        list->tails=NULL;
                	list->tails_sort=NULL;

		}
		list->size=list->size-1;			

                free(ptr);

		printf("     %d  %d",deleted_Node_Key,deleted_Node_Value);
		return 0;
	}
	
	return remove_nth(list,node->next,n-1);
}


/* function description
 * map the values using function pointer.
 * @param Sorted_list * Sorted_list pointer
 * @param value_t (*f)(value_t) function pointer
 * @return Sorted_list pointer of new link list.
 */
int  remove_nth_sorted( Sorted_list * list, struct Node * node,int n){
	 if(list->size-1 < n || n < 0){
                return 0;
        }
	

	if(n==0){
		struct Node * ptr;
		 ptr =node;
             value_t   deleted_Node_Value=node->value;
             value_t   deleted_Node_Key=node->key;
                //update head_sort
                if(node->prev_sorted != NULL && node->sort != NULL){
                        node->prev_sorted->sort=node->sort;
                        node->sort->prev_sorted= node->prev_sorted;
                }
                else  if( node->prev_sorted == NULL && node->sort != NULL)
                {
                        node->sort->prev_sorted= NULL;
                        list->head_sort=list->head_sort->sort;
                }
                else  if(node->prev_sorted != NULL && node->sort == NULL)
                {
                        node->prev_sorted->sort=NULL;
                        list->tails_sort=node->prev_sorted;
                }
		else if(node->next==NULL && node->prev== NULL)
		{
			list->head= NULL;
	                list->head_sort=NULL;
        	        list->tails=NULL;
                	list->tails_sort=NULL;

		}
                //update head



                if(node->prev != NULL && node->next != NULL){
                        node->prev->next=node->next;
                        node->next->prev=node->prev;
                }
                else if(node->prev == NULL && node->next != NULL)
                {
                        node->next->prev=NULL;
                        list->head=list->head->next;
                }
                else if(node->next ==NULL && node->prev != NULL)
                {
                        node->prev->next = NULL;
                        list->tails=list->tails->prev;
                }
		else if(node->next ==NULL && node->prev==NULL)
		{
			list->head_sort= NULL;
	                list->head=NULL;
        	        list->tails=NULL;
                	list->tails_sort=NULL;

		}
		list->size=list->size-1;			

                free(ptr);

		printf("     %d  %d",deleted_Node_Key,deleted_Node_Value);
		return 0;
	}
	
	return remove_nth_sorted(list,node->sort,n-1);
}






/* Main function of the program*/
int main( int argc, char *argv[] )  
{  
    /* initilizing head and head_sort for the linked list */
    Sorted_list * list_detail=(Sorted_list *)malloc(sizeof(Sorted_list));
    list_detail->head=NULL;
    list_detail->head_sort=NULL;
    list_detail->tails=NULL;
    list_detail->tails_sort=NULL;
    int i = 0;    
    char chunk[50];
    char commands[50][50];
    size_t malloc_size = 100;
    value_t value;
    key_t key;
    int j = 0;
    int k = 0;
    char *a;

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
		if(strcmp(a,"rem_first")==0){
			remove_first(list_detail, &value, &key);
			printf("rem_first:  %d %d \n", key, value);
		}
		else if(strcmp(a,"rem_last")==0){
			remove_last(list_detail, &value, &key);
			printf("rem_last:   %d %d \n", key, value);

		}
		else if(strcmp(a,"rem_small")==0){
			remove_smallest_key(list_detail,&value,&key);
			printf("rem_small:  %d %d\n", key, value);
		}
		else if(strcmp(a,"rem_large")==0){
			remove_largest_key(list_detail,&value,&key);
			printf("rem_large:  %d %d\n", key, value);
		}
		else if(strcmp(a,"print_all")==0){
			printList(list_detail);
		}
		else if(strcmp(a,"print_sort")==0){
			printList_sort(list_detail);
		}
	
		else if((a[0] == 'p')){
			int tempk, tempv;
			char *s;
			s = a;
			char *p = strtok(a," ");
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempk);
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempv);
			printf("p:          %d  %d\n",tempk, tempv);
			push(list_detail, tempv, tempk);
		}

		else if((a[0] == 'a')){
			int tempk, tempv;
			char *s;
			s = a;
			char *p = strtok(s," ");
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempk);
			p = strtok(NULL, " ");
			sscanf(p, "%d", &tempv);
			printf("a:          %d  %d\n",tempk, tempv);
			append(list_detail, tempv, tempk);
		}

		else if(strcmp(a, "size")==0){
			int sz = size(list_detail);
			printf("size:       List size = %d\n", list_detail->size);
		}

		else if(strcmp(a, "empty")==0){
			empty_list(list_detail);
			printf("empty:      size = %d\n", list_detail->size);

		}
	j++;
    }
	count_up(12);
	count_down(21);
	nth(list_detail, list_detail->head,2);
	nth_sorted(list_detail, list_detail->head_sort,2);
	printf("\n");
	remove_nth(list_detail,list_detail->head,2);
	
	printf("\n");
	printf("\n");
	  printList(list_detail);

	printf("\n");
	remove_nth_sorted(list_detail,list_detail->head_sort,1);
	printf("\n");
	  printList_sort(list_detail);

    destroy_list(list_detail);

    destroy_list(list_detail);

//    getchar();  
    return 0;  
}  
