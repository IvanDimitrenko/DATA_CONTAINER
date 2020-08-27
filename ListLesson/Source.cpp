#include"List.h"

void main()
{
	int n = 5;
	List a;
	
	for (int i = 0; i < n; i++)
	{
		a.push_front(i);
	}

	a.print_revers();
	cout << endl;
	a.print();

	

	system("pause");
	

}
