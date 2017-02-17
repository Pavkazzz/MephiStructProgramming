#include <stdio.h>

int main() {
    
    int vvod = 1;
    while (vvod > 0) {
	printf("Введите натуральное число > ");  
	scanf("%d", &vvod);
        if (vvod <= 0 ) {
	    return 0;
	} 
        int res = 0;
        int temp = vvod;
        int k = 1;
        int count = 0; 
        while (vvod / 10 > 0) {
    	    vvod /= 10;
        }
    
        while (temp / 10 > 0) {
            if ((temp % 10) != vvod) {
	        res += k*(temp%10);
	        k *= 10;
                count++;
	    }
            temp /= 10;
        }
    
        printf("Число без первой цифры: %d\nКоличество цифр: %d\n", res, count);
    }    
    return 0;
}

