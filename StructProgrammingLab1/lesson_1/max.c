// Найти максимальную цифру в нат. числе
#include <stdio.h>

int main() {
    int vvod = 0;
    while (vvod <= 0) {
        printf("Ожидание ввода натурального числа > ");
        scanf("%d", &vvod);
    } 

    int max = 0;

    while (vvod > 0) {
        if (max < vvod % 10) {
            max = vvod % 10;
        }
        vvod /= 10;
    }

    printf("Максимальная цифра: %d\n", max);
    return 0;
}