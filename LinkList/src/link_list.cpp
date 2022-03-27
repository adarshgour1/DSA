#include "link_list.hpp"
/**
 * @brief use to insert data last of linked list
 * 
 * @param item datatype to store
 * @return true on success
 * @return false on failure
 */
template <class T>
bool link_list<T>::insert(const T &item)
{
    if (head.next == nullptr)
    {
        Log << "Assing to head";
        Node<T> *obj = new Node<T>;
        head.next = obj;
        Log << "New node assing to head " << &head;
        head.data = item;
        this->size++;
        return true;
    }
    else
    {
        Log << "Inside else condition";
        Node<T> *temp = &head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->data = item;
        temp->next = new Node<T>;
        this->size++;
    }
    return true;
}

/**
 * @brief use to store data in linked list at mention index
 * 
 * @tparam T 
 * @param item data to be store
 * @param index index location start with 0
 * @return true on success
 * @return false on failure
 */
template <class T>
bool link_list<T>::insert(const T &item, const int &index)
{
    if(size<index)
        return false;
    Node<T> *temp = &head;
    for (int i = 0; i < index-1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }
    Node<T> *current = temp->next;
    temp->next = new Node<T>;
    temp = temp->next;
    temp->data = item;
    temp->next = current;
    this->size++;
    return true;
}
/**
 * @brief return element in list at given index
 * 
 * @tparam T datatype
 * @param index index start with 0
 * @return const T 
 */
template <class T>
const T link_list<T>::getElementByIndex(const int &index)
{
    if (index >= size)
        return -1;
        
    Node<T> *temp = &head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}
/**
 * @brief return no of element in list
 * 
 * @tparam T 
 * @return int 
 */
template <class T>
int link_list<T>::getNoOfElementInList()
{
    return this->size;
}

/**
 * @brief Destroy the link list<T>::link list object
 * 
 * @tparam T 
 */
template <class T>
link_list<T>::~link_list()
{
    Log << "Destructor called";
    Node<T> *current = head.next;
    for (int i = 0; i < size; i++)
    {
        Node<T> *next = current->next;
        Log << "deleting for address " << current;
        delete current;
        current = next;
    }
}