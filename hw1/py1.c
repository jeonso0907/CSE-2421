
#include <math.h>
#include <stdio.h>
#include "libfire.h"

int main(int argc, char *argv[]) {

	double opp;
	double adj;
	double h2, hyp;
	double dist, d2;
	double start, end;
	int rval;
	
	printf("Input 3.0 4.0 6.0 please: ");
	scanf("%lf %lf %lf", &opp, &adj, &dist);
	
	start = now();
	
	h2 = opp * opp + adj * adj;
	
	d2 = dist * dist;
	
	rval = (h2 > d2);
	
	end = now();
	
	printf("%s says (%4.1lf > %4.1lf) gives %d. It took %.91f micro seconds.\n", argv[0], h2, d2, rval, (end - start) * 1000000.0);
	
	return 0;
}
