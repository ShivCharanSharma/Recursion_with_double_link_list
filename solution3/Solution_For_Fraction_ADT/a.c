#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "a.h"
#define SIMPLE 1
#define MIXED 0

#define FALSE 0
#define TRUE 1
//
//typedef struct{
//	long num;
//	unsigned long denom;
//}Fraction;
//
long gcd(long a, long b){ 
        long n1, n2;
        if(b <= 0)
        {return a;}
	else
	{return gcd(b, a%b);}
}

int set_fraction(Fraction * fract, int num, int denom){
	if(denom == 0){
		return FALSE;
	}
	else{
		if(denom < 0){
			num = -num;
			denom = -denom;
		}

		fract->num = num;
		fract->denom = denom;

		return TRUE;
	}
}

void print_fract(Fraction * fract, int mode){
	long int n;
	int d;
	int w; //whole number for mixed fraction
	n = fract->num;
	d = fract->denom;

	// mixed mode
	if(mode == 0){	
		if(n < 0 && (((-1)*(n)%d) == 0)){
			printf("-%ld\n", ((-1)*(fract->num))/fract->denom);
		}
		
		else if(n%d == 0){
			printf("%ld\n", fract->num/fract->denom);
		}
		
		else if(n > d){
			w = n/d;
			n = n%d;
			printf("%d %ld/%lu\n", w, fract->num, fract->denom);
		}

		else if(n<0 && ((-1)*(n))>d){
			w = n/d;
			n = (-1)*(n)%d;
			printf("%d %ld/%lu\n", w, n, fract->denom);

		}
		else if(n < d){

			printf("%ld/%lu\n",  fract->num, fract->denom );
		}

		
	}

	// simple mode
	else if(mode == 1){
		printf("%ld/%lu\n", fract->num, fract->denom);
	}

}

void simplify(Fraction * fract){
	int g;
	g = gcd(fract->num, fract->denom);
	fract->num /= g;
	fract->denom /= g;
}

int add_fract(Fraction * result, Fraction * x, Fraction * y){

 	//check overflow and underflow 
       
	  if(((x->num)*(y->denom) >0) && ((y->num)*(x->denom) > LONG_MAX - (x->num)*(y->denom))){
		  return FALSE;
			  }
	 if(((x->num)*(y->denom) <0) && ((y->num)*(x->denom) < LONG_MIN- (x->num)*(y->denom))){
                  return FALSE;
                          }


	result->num = (x->num)*(y->denom) + (y->num)*(x->denom);
	result->denom = (x->denom)*(y->denom);
	return TRUE;
}

//gint main(){
//g	Fraction *f1 = (Fraction *)malloc(sizeof(Fraction));
//g	Fraction *f2 = (Fraction *)malloc(sizeof(Fraction));
//g	Fraction *f3 = (Fraction *)malloc(sizeof(Fraction));
//g
//g	int ans1, ans2;
//g	ans1 = set_fraction(f1,922337245,18);
//g	ans2 = set_fraction(f2,9,922337234); 
//g
//g	if(!(add_fract(f3, f1, f2)))
//g	{
//g		printf("not");
//g	}else{
//g		
//g	print_fract(f3, 0);
//g	}
//gprintf("%ld",LONG_MAX);	
//g	print_fract(f2, 0);
//g//	simplify(f3);
//g	print_fract(f2, 0);
//g
//g	return 0;
//g}
