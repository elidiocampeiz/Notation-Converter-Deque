#ifndef DLIST_HPP
#define DLIST_HPP
#include "DList_node.hpp"
#include <string>
//the purpose of this program is to implement an Deque Class extending from a Double linked list
class MyDeque
{
public:
    MyDeque();
    ~MyDeque();
    bool isEmpty() const
    {
        return ListHead->next == ListHead;
    }
    void push(std::string a);
    void push_back(std::string a);

    void pop();
    void pop_back();

    std::string top();
    std::string back();
    //string addToString() const;

protected:
    DLLNode<std::string> *ListHead;
    //DLLNode *ListTail;
};

#endif /* DLIST_H */
