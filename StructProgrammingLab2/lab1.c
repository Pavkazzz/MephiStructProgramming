#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct Line {
    int n;
    int *ar;
} Line;

typedef struct Matrix {
    int m;
    Line *pt;
} Matrix;

int readGoodInt() {
    int i;
    while(scanf("%d",&i) != 1)
    {
        while(getchar() != '\n');
    }
    return i;
    
}

int input(Matrix *rm) {
    int a;
    int m,i,n,j;
    printf("Введите кол-во строк, для каждой строки кол-во элл.\n");
    //printf("%d", s);

    m = readGoodInt();

    rm->m = m;
    rm->pt = (Line *)calloc(m,sizeof(Line));

    for (i=0; i<m; i++) {
        printf("Введите количество элл. строки %d\n", i+1); 
        n = readGoodInt();
        rm->pt[i].n = n;
        rm->pt[i].ar = (int *)calloc(n, sizeof(int));
        for (j=0; j<n; j++) {
            printf("Введите [%d][%d]\n", i, j); 
            a = readGoodInt();
            rm->pt[i].ar[j] = a;
        }
    }

    return m;
}

void print(Matrix rm) {
    int i,j;
    for (i=0; i<rm.m; i++) {
        for(j=0; j<rm.pt[i].n; j++) {
            printf("%d ", rm.pt[i].ar[j]);
        }
        printf("\n");
    }
}

int sumNumb(int num) {
    int res = 0;
    while(num>0) {
        res += num %10;
        num = num/10;
    }
    return res;
}

void formNewMatrix(Matrix *old, Matrix *res) {
    int i,j;
    Line temp_line;
    for (i=0; i<old->m; i++) {
        
        temp_line.n = 0;
        temp_line.ar = (int *)calloc(old->pt[i].n, sizeof(int));
        for (j=0; j<old->pt[i].n-1; j++) {
            printf("%d\n", sumNumb(old->pt[i].ar[j]));
            printf("%d\n", sumNumb(old->pt[i].ar[old->pt[i].n-1]));

            if (sumNumb(old->pt[i].ar[j]) == sumNumb(old->pt[i].ar[old->pt[i].n-1])) {
                temp_line.n++;
                temp_line.ar[temp_line.n-1] = old->pt[i].ar[j];
            }
        }
        if (temp_line.n > 0) {
            res->m++;
            res->pt[res->m-1] = temp_line;
        }
    }
}

void erase(Matrix *m) {
    int i;
    for(i=0; i<m->m; i++) {
        free(m->pt[i].ar);
    }
    free(m->pt);
    m->pt = NULL;
}

int main() {
    Matrix inp;
    Matrix res;

    // setlocale(LC_ALL, ".1251");
    input(&inp);

    res.m = 0;
    res.pt = (Line *)calloc(inp.m, sizeof(Line));

    formNewMatrix(&inp, &res);

    printf("Было введено\n");
    print(inp);

    printf("Полученная матрица\n");
    print(res);

    erase(&res);
    erase(&inp);

    getchar();
    getchar();
    return 0;
}
