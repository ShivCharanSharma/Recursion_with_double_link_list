#ifndef A_H_INCLUDED
#define A_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define SIMPLE 1
#define MIXED 0

#define FALSE 0
#define TRUE 1

typedef struct{
	long num;
	unsigned long denom;
}Fraction;

long gcd(long a, long b);
int set_fraction(Fraction * fract, int num, int denom);
void print_fract(Fraction * fract, int mode);
void simplify(Fraction * fract);


int add_fract(Fraction * result, Fraction * x, Fraction * y);


#endif
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
