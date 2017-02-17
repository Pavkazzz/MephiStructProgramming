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
		int i=0;
		int j=0;
		while(w) {
			for (i=0; i<strlen(w); i++) {
				if (i%2==0) {
					res[j] = w[i];
					j++;
				}
			}
			res[j] = ' ';
			j++;
			w = strtok(NULL, " \t");
			
		}

		res[j] = '\0';
		char *r = res;
		printf("Otvet: %s\n", r);
	}
    return 0;
}

