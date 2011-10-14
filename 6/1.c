#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double f(double x) { return x*x + 3*x - 3; }
double df(double x) { return 2*x + 3; }

double g(double x) { return x*x + 0.000001/2.0; }
double dg(double x) { return 2*x; }

void newton(double (*fx)(double), double (*dfx)(double), double initial_value) {
	double curr = initial_value;
	double fx_v, dfx_v, ratio;
	for(int i = 1; i <= 100; ++i) {
		fx_v = fx(curr);
		dfx_v = dfx(curr);
		assert(dfx_v != 0);
		ratio = fx_v/dfx_v;
		printf("%d. iteration\tx = %f\tf(x)/f'(x) = %f\tf(x) = %f\n", i, curr, ratio, fx_v);
		double new = curr - ratio;
		if(fabs(new - curr) < 0.00001) return;
		curr = new;
	}
	return;
}

int main(void) {
	double f(double);
	double df(double);
	double (*fp)(double);
	double (*dfp)(double);
	fp = f;
	dfp = df;
	
	double g(double);
	double dg(double);
	double (*gp)(double);
	double (*dgp)(double);
	gp = g;
	dgp = dg;
	
	newton(fp, dfp, 3);
	newton(gp, dgp, 0.0);
}