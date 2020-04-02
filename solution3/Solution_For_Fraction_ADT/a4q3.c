#include<stdio.h>
#include "a.h"
typedef Fraction value_t;
typedef double key_lt;
#include "sorted_list.h"
int main()
{	
	Sorted_list * list =(Sorted_list *)malloc(sizeof(Sorted_list));
//	Fraction * frec=(Fraction *)malloc(sizeof(Fraction));
	value_t frec;
	set_fraction(&frec,3,4);

	append(list,frec,3/4);
	printList(list);

	return 0;
}
