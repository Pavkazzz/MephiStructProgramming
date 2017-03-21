#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char ch;
    struct Node* next;
} Node;

char* input_string();
Node* string_to_list(char* str);
void print_list(Node** head);
void erase_list(Node** head);
void remove_symbol(Node* node);
void remove_delim(Node** head);
void in_brackets(Node** head);
void add_format(Node** head);
void add_symb(Node *head, char symb);

char* input_string() {

    char s[300];
    int si = 0;
    printf("Введите строки, до признака конца файла(CTRL+D):\n");
    scanf("%[^EOF]s", &s);

    while(s[si++] != NULL) { }

    char *str = (char *) calloc(si, sizeof(char));
    memcpy(str, &s, si * sizeof(char));

    return str;
}

Node* string_to_list(char* str) {
    Node* head = NULL;
    Node* last = NULL;
    Node* tmp = NULL;
    char* str_tmp = str;
    while(*str_tmp != '\0') {
        tmp = (Node*) calloc(1, sizeof(Node));
        tmp->ch = *str_tmp++;
        tmp->next = NULL;
        if(head == NULL) {
            head = tmp;
            last = head;
        } else {
            last->next = tmp;
            last = tmp;
        }
    }
    return head;
}

void print_list(Node** head) {

    printf("\nprint list\n");

    Node *node = *head;

    int i=0;
    while(node != NULL) {
        i++;

        if (node->ch == '\n') {
            printf("\n");
        } else {
            printf("%c", node->ch);
        }
        node = node->next;
    }
    printf("\n");
}

void erase_list(Node** head) {
    Node* prev = NULL;
    while((*head)->next != NULL) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}

void add_symb(Node* head, char symb) {

    if (head != NULL) {
        return ;
    }
    Node *s_node;
    s_node = (Node *) calloc(1, sizeof(Node));
    s_node->ch = symb;
    s_node->next = head->next;
    head->next = s_node;
}

void remove_symbol(Node* node) {
    if (node == NULL) {
        return ;
    }
    if (node->next == NULL) {
        return ;
    }

    memcpy(node, node->next, sizeof(Node));
}

void remove_delim(Node** head) {
    int space = 0;
    int ch = 0;
    Node* new_list = NULL;
    Node* tmp = (*head);
    while(tmp != NULL) {

        if (tmp->next != NULL) {
            if (tmp->next->ch != ' ' && tmp->next->ch != '\n' && tmp->ch != ' ') {
                remove_symbol(tmp);
            } else {
                tmp = tmp->next;
            }
        } else {
            tmp = tmp->next;
        }

    }
}

int main() {
    char* str = NULL;
    Node* head = NULL;
    str = input_string();
    head = string_to_list(str);
    remove_delim(&head);
    print_list(&head);
    erase_list(&head);
    free(str);

    return 0;
}
