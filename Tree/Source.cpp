#include"Tree.h"

void main()
{
	//Tree<int> first_tree;


/*	for (int i = 0; i < 10; i++)
	{
		first_tree.plant_leaf(i);
	}*/
//	first_tree.show();
	//cout << "\n-----------------------------\n";
	//first_tree.binary_search(999);
	//cout << "counter >> "  << counter ;
	//cout << endl << counter << endl;

	Tree<int> zd = {1,2,3,4,5,-1,-2,-3,-4,0,};
	Tree<int> s(zd);
	//Tree<int> s = { 1,2,3,4 };
	
	s.show();
	cout << endl;
	zd.show();

}