#include"List.h"
#include<conio.h>
/*

TODO:

operator+;
operator+=;

Done:
В класс List (Двусвязный список) добавить методы:
insert();
CopyMethods;
MoveMethods;
push_back();
pop_front();
pop_back();
erase();
~List();



*/
//#define EXE
//#define COPY
//#define ISITWORK
void main() 
{



	List<int> kel = { 3, 5, 8, 13, 21 };

	for(List<int>::Iterator it = kel.begin();it; ++it)
	{
		cout << *it << endl;
	}	
	for(List<int>::Iterator it = kel.end();it; --it)
	{
		cout << *it << endl;
	}
	

	
	

	
#ifdef ISITWORK	

	List<int>work;
	for (int i = 0; i < 5; i++)
	{
		work.push_back(i);
		work.push_front(i);
	}
	work.clear();
	for (int i = 0; i < 5; i++)
	{
		work.pop_back();
		work.pop_front();
	}
	work.clear();
	work.erase(0);


#endif // ISITWORK


#ifdef COPY
	List<const char> a1(1, 'a'), b1(a1), a2;
	a2 = a1;
	a1.print();
	a2.print();
	b1.print();


#endif // COPY


#ifdef EXE

	

	//int size = 10;
	cout << "enter size: "; //cin >> size;

	List<int> exe;
	for (int i = 0; i < 10; i++)
	{
		exe.push_back(i);
	}

	system("cls");
	char choise;
	int Data;
	size_t index;
	while (true)
	{
		exe.print();

		cout << "1.pop_back 2.pop_front 3.push_back 4.push_front 5.erase 6.insert 8.clear" << endl;

		choise = _getch();

		if (choise == '5' || choise == '6')
		{
			cout << "enter index >> "; cin >> index;
		}
		 if (choise == '3' || choise == '4' || choise == '6')
		{
			cout << "enter value >> "; cin >> Data;
		}


		switch (choise)
		{
		case '1': exe.pop_back();
			break;

		case '2': exe.pop_front();
			break;

		case '3': exe.push_back(Data);
			break;

		case '4': exe.push_front(Data);
			break;

		case '5': exe.erase(index);
			break;

		case '6': exe.insert(index, Data);
			break;

		case '8':exe.clear();
			break;

		}
		system("cls");
	}


#endif // EXE

																				
}