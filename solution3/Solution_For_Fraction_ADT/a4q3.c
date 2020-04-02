#include<stdio.h>
#include "a.h"
typedef Fraction value_t;
typedef double key_lt;
#include "sorted_list.h"

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
     
		if(strcmp(cmd,"print_all") == 0){
			int mode;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				mode = 1;
			}
			else if(strcmp(cmd, "MIXED") == 0){
				mode = 0;
			}
			printList(list,mode);
		}

		else if(strcmp(cmd,"print_sort") == 0){
			int mode;
			cmd = strtok(NULL, "\0");
			if(strcmp(cmd, "SIMPLE")==0){
				mode = 1;
			}
			else if(strcmp(cmd, "MIXED") == 0){
				mode = 0;
			}
			printList_sort(list,mode);
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
