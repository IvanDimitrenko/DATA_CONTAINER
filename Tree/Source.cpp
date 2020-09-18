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

	Tree<int> zd = {10,15,20,13,25};/*{50,60,70,65,75,55,56};*/

	//Tree<int> s(zd);
	
	zd.erase(15);

	zd.show();



}