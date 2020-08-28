#pragma once
#include<Windows.h>
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;



template<typename T> class List
{

#define ELEMENT_PRINT
#define LIST_PRINT
#define ITERATOR_PRINT

	template<typename T> class Element
	{

		friend class List;

		Element<T>* pNext;
		Element<T>* pPrev;
		T Data;

	public:

		Element(T Data = NULL, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pPrev(pPrev), pNext(pNext)
		{
#ifdef ELEMENT_PRINT
			cout << "E_Constructor >> \t" << this << endl;
#endif // ELEMENT_PRINT
		}


		~Element()
		{
#ifdef ELEMENT_PRINT
			cout << "E_Destructor >> \t" << this << endl;
#endif // ELEMENT_PRINT
		}


	};

	Element<T>* Head;
	Element<T>* Tail;
	size_t size;

public:


	List()
	{
		Head = Tail = nullptr;
#ifdef LIST_PRINT
		cout << "LConstructor >> \t" << this << endl;
#endif // LIST_PRINT
	}

	~List()
	{
#ifdef LIST_PRINT
		cout << "LDestructor >> \t" << this << endl;
#endif // LIST_PRINT

	}

	void push_front(T Data = NULL)
	{

		Element<T>* New = new Element<T>(Data, this->Head);

		!Head ? Tail = (Head = New) : Head = (New->pNext = Head)->pPrev = New;
	}


	void push_back(T Data = NULL)
	{

		Element<T>*New = new Element<T>(Data, nullptr, this->Tail);

		!Tail ? Tail = (Head = New) : Tail = (New->pPrev = Tail)->pNext = New;


	}



	void pop_front()
	{

		/*
		Element<T>* Iterator = this->Head;
		Head = Head->pNext;
		Head->pPrev = nullptr;

		delete Iterator;
		*/
	
		delete (Head = Head->pNext)->pPrev;
		Head->pPrev = nullptr;

	}



	void print()

	{
		for (Element<T>* it = this->Head; it != nullptr; it = it->pNext)
		{
			cout << it << "\t" << it->Data << "\t" << it->pNext << endl;
		}
	}


	void print_revers()
	{
		for (Element<T>* it = this->Tail; it; it = it->pPrev)
		{
			cout << it << "\t" << it->Data << "\t" << it->pPrev << endl;
		}
	}


};

template<typename T>std::ostream& operator <<(std::ostream& os, const List<T>& other)
{
	other.print();
	return os;
}
/*
template<typename T>  List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> Temp(left);

	for (size_t i = 0; i < right.get_size(); i++)
	{
		Temp.push_back(right[i]);
	}
	return Temp;
}
*/




