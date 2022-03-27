#ifndef _LINKLIST_HPP
#define _LINKLIST_HPP

#include <iostream>
#include "Logger.hpp"
using namespace std;
/**
 * @brief This struct used in link_list class for creation of linked lint
 * 
 * @tparam T template variable type of data to store
 */
template <class T>
struct Node
{
    T data;
    Node *next = nullptr;
};

/**
 * @brief This is actual operator class on link list
 * Just creat obj of this class and start using it
 * 
 * @tparam T type of data
 */
template <class T>
class link_list
{
private:
    Node<T> head;
    int size = 0;

public:
    bool insert(const T &item);
    bool insert(const T &item,const int &index);
    const T getElementByIndex(const int &);
    int getNoOfElementInList();
    ~link_list();
    // void printList();
};
#endif