#include "MyDeque.hpp"

//g++ -std=c++17 -Wall
//This program has the purpose of defining all the needed methods for the MyDeque class declared in Mydeque.hpp

//constructor
MyDeque::MyDeque()
{
    //initialize ListHead as a head/tail sentinel
    ListHead = new DLLNode<std::string>;
    //initially list is empty
    ListHead->next = ListHead; //next will pos to first node (head)
    ListHead->prev = ListHead; //prev will pos to last node (tail)
}

//destructor

MyDeque::~MyDeque()
{
    //properly destruct the list

    while (!isEmpty())
    {
        pop();
    }
    delete ListHead;
}
//add to front of deque

void MyDeque::push(std::string a)
{
    //create new node between head and first element
    DLLNode<std::string> *node = new DLLNode<std::string>(a, ListHead->next, ListHead);

    //update prev pointer, of Listhead->next(now the second node), to point to new node
    ListHead->next->prev = node;

    //update next pointer, of ListHead, to point to new node
    ListHead->next = node;
}

//add to the back

void MyDeque::push_back(std::string a)
{
    //declare new node between ListHead->prev and ListHead
    DLLNode<std::string> *node = new DLLNode<std::string>(a, ListHead, ListHead->prev);

    //update the header prev node's *next pointer point to the new node
    ListHead->prev->next = node;
    // update header *prev point to new node
    ListHead->prev = node;
}
//remove front
void MyDeque::pop()
{
    if (!isEmpty()) //if list not empty
    {
        DLLNode<std::string> *node = ListHead->next; //pointer to first node on list, which will be deleted
        //T a = node->info;                  // save node's info

        //update pointers to safely delete node
        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node; //delete first node on the list
        //return a;    //return its value
    }
    else //else, list is empty throw
    {
        throw;
    }
}
//remove from back

void MyDeque::pop_back()
{
    if (isEmpty()) //if list is empty throw
    {
        throw;
    }
    else // else
    {
        DLLNode<std::string> *node = ListHead->prev; //pointer to last node on list, which will be deleted
        //T a = node->info;                  //safe node's info

        //update pointers to safely delete node
        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node; //delete last node on the list
        //return a;    //return its value
    }
}
//return value at front
std::string MyDeque::top()
{
    if (!isEmpty())
    {
        /* code */
        return ListHead->next->info;
    }
    else
    {
        throw;
    }
}
//return value from back
std::string MyDeque::back()
{
    if (!isEmpty())
    {
        /* code */
        return ListHead->prev->info;
    }
    else
    {
        throw;
    }
}
