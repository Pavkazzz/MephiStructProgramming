#include <stdio.h>

int main() {
    int vvod = 0;
    while (vvod <= 0) {
        printf("Ожидание ввода натурального числа > ");
        scanf("%d", &vvod);
    } 
    int s = 0;
    
    // Вариант 1
    // while (vvod > 10) {
    //     s += vvod % 10;
    //     vvod /= 10;
    // }
    // s += vvod;

    // Вариант 2 
    for (s=0; vvod>0; vvod/=10) {
        s += vvod % 10;
    }

    // Вариант 3
    // for (int i=0; i< ;i++) {

    // }

    printf("Сумма цифр равна: %d\n", s);
    return 0;
}