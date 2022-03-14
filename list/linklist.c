#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

typedef struct LinkList
{
    /* data */
    Node *header;
    int size;
} LinkList;

Node *
NewNode(int element, Node *node)
{
    Node *res = (Node *)malloc(sizeof(Node));
    res->element = element;
    res->next = node;
    return res;
}

LinkList *
NewList()
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    return list;
}

void Add(LinkList *list, int element)
{
    if (list->header == NULL)
    {
        list->header = NewNode(element, NULL);
        list->size++;
        return;
    }
    Node *node = list->header;
    Node *prev = list->header;
    while (node != NULL)
    {
        prev = node;
        node = node->next;
    }
    prev->next = NewNode(element, NULL);
    list->size++;
    return;
}

void print(LinkList *list)
{
    if (list->header == NULL)
    {
        return;
    }
    Node *node = list->header;
    while (node != NULL && node->next != NULL)
    {
        printf("value: %d, next: %d, \n", node->element, node->next->element);
        node = node->next;
    }
    return;
}

Node *
GetNode(LinkList *list, int element)
{
    if (list->header == NULL)
    {
        return NULL;
    }
    Node *node = list->header;
    while (node != NULL)
    {
        if (node->element == element)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void Remove(LinkList *list, int element)
{
    Node *removeNode = GetNode(list, element);
    if (removeNode == NULL)
    {
        return;
    }
    if (list->header == removeNode)
    {
        list->header = list->header->next;
        list->size--;
        return;
    }
    Node *prev = list->header;
    Node *node = list->header;
    while (node == NULL)
    {
        if (node->element == element)
        {
            break;
        }
        prev = node;
        node = node->next;
    }
    prev->next = removeNode->next;
    list->size--;
    return;
}

int main(int argc, char const *argv[])
{
    LinkList *list = NewList();
    for (int i = 0; i < 100; i++)
    {
        Add(list, i);
    }
    // for (int i = 0; i < 80; i++)
    // {
    //     /* code */
    //     Remove(list, i);
    // }
    print(list);
    return 0;
}

