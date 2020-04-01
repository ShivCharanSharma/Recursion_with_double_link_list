#include<stdio.h>
#include<stdlib.h>

#define SIMPLE 1
#define MIXED 0

#define FALSE 0
#define TRUE 1

typedef struct{
	long num;
	unsigned long denom;
}Fraction;

long gcd(long a, long b){ 
        long n1, n2;
        if(b > 0){return gcd(b, a%b);}
        else{return a;}
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
	int n;
	int d;
	int w; //whole number for mixed fraction
	n = fract->num;
	d = fract->denom;

	// mixed mode
	if(mode == 0){	
		if(n%d == 0){
			printf("%ld\n", fract->num/fract->denom);
		}

		else if(n < d){
			printf("%ld/%lu\n",  fract->num, fract->denom );
		}

		else if(n > d){
			w = n/d;
			n = n%d;
			printf("2\n");
			printf("%d %ld/%lu\n", w, fract->num, fract->denom);
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
	result->num = (x->num)*(y->denom) + (y->num)*(x->denom);
	result->denom = (x->denom)*(y->denom);
}

int main(){
	Fraction *f1 = (Fraction *)malloc(sizeof(Fraction));
	Fraction *f2 = (Fraction *)malloc(sizeof(Fraction));
	Fraction *f3 = (Fraction *)malloc(sizeof(Fraction));

	int ans1, ans2;
	ans1 = set_fraction(f1,8,18);
	ans2 = set_fraction(f2,9,18); 

	add_fract(f3, f1, f2);
	simplify(f3);
	print_fract(f3, 0);

	return 0;
}
