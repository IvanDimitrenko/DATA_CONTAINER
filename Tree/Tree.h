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
//#define PRINT_ITERATOR
//#define PRINT_TREE
#define PRINT_LEAF


	class Leaf
	{
		template<class T> friend class Tree;
		T Data;
		Leaf*pLeft;
		Leaf*pRight;

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
	Leaf* Root;
	size_t size;

public:

//	class iterator
//	{
//
//		Leaf* it;
//
//	public:
//
//		iterator(Leaf* it = nullptr): it(it)
//		{
//#ifdef PRINT_ITERATOR
//			cout << "ItConstructor >> \t" << this << endl;
//#endif // PRINT_ITERATOR
//		}
//
//		~iterator()
//		{
//#ifdef PRINT_ITERATOR
//			cout << "ItDestructo >> \t" << this << endl;
//#endif // PRINT_ITERATOR
//
//		}
//
//		operator bool()
//		{
//			return it;
//		}
//
//		iterator operator++()
//		{
//			if (it->pLeft)
//			{
//				return this->it->pLeft;
//			}
//			else if (it->pRight)
//			{
//				return this->it->pRight;
//			}
//			return this->it;
//		}
//
//
//	};

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
		for (const auto& i : list)
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

	void destroy_tree(Leaf* it)
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
		if (!size) this->Root = new Leaf(Data);
		else this->plant_leaf(Data, Root);
		size++;
	}

	void show()const
	{
		show(this->Root);
		cout << "size >> " << this->size << endl;
	}

	Leaf* binary_search(T Data) { return binary_search(Data, Root); }

	T max(Leaf* it)
	{
		
		for (; it->pRight; it = it->pRight);
		//return Root ? 

		return it->Data;
	}
	T min(Leaf* it)
	{
		for ( ; it->pLeft; it = it->pLeft);
		return it->Data;
	}
	T sum()
	{
		if (!size)return NULL;
		return sum(this->Root);
	}

	size_t Size()
	{
		return Size(this->Root);
	}
	/*void erase(T Data)
	{
		erase(Data, this->Root);
	}*/

	void erase(T Data)
	{
		erase(Data, this->Root);
	}

		Leaf* get_root()const 
		{
			return this->Root; 
		}
	
private:

	void erase(T Data, Leaf* it)
	{

		Leaf* to_delete = binary_search(Data, it);

		if (to_delete->pLeft == to_delete->pRight)
		{
			Leaf* perent = parent(to_delete->Data, this->Root);
			perent->pLeft ? perent->pLeft = nullptr : perent->pRight = nullptr;
			delete to_delete;
		}

		else if (to_delete->pLeft && to_delete->pRight)
		{
			Leaf* new_Root = minL(to_delete->pRight);
			to_delete->Data = new_Root->Data;
			erase(to_delete->Data, to_delete->pRight);
		}

		else
		{
			Leaf* perent = this->parent(Data, this->Root);
			Leaf* child = (to_delete->pLeft ? to_delete->pLeft : to_delete->pRight);
			perent->pLeft == to_delete ? perent->pLeft = child : perent->pRight = child;
			delete to_delete;

		}
	}

	Leaf* minL(Leaf* it)
	{
		for (; it->pLeft; it = it->pLeft);
		return it;
	}



	Leaf* parent(T Data, Leaf* it)
	{
		if (it)
		{
			if (Data == it->pRight->Data || Data == it->pLeft->Data) { return it; }

			if (Data < it->Data) return binary_search(Data, it->pLeft);

			else return binary_search(Data, it->pRight);
		}
		else return nullptr;
	}

	/*Leaf* parent(Leaf* child  , Leaf* it)
	{

		    if (it) return nullptr;
		
			if (child == it->pRight || child == it->pLeft) { return it; }

			  binary_search(child, it->pRight);
			  binary_search(child, it->pLeft);
	}*/
	

    Leaf* binary_search(T Data, Leaf* it)
	{
		if (it)
		{
			if (Data == it->Data) {return it;}

			if (Data < it->Data) return binary_search(Data, it->pLeft);

			else return binary_search(Data, it->pRight);
		}
		else return nullptr;	
	}
	Leaf* binary_search(Leaf* ref, Leaf* it)
	{
		if (it)
		{
			if (ref == it) {return it;}

			binary_search(ref, it->pLeft);
			binary_search(ref, it->pRight);		
		}	
	}

	/*Leaf* binary_search(T Data, Leaf* it)
	{
		counter++;
		if (it)
		{
			if (Data == it->pLeft->Data) {return it;}

			if (Data < it->pRight->Data) return binary_search(Data, it->pLeft);

			else return binary_search(Data, it->pRight);
		}
		else return nullptr;
		
	}*/

	void show(Leaf* it)const // print()
	{	
		if (it) 
		{
			show(it->pLeft);
			cout << it->Data << "\t";	
			show(it->pRight);
		}	  
	}

	void plant_leaf(T Data, Leaf* it)
	{
		if (Data >= it->Data)
		{
			if (it->pRight) plant_leaf(Data, it->pRight);
			else it->pRight = new Leaf(Data);
		}
		else if (Data < it->Data)
		{
			if (it->pLeft) plant_leaf(Data, it->pLeft);
			else it->pLeft = new Leaf(Data);
		}
	}

	void copy(Leaf* it)
	{
		if (it)
		{
			this->plant_leaf(it->Data);
			copy(it->pLeft);
			copy(it->pRight);
		}
	}

	T sum(Leaf*	it)
	{
		if (!it) return 0;
		if (it->Left == it->pRight)return it->Data;
		return sum(it->pLeft) + sum(it->pRight) + it->Data;		
	}
	size_t Size(Leaf*it)
	{
		if (!it) return 0;
		else if (it->pLeft == it->pRight)return 1;
		return Size(it->pLeft) + Size(it->pRight) + 1;
	}
};












