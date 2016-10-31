#include <stdio.h>
#include <string.h>

const int SIZE = 80;

int main() {
    char vvod[SIZE];
	char work[SIZE];
	
	while(printf("Введите строку символов\n"), gets(vvod)) {
    	char res[SIZE];
		char *w = strtok(vvod, " \t");
		char *p;
		int sizes[20];
		char pointers[20][80];
		int i=0;
		int j=0;
		while(w) {
			printf("%s\n", w);
			sizes[i] = strcspn(w, " \t");
			//printf("%d", pointers[i]);
			strncpy(pointers[i], w, sizes[i]);
			//printf("%s", z);
			i++;
			w = strtok(NULL, " \t");
		}
		int n,m, k, tmp;
		char tmp_c[80];
		for (n=0; n<i-1; n++) 
		{
			for (m=n+1, k=n; m<i; m++) 
				if (sizes[m] < sizes[k]) k = m;
			
			tmp = sizes[n];
			sizes[n] = sizes[k];
			sizes[k] = tmp;
	
			tmp_c = pointers[n];
			pointers[n] = pointers[k];
			pointers[k] = tmp_c;
			
		}
		

		char r[SIZE];
		int v;
		for (j=0; j<i; j++) {
			//printf("%d", j);
			printf("%d: %s\n", sizes[j], pointers[j]);
		}
		//res[j] = '\0';
		printf("Otvet: %s\n", r);
	}
    return 0;
}

