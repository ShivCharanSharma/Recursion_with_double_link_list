#include<stdio.h>

long gcd(long a, long b){
	long n1, n2;

	n1 = (a>b)?a:b;
	n2 = (n1 == a)?b:a;

	if(b > 0){
		return gcd(b, a%b);
	}
	else{
		return a;
	}
}

int main(){
	long num1, num2, gcd_ans;
	printf("Enter the two numbers whose gcd you want to find:\n");
	scanf("%ld", &num1);
	scanf("%ld", &num2);
	gcd_ans =  gcd(num1, num2);
	printf("GCD of %ld, %ld is %ld\n", num1, num2, gcd_ans);

	return 0;
}
