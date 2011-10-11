#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void newton(double initial_value) {
	double curr = initial_value;
	double fx, dfx, ratio;
	for(int i = 1; i <= 100; ++i) {
		fx = curr*curr + 3*curr - 3;
		dfx = 2*curr + 3;
		assert(dfx != 0);
		ratio = fx/dfx;
		printf("%d. iteration\tx = %f\tf(x)/f'(x) = %f\tf(x) = %f\n", i, curr, ratio, fx);
		double new = curr - ratio;
		if(fabs(new - curr) < 0.00001) return;
		curr = new;
	}
	return;
}

int main(void) {
	newton(3);
}