#ifndef LinkedList_H
#define LinkedList_H

#include <cstdlib>

template <typename T>
class LinkedList 
{
    struct Node
    {
        T val;
        Node* next;
        Node* prev;
    };

    Node *sentinel;
  public:
    LinkedList();
    ~LinkedList();
    void push_front(T);
    void push_back(T);
    T pop_front();
    T pop_back();
    bool find(T);
};

template <typename T>
LinkedList<T>::LinkedList()
{
  Node *sentinel = (Node*)malloc(sizeof(Node));
  sentinel->val = NULL;
  sentinel->next = sentinel;
  sentinel->prev = sentinel;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  Node *curr = sentinel->next;
  while (curr != sentinel) {
    Node *temp = curr;
    free(temp);
    curr = curr->next;
  }
  free(sentinel);
}

template <typename T>
void LinkedList<T>::push_front(T val)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->val = val;
  node->next = sentinel->next;
  node->prev = sentinel;
  sentinel->next = node;
}

template <typename T>
void LinkedList<T>::push_back(T val)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->val = val;
  node->next = sentinel;
  node->prev = sentinel->prev;
  sentinel->prev = node;
}

template <typename T>
T LinkedList<T>::pop_front()
{
  Node *node = sentinel->next;
  T val = node->val;
  node->next->prev = sentinel;
  sentinel->next = node->next;
  free(node);
  return val;
}

template <typename T>
T LinkedList<T>::pop_back()
{
  Node *node = sentinel->prev;
  T val = node->val;
  node->prev->next = sentinel;
  sentinel->prev = node->prev;
  free(node);
  return val;
}

template <typename T>
bool LinkedList<T>::find(T val)
{
  Node *curr = sentinel->next;
  while (curr != sentinel)
  {
    if (curr->val == val) return true;
  }
  return false;
}

#endif // LinkedList_H