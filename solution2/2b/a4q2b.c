#include<stdio.h>

long gcd(long a, long b){
	long n1, n2;

	n1 = (a>b)?a:b;
	n2 = (n1 == a)?b:a;

	if(b <= 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}

int main(){
	long num1, num2, gcd_ans;
	printf("Enter the two numbers whose gcd you want to find:\n");
	if(!(scanf("%ld", &num1)))
	{
		printf("Failed to read value.\n");
	}
	 if(!(scanf("%ld", &num2)))
        {
                printf("Failed to read value.\n");
        }

	gcd_ans =  gcd(num1, num2);
	printf("GCD of %ld, %ld is %ld\n", num1, num2, gcd_ans);

	return 0;
}
