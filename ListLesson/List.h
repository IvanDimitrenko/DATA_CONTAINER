#pragma once

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

class List
{
//#define PRINT

	class Element
	{
		friend class List;

		int Data;
		Element* pNext;
		Element* pPrev;

	public:
		Element(int Data,  Element* pNext = nullptr, Element* pPrev = nullptr ) :Data(Data), pNext(pNext), pPrev(pPrev)
		{
#ifdef PRINT
			cout << "EConstructor:\t" << this << endl;
#endif // PRINT
		}
		~Element()
		{
#ifdef PRINT
			cout << "EDestructor:\t" << this << endl;
#endif // PRINT
		}
	};

public:

	Element* Head;
	Element* Tail;
	int size;



	List()
	{
		Head = Tail = nullptr;
#ifdef PRINT
		cout << "LConstructor\t" << this;
#endif // PRINT
	}



	~List()
	{
#ifdef PRINT
		cout << "LDestructor:\t" << this;
#endif // PRINT

	}

	void push_front(int Data = NULL)
	{
		
		Element* New = new Element(Data, this->Head);
		 
		 !Head ? Tail = Head = New : Head = (New->pNext = Head)->pPrev = New;

		

	}

	void pop_front()
	{
		
	}

	void print()
	{	
		for (Element* it = this->Head;it != nullptr; it = it->pNext)
		{
			cout << it << "\t" << it->Data << "\t" << it->pNext << endl;
		}
	}
	void print_revers()
	{
		for (Element* it = this->Tail; it ; it = it->pPrev)
		{
			cout << it << "\t" << it->Data << "\t" << it->pPrev << endl;
		}
	}

	int as()
	{
	
	}
		
};








