#ifndef LinkedList_H
#define LinkedList_H

template <typename T>
class LinkedList 
{
    struct Node
    {
        T value;
        Node* next;
        Node* prev;
    };

    Node *sentinel
  public:
    LinkedList();
    ~LinkedList();
    Node* getHead() { return head; }
    void push_front(T);
    void push_back(T);
    T pop_front();
    T pop_back();
    bool find(T);
}

#endif // LinkedList_H