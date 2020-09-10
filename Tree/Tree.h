#pragma once
#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

template<class T>class Tree 
{
#define PRINT_ITERATOR
#define PRINT_TREE

#define PRINT_LEAF

	template<class T>class Leaf
	{
		template<class T> friend class Tree;
		T Data;
		Leaf<T>*pLeft;
		Leaf<T>*pRight;

	public:

		Leaf(T Data = NULL, Leaf* pLeft = nullptr, Leaf* pRight = nullptr): Data(Data),	pLeft(pLeft), pRight(pRight)
		{
#ifdef PRINT_LEAF
			cout << "LDefGrow >> \t" << this << endl;
#endif // PRINT_LEAF
		}
		
		
		~Leaf()
		{
#ifdef PRINT_LEAF
			cout << "LFallOff >> \t" << this << endl;
#endif // PRINT_LEAF
		}



	};
	Leaf<T>* Root;
	size_t size;

public:
	Tree()
	{
		this->Root = nullptr;
		this->size = 0;
#ifdef PRINT_TREE
		cout << "TDefPlant >> \t" << this << endl;
#endif // PRINT_TREE

	}
	~Tree()
	{

		cout << "TFelling >> \t" << this;
	}
	void plant_leaf(T Data)		// Push_back(front) (*-*)
	{
		Leaf<T>* New = new Leaf<T>(Data);
		Leaf<T>* Worm = Root;	// Iterator
		if (size == 0)this->Root = New;	
			else
			{
			//if(Worm->Data > New->Data)
				while (/*Worm->pLeft && Worm->pRight*/ Worm)
				{		
					if (New->Data > Worm->Data)Worm = Worm->pLeft;
					else Worm = Worm->pRight;			
				}
				Worm = New;
			}
			size++;
	}
	void show()		// print()
	{
		
		Leaf<T>* Worm = Root;
		for (int i = 0; i < this->size; i++)
		{
			
		}


};












