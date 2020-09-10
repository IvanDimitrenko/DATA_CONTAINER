#pragma once
#include<Windows.h>
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;

template<typename T> class Element;

template<typename T> class List
{

#define ELEMENT_PRINT
#define LIST_PRINT
#define ITERATOR_PRINT
	
	
	template<typename T> class Element
		{
			template<typename T> friend class List;
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

	 class Iterator
	{

		Element<T>* Temp;

	public:

		Iterator(Element<T>* Temp = nullptr);


		~Iterator();


		const Iterator begin();

		const Iterator end();

		Iterator&operator++();

		Iterator&operator--();

		Iterator& operator++(int);

		Iterator& operator--(int);



		bool operator != (Element<T>* other)const;

		operator bool()const;


		T& operator* ()const;

	};
	

	 class ReverseIterator
	 {
		 Element<T> Temp;

	 public:

		 ReverseIterator(Element<T>* Temp = nullptr) :Temp(Temp)
		 {
			 cout << "RitConstructor >> \t" << this;
		 }

		 ~ReverseIterator()
		 {
			 cout << "RitDestructor >> \t" << this;
		 }

		 ReverseIterator& operator++()
		 {
			 Temp = Temp->pPrev;
			 return *this;
		 }

		 ReverseIterator& operator--()
		 {
			 Temp = Temp->pNext;
			 return *this;
		 }

		 T& operator *()
		 {
			 return Temp->Data;
		 }

		 bool operator != (const ReverseIterator& other)const
		 {
			 return this->Temp != other.Temp;
		 }

		 operator bool()const
		 {
			 return this->Temp;
		 }
	 };

	 List();
	 List(size_t size, T Data = NULL);
	 List(const List& other);
	 List(const List&& other);
	 List(const std::initializer_list<T>& list);
	 ~List();


	 List& operator = (const List& other);
	 List& operator = (const List&& other);


	 void push_front(T Data = NULL);
	 void push_back(T Data = NULL);
	 void pop_front(void);
	 void pop_back(void);

	 void clear(void);
	 void erase(size_t index);
	 void insert(size_t index, T Data);

	 void print()const;
	 void print_revers();

	 Element<T>* &get_element(size_t index); 

	 const Iterator begin()const;
	 Iterator begin();

	 const Iterator end()const;
	 Iterator end();

	 const ReverseIterator rbegin()const;
	 ReverseIterator rbegin();

	 const ReverseIterator rend()const;
	 ReverseIterator rend();
	

};


template<typename T>std::ostream& operator <<(std::ostream& os, const List<T>& other)
{
	other.print();
	return os;
}

/*
template<typename T>std::ostream& operator <<(std::ostream& os, const List<T>::Iterator other)
{
	other.print();
	return os;
}

*/