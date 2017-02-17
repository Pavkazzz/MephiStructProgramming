// Сумма первой и последней цифры
#include <stdio.h>

int main() {
    int vvod = 0;
    while (vvod <= 0) {
        printf("Ожидание ввода натурального числа > ");
        scanf("%d", &vvod);
    } 

    int k = 1;

    int s = vvod % 10;
    vvod /= 10;
    while (vvod >= 10) {
        vvod /= 10;
    }
    s += vvod % 10;

    printf("Сумма первой и последней цифры: %d\n", s);
    return 0;
}