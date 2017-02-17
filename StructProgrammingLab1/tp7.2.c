#include <stdio.h>
#include <stdlib.h>

struct Item{int a;struct Item *next;};

struct Item *input_list();
void print_list(struct Item *);
void free_list(struct Item *);
void oddeven_list(struct Item *,struct Item **,struct Item **);
void sort_list(struct Item *);
void sort(struct Item *, int);
void swap(struct Item *, struct Item *);
void merge_list(struct Item *, struct Item *);
int main()
{
    struct Item *from, *odd, *even;
	while(from = input_list()){
		printf("Исходный список \n");
		print_list(from);
		oddeven_list(from,&odd,&even);
		
		sort(even,0);
		sort(odd,1);
		merge_list(odd, even);

		printf("Отсортированный результирующий список: \n");
		print_list(odd);

		free_list(from);
		free_list(even);

	}
	return 0;
}

struct Item * input_list(){
	struct Item *head = NULL, *cur, *tmp;
	int n;
	char *err="";
	do {
		printf("%s",err);
		printf("Введите кол-во элементов от 1 до 20 \n");
		err="Повторите ввод \n";
		scanf("%d", &n);
	} while(n<0||n>20);
	while(n-- > 0) {
		tmp = malloc(sizeof(struct Item));
		printf("Введите элемент: ");
		scanf("%d", &tmp->a);
		tmp->next = NULL;
		if (head == NULL) {
			head = cur = tmp;
		} else {
			cur->next = tmp;
			cur = cur->next;
		}
	}
	return head;
}

void print_list(struct Item *p){
	
	for(;p;p=p->next){
	printf("%d ",p->a);
	printf("\n");}
}

void free_list(struct Item *p){
	struct Item *tmp;
	while(p){
		tmp=p;
		p=p->next;
		free(tmp);
	}
}

void oddeven_list(struct Item *p, struct Item **to1, struct Item **to2){
	for(;p;p=p->next)
		if((p->a)<0){
			*to1=malloc(sizeof(struct Item));//
			(*to1)->a=p->a;
			(*to1)->next=NULL;
			to1=&(*to1)->next;
		}else if ((p->a)>0){
			*to2=malloc(sizeof(struct Item));//
			(*to2)->a=p->a;
			(*to2)->next=NULL;
			to2=&(*to2)->next;
		}
}

void sort_list(struct Item *p){
	struct Item *i,*j,*min;
	int tmp;
	for(i=p;i&&i->next;i=i->next){
		for(min=i, j=i->next;j;j->next)
			if(j->a<min->a) min=j;
		tmp=i->a;
		i->a=min->a;
		min->a=tmp;
}
}

void sort(struct Item *begin, int asc){
	struct Item *p, *q;
	for(p=begin; p!=NULL;p=p->next){
		for(q=p->next; q!=NULL;q=q->next){
			if(asc*p->a>asc*q->a){
				swap(p,q);
			}
		}
	}
}

void swap(struct Item *elem1, struct Item *elem2){
	int tmp;
	tmp=elem1->a;
	elem1->a = elem2->a;
	elem2->a=tmp;
}

void merge_list(struct Item *p, struct Item *q){
	struct Item *tmp;
	if(p==NULL||!q)return;
	for(;p&&p->next;p=p->next);
	for(;q;q=tmp){
		tmp=q->next;
		q->next=p->next;
		p->next=q;
	}
}
