#include <stdio.h>
#include <math.h>

int main() {
    
    double vvod = 1;
    int n = 0;
    while (vvod > 0) {
	printf("Введите вещественное число x (|x|<=1): > ");  
	scanf("%lf", &vvod);
        if (vvod == 0) {
	    return 0;
	} 

	printf("Введите количество членов ряда n: > ");
	scanf("%d", &n);

	double res = 0;	 
	int i=1;
	for (i; i<n; i++) {
	    int znak;
	
	    if (i % 2 == 1) 
		znak = 1;
	    else 
		znak = -1;
	
	    int z = 1;
            double chisl = vvod;
            for(z; z<2*i-1; z++) {
	        chisl = chisl * vvod;
	    }
	    
	    double znam = 2*i-1; 
	    
	    double iter = znak * chisl / znam;
	    res += iter;
	
	}

       

	printf("Сумма %d членов ряда = %f\n", n, res);
 	
	double res2 = atan(vvod);
	printf("atan(x) = %f\n", res2);

    }
    return 0;
}

