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

		Leaf(T Data = NULL, Leaf<T>*pLeft = nullptr, Leaf<T>pRight = nullptr)
			:  Data(Data),	pLeft(pLeft), pRight(pRight)
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
		cout << "TFelling >> \"
	}
	void plant_leaf(T Data)
	{
		if (size == 0)this->Root = new Leaf(Data);
		size++
	}


};












