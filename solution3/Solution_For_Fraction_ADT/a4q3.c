#include<stdio.h>
#include "a.h"

typedef Fraction value_t;
typedef double key_lt;
//#include "sorted_list.h"

#include "functions.h"

int filter_fraction(value_t x){
	if(x->num % x->denom ==0){
		return 0;
	}else{
		return 1;
	}
}
int filter_wholeNumber(value_t x){

	if(x->num % x->denom ==0)
	{
		return 1;
	}else{
		return 0;
	}
}
int filter_mixedFraction(value_t x)
{
	if((x->num % x->denom ==0) || x->num < x->denom){
		return 1;
	}else{
		return 0;
	}
}

int main()
{	
	Sorted_list * list =(Sorted_list *)malloc(sizeof(Sorted_list));
//	Fraction * frec=(Fraction *)malloc(sizeof(Fraction));
	value_t frec;
	set_fraction(&frec,3,4);

	append(list,frec,3/4);

	value_t initValue={0,1};
	value_t sumValue;
	sumValue = reduce(list,add_fract,initValue,INSERTED_ORDER);
	print_fract(&sumValue,SIMPLE);
	
	Sorted_list * fraclist,wholeList,mixed_less_list;
	fraclist=filter(list,filter_fraction);
	wholeList=filter(list,filter_wholeNumber);
	mixed_less_list=filter(list,filter_mixedFraction);
	//now all list can be printed

	
	printList(list);

	

	return 0;
}
