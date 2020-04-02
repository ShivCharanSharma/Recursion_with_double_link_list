#include<stdio.h>
#include "a.h"
#include<math.h>
typedef Fraction value_t;
typedef double key_lt;
//#include "sorted_list.h"

#include "functions.h"

int filter_fraction(value_t x){
	if((int)abs(x.num) % x.denom == 0){
		return 0;
	}
	else{
		return 1;
	}
}
int filter_wholeNumber(value_t x){

	if((int)abs(x.num) % x.denom ==0)
	{
		return 1;
	}else{
		return 0;
	}
}
int filter_mixedFraction(value_t x)
{
	if((int)(abs(x.num) % x.denom ==0) || (int)abs(x.num) < x.denom){
		return 1;
	}else{
		return 0;
	}
}


int main(int argc, char *argv[] )
{	
	 Sorted_list * list =(Sorted_list *)malloc(sizeof(Sorted_list));
         list->head=NULL;
         list->head_sort=NULL;
         list->tails=NULL;
         list->tails_sort=NULL;
         int i = 0;
         char chunk[50];
         char commands[50][50];
         size_t malloc_size = 100;
         int j = 0;
         int k = 0;
         char *a;
	 value_t value;
	 key_lt key;
              
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
     		int n;
	     	char *cmd = strtok(a, " ");
     
		if(strcmp(a,"rem_first")==0){
			remove_first(list, &value, &key);
			printf("rem_first:  %0.2f ", key);
			print_fract(&value, 1);
		}
		else if(strcmp(a,"rem_last")==0){
			remove_last(list, &value, &key);
			printf("rem_last:   %0.2f ", key);
			print_fract(&value, 1);
		}
		else if(strcmp(a,"rem_small")==0){
			remove_smallest_key(list,&value,&key);
			printf("rem_small:  %0.2f ", key);
			print_fract(&value, 1);	
		}
		else if(strcmp(a,"rem_large")==0){
			remove_largest_key(list,&value,&key);
			printf("rem_large:  %0.2f ", key);
			print_fract(&value, 1);
		}

		else if(strcmp(cmd,"print_all") == 0){
			int mode;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				mode = 1;
				printf("print_all:  Simple Fraction, Insertion Order\n");
			}
			else if(strcmp(cmd, "MIXED") == 0){
				mode = 0;
				printf("print_all:  Mixed Fraction, Insertion Order\n");		
			}
			printList(list,mode);
		}

		else if(strcmp(cmd,"print_sort") == 0){
			int mode;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				printf("print_all:  Simple Fraction, Sorted Order\n");			
				mode = 1;
			}
			else if(strcmp(cmd, "MIXED") == 0){
				printf("print_all:  Mixed Fraction, Sorted Order\n");
				mode = 0;
			}
			printList_sort(list,mode);
		}

		else if(strcmp(cmd, "fract") == 0){
			int mode;
			Sorted_list * fraclist;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				printf("print_all:  Simple Fraction, Insertion Order\n");
				mode = 1;
			}
			else if(strcmp(cmd, "MIXED") == 0){
				printf("print_all:  Mixed Fraction, Insertion Order\n");
				mode = 0;
			}
			fraclist=filter(list,filter_fraction);
			printList(fraclist, mode);
			
			destroy_list(fraclist);
		}

		else if(strcmp(cmd, "whole_num") == 0){
			int mode;
			Sorted_list * wholeList;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				printf("print_all:  Simple Fraction, Insertion Order\n");
				mode = 1;
			}
			else if(strcmp(cmd, "MIXED") == 0){
				printf("print_all:  Mixed Fraction, Insertion Order\n");
				mode = 0;
			}
			wholeList=filter(list,filter_wholeNumber);
			printList(wholeList, mode);
			
			destroy_list(wholeList);
		}

		else if(strcmp(cmd, "rem_mixed") == 0){
			int mode;
			Sorted_list * mixed_less_list;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				mode = 1;
			}
			else if(strcmp(cmd, "MIXED") == 0){
				mode = 0;
			}
			mixed_less_list=filter(list,filter_mixedFraction);
			printList(mixed_less_list, mode);
			
			destroy_list(mixed_less_list);
		}

		else if(strcmp(cmd, "sum") == 0){
			int mode;
			Sorted_list * mixed_less_list;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				mode = 1;
			}
			else if(strcmp(cmd, "MIXED") == 0){
				mode = 0;
			}

			value_t initValue={0,1};
			value_t sumValue;
			sumValue = reduce(list,add_fract,initValue,INSERTED_ORDER);
			print_fract(&sumValue,mode);

		}

    	 	else if((a[0] == 'p')){
			int ans;
			float tempk;
			int n,d;
			float nn, dd;
     			char *s;
			value_t frac;
     			cmd = strtok(NULL, "/");
     			sscanf(cmd, "%d", &n);
     			cmd = strtok(NULL, "\0");
     			sscanf(cmd, "%d", &d);
			ans = set_fraction(&frac,n,d);
			if(ans == 1){
				tempk = (float)n/(float)d;
				push(list, frac, tempk);
				printf("p:          %0.2f  %ld/%lu\n",tempk, frac.num,frac.denom );
			}

			else if(ans == 0){
				printf("invalid numertor or denomenator\n");
			}
     		}
     		
		else if((a[0] == 'a')){
			int ans;
			float tempk;
			int n,d;
			float nn, dd;
     			char *s;
			value_t frac;
     			cmd = strtok(NULL, "/");
     			sscanf(cmd, "%d", &n);
     			cmd = strtok(NULL, "\0");
     			sscanf(cmd, "%d", &d);
			ans = set_fraction(&frac,n,d);
			if(ans == 1){
				tempk = (float)n/(float)d;
				append(list, frac, tempk);
				printf("a:          %0.2f  %ld/%lu\n",tempk, frac.num,frac.denom );
			}

			else if(ans == 0){
				printf("invalid numertor or denomenator\n");
			}
     		}
     		
       	j++;
 }

	 return 0;
}
