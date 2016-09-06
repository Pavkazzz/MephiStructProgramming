// Удалить все четные цифры
#include <stdio.h>

int main() {
    int vvod = 0;
    while (vvod <= 0) {
        printf("Ожидание ввода натурального числа > ");
        scanf("%d", &vvod);
    } 

    int s = 0;
    int k = 1;

    while (vvod > 0) {
        int i = vvod % 10;
        vvod /= 10;
        if (i % 2) {
            s += i * k;
            k *= 10;
        }

    }

    printf("Число без четных цифр: %d\n", s);
    return 0;
}