
#include <math.h>
#include <stdio.h>
#include "libfire.h"

int main(int argc, char *argv[]) {

	double opp;
	double adj;
	double h2, hyp;
	double dist;
	double start, end;
	int rval;
	
	printf("Input 3.0 4.0 6.0 please: ");
	scanf("%lf %lf %lf", &opp, &adj, &dist);
	
	start = now();
	
	h2 = opp * opp + adj * adj;
	
	hyp = sqrt(h2);
	
	rval = (hyp > dist);
	
	end = now();
	
	printf("%s says (%4.1lf > %4.1lf) gives %d. It took %.91f micro seconds.\n", argv[0], hyp, dist, rval, (end - start) * 1000000.0);
	
	return 0;
}
