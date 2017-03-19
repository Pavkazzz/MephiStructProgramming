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
void add_symb(Node* head, char symb);
bool check_bad(Node* node);

char* input_string() {

    char s[300];
    int si = 0;
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
    free(str);
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
    if (head == NULL) {
        return ;
    }
    if (head->next == NULL) {
        return ;
    }
    Node *s_node = (Node *) calloc(1, sizeof(Node));
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

bool check_bad(Node *node) {
    if (node == NULL) {
        return false;
    }
    if (node->next == NULL) {
        return false;
    }
    if (node->ch == ' ' || node->ch == '\t' || node->ch == ',' || node->ch == ';' || node->ch == '.') {
        return true;
    }
    return false;
}

void remove_delim(Node** head) {
    int space = 0;
    int ch = 0;
    bool first = false;
    Node* tmp = (*head);
    while(tmp != NULL) {

        if (tmp->ch == '.') {
            add_symb(tmp, '\n');
        }

        if (check_bad(tmp) && (check_bad(tmp->next) || first)) {
            remove_symbol(tmp); // tmp = tmp->next;

        } else {

            if (tmp->ch == '.') {
                first = true;
            }

            tmp = tmp->next;
        }

    }
}

void add_format(Node** head) {
    Node* tmp = (*head);
    while(tmp != NULL) {
        if (tmp->ch == ' ') {
            add_symb(tmp, ' ');
            add_symb(tmp, ',');
            remove_symbol(tmp);
            tmp = tmp->next;
            tmp = tmp->next;
        } else {
            tmp = tmp->next;
        }
    }
}

int main() {
    char* str = NULL;
    Node* head = NULL;
    str = input_string();
//    printf("%s", str);
    head = string_to_list(str);
    remove_delim(&head);
    add_format(&head);
    print_list(&head);
    erase_list(&head);

    // while((str = input_string()) != NULL) {
    // }

    return 0;
}
