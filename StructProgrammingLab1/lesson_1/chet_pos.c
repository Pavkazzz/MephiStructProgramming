// Удалить все цифры на четных местах
#include <stdio.h>
#include <math.h>

int main() {
    int vvod = 0;
    while (vvod <= 0) {
        printf("Ожидание ввода натурального числа > ");
        scanf("%d", &vvod);
    }  

    int s1 = 0, s2 = 0;
    int pos = 1;
    int k = 1;

    while (vvod > 0) {

        if (pos % 2) {
            s1 += vvod % 10 * k;
        }
        else {
            s2 += vvod % 10 * k;
            k *= 10;
        }

        vvod /= 10;
        pos++;
    }
    if (pos % 2) {
        printf("Число без четных цифр: %d\n", s2);
    }
    else {
        printf("Число без четных цифр: %d\n", s1);        
    }
    return 0;
}