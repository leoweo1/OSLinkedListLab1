// list/list.c
// 
// Implementation for linked list.
//
// <Daniel Onwuka>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list.h"

list_t *list_alloc() { 
    list_t* mylist = (list_t *) malloc(sizeof(list_t)); 
    if (mylist != NULL) {
        mylist->head = NULL;
    }
    return mylist;
}

void list_free(list_t *l) {
    if (l == NULL) return;
    
    node_t *current = l->head;
    node_t *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(l);
}

void list_print(list_t *l) {
    if (l == NULL) {
        printf("List is NULL\n");
        return;
    }
    
    node_t *current = l->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

char * listToString(list_t *l) {
    if (l == NULL) {
        char* buf = (char *) malloc(sizeof(char) * 10);
        strcpy(buf, "NULL List");
        return buf;
    }
    
    char* buf = (char *) malloc(sizeof(char) * 1024);
    char tbuf[20];
    buf[0] = '\0';
    
    node_t* curr = l->head;
    while (curr != NULL) {
        sprintf(tbuf, "%d->", curr->value);
        strcat(buf, tbuf);
        curr = curr->next;
    }
    strcat(buf, "NULL");
    return buf;
}

int list_length(list_t *l) {
    if (l == NULL) return 0;
    
    int count = 0;
    node_t *current = l->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void list_add_to_back(list_t *l, elem value) {
    if (l == NULL) return;
    
    node_t *new_node = getNode(value);
    if (new_node == NULL) return;
    
    if (l->head == NULL) {
        l->head = new_node;
        return;
    }
    
    node_t *current = l->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
    if (l == NULL) return;
    
    node_t *new_node = getNode(value);
    if (new_node == NULL) return;
    
    new_node->next = l->head;
    l->head = new_node;
}

node_t * getNode(elem value) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = NULL;
    }
    return new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
    if (l == NULL || index < 1) return; // 1-based indexing
    
    if (index == 1) {
        list_add_to_front(l, value);
        return;
    }
    
    node_t *new_node = getNode(value);
    if (new_node == NULL) return;
    
    node_t *current = l->head;
    int i = 1; // Start counting from 1
    
    // Find the node at position index-1 (1-based)
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    
    if (current == NULL) {
        free(new_node);
        return;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

elem list_remove_from_back(list_t *l) {
    if (l == NULL || l->head == NULL) return -1;
    
    elem value;
    
    // If there's only one node
    if (l->head->next == NULL) {
        value = l->head->value;
        free(l->head);
        l->head = NULL;
        return value;
    }
    
    // Find the second last node
    node_t *current = l->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    value = current->next->value;
    free(current->next);
    current->next = NULL;
    return value;
}

elem list_remove_from_front(list_t *l) {
    if (l == NULL || l->head == NULL) return -1;
    
    node_t *temp = l->head;
    elem value = temp->value;
    l->head = l->head->next;
    free(temp);
    return value;
}

elem list_remove_at_index(list_t *l, int index) {
    if (l == NULL || l->head == NULL || index < 1) return -1; // 1-based indexing
    
    if (index == 1) {
        return list_remove_from_front(l);
    }
    
    node_t *current = l->head;
    int i = 1; // Start counting from 1
    
    // Find the node before the one to remove (1-based)
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    
    if (current == NULL || current->next == NULL) {
        return -1;
    }
    
    node_t *temp = current->next;
    elem value = temp->value;
    current->next = temp->next;
    free(temp);
    
    return value;
}

bool list_is_in(list_t *l, elem value) {
    if (l == NULL) return false;
    
    node_t *current = l->head;
    while (current != NULL) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

elem list_get_elem_at(list_t *l, int index) {
    if (l == NULL || index < 1) return -1; // 1-based indexing
    
    node_t *current = l->head;
    int i = 1; // Start counting from 1
    
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    
    if (current == NULL) {
        return -1;
    }
    
    return current->value;
}

int list_get_index_of(list_t *l, elem value) {
    if (l == NULL) return -1;
    
    int index = 1; // Start counting from 1 (1-based indexing)
    node_t *current = l->head;
    
    while (current != NULL) {
        if (current->value == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    
    return -1;
}