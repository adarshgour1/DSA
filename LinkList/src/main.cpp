#include <iostream>
#include "Logger.hpp"
#include "link_list.cpp"

using namespace std;

int main()
{

	link_list<int> ls;
	ls.insert(2);
	ls.insert(3);
	ls.insert(4);
	ls.insert(5);
	ls.insert(2, 2);
	Log << "size: " << ls.getNoOfElementInList();
	int a = ls.getElementByIndex(0);
	Log << a;
	a = ls.getElementByIndex(1);
	Log << a;
	a = ls.getElementByIndex(2);
	Log << a;
	a = ls.getElementByIndex(3);
	Log << a;
	a = ls.getElementByIndex(4);
	Log << a;
	a = ls.getElementByIndex(5);
	Log << a;
	return 0;
}