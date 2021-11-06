#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class Stack
{

private:
    int iStackSize;
    int iStackIndex;
    T *tItem;

public:
    Stack(int size)
    {
        this->iStackSize = size;
        this->iStackIndex = -1;
        tItem = (T *)calloc(size, sizeof(T));
    }

    bool isFull()
    {
        if (this->iStackIndex >= this->iStackSize - 1)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (this->iStackIndex < 0)
            return true;
        else
            return false;
    }

    bool push(const T &element)
    {
        if (this->isFull())
        {
            printf("Stack Overflow...\n");
            return false;
        }
        this->iStackIndex++;
        memcpy(&(this->tItem[this->iStackIndex]), &element, sizeof(T));
        return true;
    }

    T pop()
    {
        T temp;
        memset(&temp, '\0', sizeof(T));
        if (this->isEmpty())
        {
            printf("Stack Underflow\n");
            return temp;
        }

        memcpy(&temp, &(this->tItem[this->iStackIndex]), sizeof(T));
        this->iStackIndex--;
        return temp;
    }

    T at(int i)
    {
        T temp;
        memset(&temp, '\0', sizeof(T));
        if (this->isEmpty())
        {
            printf("Stack Underflow\n");
            return temp;
        }
        else if (i > this->iStackIndex)
        {
            printf("Stack contain value till %d index\nReturn Value contains [NULL]\n", this->iStackIndex);
            return temp;
        }

        memcpy(&temp, &(this->tItem[i]), sizeof(T));
        return temp;
    }
};

struct Person
{
    int id;
    string name;
};


int main()
{
    int size = 5;
    Stack<Person> A(size);

    Person p;
    p.id = 23;
    p.name = "Adarsh";

    A.push(p);
    Person temp = A.at(2);
    cout << temp.id << " " << temp.name<<endl;

    return 0;
}