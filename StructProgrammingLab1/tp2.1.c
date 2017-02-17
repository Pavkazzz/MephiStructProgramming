#include <stdio.h>
#include <math.h>

int main() {
    
    double vvod = 1;
    int n = 0;
    while (vvod > 0) {
	printf("Введите вещественное число x: > ");  
	scanf("%lf", &vvod);
        if (vvod == 0 ) {
	    return 0;
	} 

	printf("Введите количество членов ряда n: > ");
	scanf("%d", &n);

	double res = 1;	 
	int i=1;
	for (i; i<n+1; i++) {
	    double iter;
	    int znak;
	    if (i % 2 == 0) 
		znak = 1;
	    else 
		znak = -1;
		
	    int z = 0;
            double chisl = 1;
            for(z; z<2*i; z++) {
	        chisl *= vvod;
	    }
	    
	    double gam_max = 1;
	    int gam = 2*i;
	    for (gam; gam > 0; gam--) {
	    	gam_max *= gam;
	    }
	    
	    iter = znak * chisl / gam_max;
	    res += iter;
	
	    printf("%f\n", iter);
	}

       

	printf("Сумма %d членов ряда = %f\n", n, res);
 	
	double res2 = cos(vvod);
	printf("cos(x) = %f\n", res2);

    }
    return 0;
}

