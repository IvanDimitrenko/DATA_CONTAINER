#pragma once
#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::cin;
int counter = 0;

template<class T>class Tree;
template<class T>class Leaf;

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

		Leaf(T Data = NULL, Leaf* pLeft = nullptr, Leaf* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
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

	class iterator
	{

		Leaf<T>* it;

	public:

		iterator(Leaf<T>* it = nullptr): it(it)
		{
#ifdef PRINT_ITERATOR
			cout << "ItConstructor >> \t" << this << endl;
#endif // PRINT_ITERATOR
		}

		~iterator()
		{
#ifdef PRINT_ITERATOR
			cout << "ItDestructo >> \t" << this << endl;
#endif // PRINT_ITERATOR

		}

		operator bool()
		{
			return it;
		}

		iterator operator++()
		{
			if (it->pLeft)
			{
				return this->it->pLeft;
			}
			else if (it->pRight)
			{
				return this->it->pRight;
			}
			return this->it;
		}


	};

	Tree()
	{
		this->Root = nullptr;
		this->size = 0;
#ifdef PRINT_TREE
		cout << "TDefPlant >> \t" << this << endl;
#endif // PRINT_TREE

	}

	Tree(const std::initializer_list<T>& list): Tree()
	{
		for (const auto i : list)
		{
			plant_leaf(i);
		}
	}
	Tree(const Tree& other) : Tree()
	{
		this->copy(other.Root);
	}
	~Tree()
	{
		destroy_tree(Root);
		cout << "TFelling >> \t" << this;
	}

	void destroy_tree(Leaf<T>* it)
	{
		if (it)
		{
			destroy_tree(it->pLeft);
			destroy_tree(it->pRight);
			delete it;
		}
	}

	void plant_leaf(T Data)		// Push_back(front) (*-*)
	{
		if (!size) this->Root = new Leaf<T>(Data);
		else this->plant_leaf(Data, Root);
		size++;
	}

	void show()const
	{
		show(this->Root);
		cout << "size >> " << this->size << endl;
	}
	Leaf<T>* binary_search(T Data) { return binary_search(Data, Root); }
	
private:

	Leaf<T>* binary_search(T Data, Leaf<T>* it)
	{
		counter++;
		if (it)
		{
			if (Data ==it->Data) { cout << endl << "---------------"   << Data << "--------------" << endl; return it; }

			if (Data < it->Data) return binary_search(Data, it->pLeft);

			else return binary_search(Data, it->pRight);
		}
		else return nullptr;
		
	}

	void show(Leaf<T>* it)const // print()
	{	
		if (it) 
		{
			show(it->pLeft);
			cout << it->Data << "\t";	
			show(it->pRight);
		}	  
	}

	void plant_leaf(T Data, Leaf<T>* it)
	{
		if (Data >= it->Data)
		{
			if (it->pRight) plant_leaf(Data, it->pRight);
			else it->pRight = new Leaf<T>(Data);
		}
		else if (Data < it->Data)
		{
			if (it->pLeft) plant_leaf(Data, it->pLeft);
			else it->pLeft = new Leaf<T>(Data);
		}
	}


	void copy(Leaf<T>*it)
	{
		if (it)
		{
			this->plant_leaf(it->Data);
			copy(it->pLeft);
			copy(it->pRight);
		}
	}
};












