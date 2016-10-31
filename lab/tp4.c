#include <stdio.h>

const int SIZE = 80;

char *skipspace(char *p) {
	for ( ; *p == ' ' || *p == '\t'; p++);
	return p;
}

char *skipword(char *p) {
	for (; *p && *p!=' ' && *p!='\t'; p++);
	return p;
}

int main() {
    char vvod[SIZE];
	char work[SIZE];
	
	while(printf("Введите строку символов\n"), gets(vvod)) {
    	char res[SIZE];
		char *w = vvod;
		char *p;
		int i=0;
		while(*(w = skipspace(w))) {
			//printf("%s\n", vvod);
			p = w;
			w = skipword(w);
			//printf("asd: %c %c\n", p[0], p[vvod-p-1]);
			if (p[0] == p[w - p - 1] && (w-p)%2==1) {
				printf("Одинаковы %c", p[0]);
				int j=0;
				for (j; j<w-p; j++,i++) {
					res[i] = p[j];
				}
				i++;
				res[i] = ' ';
			}
		}

		res[i] = '\0';
		char *r = res;
		printf("Otvet: %s\n", r);
		printf("%d\n", i);
	}
    return 0;
}

