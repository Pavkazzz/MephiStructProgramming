#include <stdio.h>
#include <math.h>

const int SIZE = 10;

int input(int *mass, int max_size) {

	int n = -1;

	while (n > max_size || n < 0) {
		printf("Введите кол-во элл., 0<n<%d > ", max_size);
		scanf("%d", &n);
	}
	int i=0;
	for (i; i<n; i++) {
		printf("[%d] = ", i);
		scanf("%d", &mass[i]);
	}
	return n;

}

void output(int *mass, int n) {
	int i=0;
	for (i; i<n; i++) {
		printf("mass[%d] = %d\n", i, mass[i]);
	}	
}

int sort(int *mass, int n) {
	int i,j,tmp;
	for (i=1; i<n; i++) {
		for (j=0; j<n-i; j++) {
			if (mass[j] > mass[j+1]) {
				tmp = mass[j];
				mass[j] = mass[j+1];
				mass[j+1] = tmp;
			}
		}
	}

}

int indexes(int *mass, int n) {
	int i=0;
	int new_size=0;
	for (i; i<n; i++) {
		if (mass[i]%2==1) {
			mass[new_size] = i;
			new_size++;
		}	
	}
	return new_size;
}

int main() {
    int vvod[SIZE];
    int result[SIZE];
    int n;
	while(printf("Введите кол-во элементов, для окончания введите 0\n"), \
			n=input(vvod, SIZE)) {
	
		printf("исходный массив\n");
		output(vvod, n);	
		printf("отсортированный массив\n");
		int i;
		for (i=0; i<n; i++) {
			result[i] = vvod[i];
		}
		sort(result, n);
		output(result, n);
		printf("нечетные индексы\n");
		output(vvod, indexes(vvod, n));
	}

    return 0;
}

