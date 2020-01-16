//           Doubly-linked list class to store  egers
#ifndef DLISTNODE_HPP
#define DLISTNODE_HPP

template <class T>
class DLLNode
{
public:
    T info;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(T el, DLLNode *ptr1 = 0,
            DLLNode *ptr2 = 0)
    {
        info = el;
        next = ptr1;
        prev = ptr2;
    }
    //declare a default constructor to the class
    DLLNode()
    {
        next = 0;
        prev = 0;
    }
};
#endif /*  DLISTNODE_H */
