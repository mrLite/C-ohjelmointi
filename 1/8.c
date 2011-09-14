#include <stdio.h>
#include <stdlib.h>
#include "8.h"

/* Start of ex. 8 */

int recursive_gcd(int a, int b) {
	int ret;
	if(a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	ret = a%b;
	if(ret == 0) {
		return b;
	}
	else {
		return recursive_gcd(b, ret);
	}
}

int iterative_gcd(int a, int b) {
	int ret;
	while(1) {
		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
		}
		ret = a%b;
		if(ret == 0) {
			break;
		}
		else {
			a = b;
			b = ret;
		}
	}
	return b;
}

void gcd_test() {
	int a = 23152352;
	int b = 235232;
	int rgcd = recursive_gcd(a, b);
	int igcd = iterative_gcd(a, b);
	printf("Integers %d and %d. Greatest common divisor:\n", a, b);
	printf("Recursive method: %d\n", rgcd);
	printf("Iterative method: %d\n", igcd);
	
	int c = 2147483640;
	int d = 2345230;
	int rgcd_2 = recursive_gcd(c, d);
	int igcd_2 = iterative_gcd(c, d);
	printf("Integers %d and %d. Greatest common divisor:\n", c, d);
	printf("Recursive method: %d\n", rgcd_2);
	printf("Iterative method: %d\n", igcd_2);
}

/* End of ex. 8 */

fraction simplify(fraction n) {
	int gcd = iterative_gcd(n.denominator, n.nominator);
	n.nominator = (n.nominator/gcd);
	n.denominator = (n.denominator/gcd);
	return n;
}

// Ex. 9
fraction fr_add(fraction a, fraction b) {
	fraction result;
	result.nominator = (a.nominator*b.denominator)+(b.nominator*a.denominator);
	result.denominator = (a.denominator*b.denominator);
	result = simplify(result);
	return result;
}

// Ex. 10
fraction fr_sub(fraction a, fraction b) {
	fraction result;
	result.nominator = (a.nominator*b.denominator)-(b.nominator*a.denominator);
	result.denominator = (a.denominator*b.denominator);
	result = simplify(result);
	return result;
}


// Ex. 11
fraction fr_mul(fraction a, fraction b) {
	fraction result;
	result.nominator = a.nominator*b.nominator;
	result.denominator = a.denominator*b.denominator;
	result = simplify(result);
	return result;
}

// Ex. 12
fraction fr_div(fraction a, fraction b) {
	fraction result;
	result.nominator = a.nominator*b.denominator;
	result.denominator = b.nominator*a.denominator;
	result = simplify(result);
	return result;
}

int main(void) {
	gcd_test();
	
	fraction a = {3, 8};
	fraction b = {4, 11};
	printf("\nTwo fractions, a: 3/8 and b: 4/11\n");
	fraction added = fr_add(a, b);
	printf("Result of addition: %d/%d\n", added.nominator, added.denominator);
	
	fraction substracted = fr_sub(a, b);
	printf("Result of substraction: %d/%d\n", substracted.nominator, substracted.denominator);
	
	fraction multiplied = fr_mul(a, b);
	printf("Result of multiplication: %d/%d\n", multiplied.nominator, multiplied.denominator);
	
	fraction divided = fr_div(a, b);
	printf("Result of division: %d/%d\n", divided.nominator, divided.denominator);
}