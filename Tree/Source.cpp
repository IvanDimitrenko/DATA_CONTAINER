#include"Tree.h"


//#define COPY_INSERT_DESTRUCTOR_ITD
#define ERASE
void main()
{


#ifdef COPY_INSERT_DESTRUCTOR_ITD

	Tree<int> first_tree = { 3,2,5 };


	for (int i = 0; i < 10; i++)
	{
		first_tree.plant_leaf(i);
	}
	first_tree.show();
	Tree<int> copy(first_tree);
	

#endif // COPY_INSERT_DESTRUCTOR_ITD

#ifdef ERASE

	//Tree<int> zd = { 13,15,20,70,8 };
	Tree<int> zd = {50, 80 , 60 ,120 ,100, 40, 45,30};

	zd.show();
	zd.erase(30);
	zd.show();


#endif //ERASE


/*	Tree<char> r1 = { '1','2','3','4' }, r2;
	r1 = r1;
	r1.show();
	*/


}