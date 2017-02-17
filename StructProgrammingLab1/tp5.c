#include <stdio.h>
#include <string.h>

const int SIZE = 80;

int main() {
    char vvod[SIZE];
	char work[SIZE];
	
	while(printf("Введите строку символов\n"), gets(vvod)) {
    	char res[SIZE];
		char *w = vvod;
		char *p;
		int i=0;
		int j=0;
		while(*(w = strtok(w, " \t"))) {
			if (i%2==0) {
				res[j] = w[0];
				j++;
			}
			
			w++;
			if (w[0] == ' ' || w[0] == '\t') {
				res[j] = ' ';
				j++;
				i--;
			}
			i++;
		}

		res[j] = '\0';
		char *r = res;
		printf("Otvet: %s\n", r);
	}
    return 0;
}

