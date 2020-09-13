#include"Tree.h"

void main()
{
	Tree<int> first_tree;


	for (int i = 0; i < 10; i++)
	{
		first_tree.plant_leaf(i);
	}
	first_tree.show();
	cout << "\n-----------------------------\n";
	first_tree.binary_search(999);
	cout << "counter >> "  << counter ;
	cout << endl << counter << endl;
}