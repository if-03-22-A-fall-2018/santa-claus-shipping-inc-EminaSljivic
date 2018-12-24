#include <stdlib.h>
#include "list.h"

struct _node{
  void* data;
  Node* next;
};

struct _list{
  Node* _head;
};

List* list_create(){
  return (List*)malloc(sizeof(List));
}
void list_delete(List *list){
  free(list);
}
void list_add(List *list, void *data){
  Node* newNode=(Node*)malloc(sizeof(Node));
  newNode->data=data;
  newNode->next=0;

  if(list->_head==0)
  {
    list->_head=newNode;
  }

  else
  {
    newNode->next=list->_head;
    list->_head=newNode;
  }
}
void list_insert_after(Node *node, void *data){
  Node* newNode=(Node*)malloc(sizeof(Node));
  newNode->data=data;
  newNode->next=0;

  newNode->next=node->next;
  node->next=newNode;
}
Node* list_get_first(List *list){
  return list->_head;
}
Node* list_get_next(Node *node){
  return node->next;
}
void* list_get_data(Node *node){
  return node->data;
}
