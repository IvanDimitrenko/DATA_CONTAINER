 #include"Forward_list.h"
using namespace Forward_List;
#include<vector>
#include<forward_list>

/*
TODO:
Add to the ForwardList class:


4. Operator +, which will concatenate lists;
5. MoveMethods;



Done:
1. Destructor;
2. Copy constructor;
3. The assignment operator;
4. pop_front - removes the starting element;
5. pop_back - removes the last item;
6. insert - inserts the value at the index;
7. erase - deletes the value by index;
8. Operator [];
9. ForwardList list {3, 5, 8, 13, 21}; for (int i = 0; i <list.size; i ++) cout << list [i] << tab; cout << endl;
10. Constructor for a given number of elements ForwardList list (5), elements must be filled with zeros;


*/

void main()
{

	/*
		int n = 10;

		ForwardList <char>lst(n);

		for (int i = 0; i < n; i++)
		{
			lst[i] = i + '0' - 'a';
		}

		for (int i = 0; i < n; i++)
		{
			cout << "lst[" << i << "] = " << lst[i] << endl;
		}


		ForwardList<char>copy(lst);

		for (int i = 0; i < n; i++)
		{
			cout << "copy[" << i << "] = " << copy[i] << endl;
		}
	*/

	//	ForwardList<const char*>str = {"Hello","World","!"};
		//cout << str;
	ForwardList<int>ctr = { 1 };
	//cout << ctr;
//	cout << "\n---------------------------------------\n";
	ForwardList<int> copy_ctr;
	copy_ctr = ctr;
	cout << copy_ctr;

	ForwardList<const char*> copy_move = ForwardList<const char*>(10);
	cout << copy_move;
	/*	for (size_t i = 0 ;   i < copy_move.get)
	{

	}*/
	

	/*
	size_t n;

	cout << "Input size >> ";

	cin >> n;

	int value;
	size_t index;
	char choise;

	ForwardList<int> list;

	for (size_t i = 0; i < n; i++)
	{
		list.push_front(rand() % 30 + 5);
	}
	do
	{
		system("cls");
		list.print();
		cout << "\n\nWhat operation do you want to do:\n\t1.push_back\n\t2.push_front\n\t3.pop_back"
			<< "\n\t4.pop_front\n\t5.insert\n\t6.erase\n\t7.clear\n\t8.Set Element\n >> ";

		choise = _getch();

		if (choise == '1' || choise == '2' || choise == '5' || choise == '8')
		{
			cout << "\nEnter value >> ";  cin >> value;
		}
		if (choise == '6' || choise == '5' || choise == '8')
		{
			cout << "\nEneter index >> "; cin >> index;
		}
		switch (choise)
		{
		case '1': list.push_back(value); break;
		case '2': list.push_front(value); break;
		case '3': list.pop_back(); break;
		case '4': list.pop_front(); break;
		case '5': list.insert(index, value); break;
		case '6': list.erase(index); break;
		case '7': list.clear(); break;
		case '8': list[index] = value; break;
		case 'q': return;
		}

	} while (true);

	*/
}