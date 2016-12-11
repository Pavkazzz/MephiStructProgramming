#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const int SIZE = 10;

int input(queue *inp, int max_size) {
	int len = -1;
	while (len > max_size || len < 0) {
		printf("Введите кол-во элл., 0<n<%d > ", max_size);
		scanf("%d", &len);
	}
	//inp = (int *)malloc(sizeof(queue)*len);
	
	int i=0;
	int num;
	for (i; i<len; i++) {
		printf("[%d] = ", i);
		scanf("%d", &num);
		put(inp,num);
	}
	return len;
}


void output(queue *mass, int len) {
	int i=0;
	int num;
	for (i; i<len; i++) {
		get(mass, &num);
		printf("mass[%d] = %d\n", i, num);
	}	
}

void sort_v(int *mass, int n, int vozr) {
	int i,j,tmp;
	for (i=1; i<n; i++) {
		for (j=0; j<n-i; j++) {
			if (vozr == 1) {
				if (mass[j] > mass[j+1]) {
					tmp = mass[j];
					mass[j] = mass[j+1];
					mass[j+1] = tmp;
				}
			} else {
				if (mass[j] < mass[j+1]) {
					tmp = mass[j];
					mass[j] = mass[j+1];
					mass[j+1] = tmp;
				}
			}
		}
	}
}

int main() {
	queue *inp;
	init(inp);
	queue *res;
	init(res);
    int len;
	while(printf("Введите кол-во элементов, для окончания введите 0\n"), \
			len=input(SIZE)) {
	
		printf("исходный массив\n");
		output(inp);	
	
		//sort_v(otric, len_o, 1);
		//sort_v(polozh, len_p, 0);
		
		free(inp);
	/*
		printf("отсортированный массив\n");
		int i;
		for (i=0; i<n; i++) {
			result[i] = vvod[i];
		}
		sort(result, n);
		output(result, n);
		printf("нечетные индексы\n");
		output(vvod, indexes(vvod, n));
	*/
	}
	

    return 0;
}

