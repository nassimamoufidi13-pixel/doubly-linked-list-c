# include<stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;
 
 
void printList(node *head) {
    node *temp = head;
 
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
 
    printf("NULL\n");
}
 
 
/* ---------- Exercise 2 ---------- */
 
void insertAtBeginning(node **head, int value) {
    node *newnode = malloc(sizeof(node));
 
    if (newnode == NULL) {
        return;
    }
 
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = *head;
 
    if (*head != NULL) {
        (*head)->prev = newnode;
    }
 
    *head = newnode;
}
 
 
void insertAtEnd(node **head, int value) {
    node *newnode = malloc(sizeof(node));
 
    if (newnode == NULL) {
        return;
    }
 
    newnode->data = value;
    newnode->next = NULL;
 
    if (*head == NULL) {
        newnode->prev = NULL;
        *head = newnode;
        return;
    }
 
    node *temp = *head;
 
    while (temp->next != NULL) {
        temp = temp->next;
    }
 
    temp->next = newnode;
    newnode->prev = temp;
}
 
 
void insertAfter(node *head, int value, int target) {
    node *temp = head;
 
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
 
    if (temp == NULL) {
        printf("the value %d is not fount.\n", target);   
        return;
    }
 
    node *newnode = malloc(sizeof(node));
 
    if (newnode == NULL) {
        return;
    }
 
    newnode->data = value;
    newnode->prev = temp;
    newnode->next = temp->next;
 
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
 
    temp->next = newnode;
}
 
 
/* ---------- Exercise 3 ---------- */
 
void deleteAtBeginning(node **head) {
    if (*head == NULL) {
        printf("the linked list is empty.\n");
        return;
    }
 
    node *temp = *head;
    *head = temp->next;
 
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
 
    free(temp);
}
 
 
void deleteAtEnd(node **head) {
    if (*head == NULL) {
        printf("the linked list is empty.\n");
        return;
    }
 
    node *temp = *head;
 
    while (temp->next != NULL) {
        temp = temp->next;
    }
 
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;         
    }
 
    free(temp);
}
 
 
void deleteNode(node **head, int target) {
    node *temp = *head;
 
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
 
    if (temp == NULL) {
        return;
    }
 
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;    
    }
 
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
 
    free(temp);
}
 
 
/* ---------- Exercise 4 ---------- */
 
node *searchNode(node *head, int target) {
    node *temp = head;
 
    while (temp != NULL) {
        if (temp->data == target) {
            return temp;
        }
        temp = temp->next;
    }
 
    return NULL;
}
 
 
/* ---------- Exercise 5 ---------- */
 
void traverseForward(node *head) {
    node *temp = head;
 
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
 
    printf("\n");
}
 
 
void traverseBackward(node *tail) {
    node *temp = tail;
 
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
 
    printf("\n");
}
 
 
void freeList(node *head) {
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}
 
 
int main() {
    node *head = NULL;
 
    /* Exercise 2 */
    printf("--- Exercise 2 ---\n");
    insertAtBeginning(&head, 15);
    printList(head);
 
    insertAtBeginning(&head, 10);
    printList(head);
 
    insertAtEnd(&head, 20);
    printList(head);
 
    insertAtEnd(&head, 25);
    printList(head);
 
    insertAtEnd(&head, 30);
    printList(head);
 
    insertAfter(head, 17, 15);
    printList(head);
 
    /* Exercise 3 */
    printf("\n--- Exercise 3 ---\n");
    deleteAtBeginning(&head);
    printList(head);
 
    deleteAtEnd(&head);
    printList(head);
 
    deleteNode(&head, 20);
    printList(head);
 
    /* Exercise 4 */
    printf("\n--- Exercise 4 ---\n");
    int cibles[] = {25, 17};
 
    for (int i = 0; i < 2; i++) {
        node *res = searchNode(head, cibles[i]);
 
        if (res != NULL) {
            printf("the value %d is found.\n", cibles[i]);
        } else {
            printf("the value %d  is not found.\n", cibles[i]);
        }
    }
 
    /* Exercise 5 */
    printf("\n--- Exercise 5 ---\n");
    printf("Forward traversal:");
    traverseForward(head);
 
    node *tail = head;
    while (tail != NULL && tail->next != NULL) {
        tail = tail->next;
    }
 
    printf("Backward traversal: ");
    traverseBackward(tail);
 
    freeList(head);
    return 0;
}
 