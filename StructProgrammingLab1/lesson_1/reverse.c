#include <stdio.h>

int main() {
    int vvod = 0;
    while (vvod <= 0) {
        printf("Ожидание ввода натурального числа > ");
        scanf("%d", &vvod);
    } 

    int s = 0;

    while (vvod > 10) {
        s = s*10 + vvod%10;
        vvod /= 10;
    }


    printf("Перевернутое число: %d\n", s);
    return 0;
}