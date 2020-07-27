 #include"Forward_list.h"
using namespace Forward_List;
#include<vector>
#include<forward_list>

/*
TODO:
Add to the ForwardList class:
1. Destructor;
2. Copy constructor;
3. The assignment operator;
4. Operator +, which will concatenate lists;
5. MoveMethods;
6. Constructor for a given number of elements ForwardList list (5), elements must be filled with zeros;
7. Operator [];
8. ForwardList list {3, 5, 8, 13, 21}; for (int i = 0; i <list.size; i ++) cout << list [i] << tab; cout << endl;
DONE vse, krome erase:
1.pop_front - removes the starting element;
2. pop_back - removes the last item;
3. insert - inserts the value at the index;
4. erase - deletes the value by index;
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
 
	ForwardList<int>ctr = {1,2,1,1};



	
	/*size_t n;
	cout << "Input size >> ";
	cin >> n;
	int value;
	size_t index = 5;
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

	} while (true);*/

	
}