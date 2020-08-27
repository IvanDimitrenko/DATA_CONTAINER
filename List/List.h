#pragma once
#include<Windows.h>
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;

namespace List
{

#define ELEMENT_PRINT
#define LIST_PRINT
#define ITERATOR_PRINT
	template<typename T> class Element
	{

		Element<T>* pNext, pRev;
		T Data;

	public:

		Element(Element* pNext = nullptr, Element* pRev = nullptr, Data = NULL) :pRev(pRev),
		pNext(pNext), Data(Data)
		{
#ifdef ELEMEN
			cout << "E_DefConstructor >> \t" << this << endl;
#endif // ELEMEN
		}

		~Element()
		{
#ifdef ELEMENT_PRINT
			cout << "E_Destructor >> \t" << this << endl; 
#endif // ELEMENT_PRINT

		}


	};







}

