#include"List.h"
/*

TODO:
В класс List (Двусвязный список) добавить методы:
push_back();
pop_front();
pop_back();
insert();
erase();

~List();
CopyMethods;
MoveMethods;
operator+;
operator+=;

*/
void main()
{
	List<int> a;
	//for (size_t i = 0; i < 5; i++)
	//{
	//	a.push_front(i);
	//		
	//}
	a.push_back(999);
	a.push_back(999);
	a.push_back(999);
	a.pop_front();
	a.pop_front();
	a.pop_front();
	a.pop_front();

	a.print();
	a.print_revers();
	cout << endl;

																				
}