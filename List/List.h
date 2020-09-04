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

		Iterator(Element<T>* Temp = nullptr)
		{
			this->Temp = Temp;

#ifdef ITERATOR_PRINT
			cout << "DefItConstructor >> \t" << this << endl;
#endif // ITERATOR_PRINT
		}


		~Iterator()
		{
#ifdef ITERATOR_PRINT
			cout << "ItDestructor >> \t" << this << endl;
#endif // ITERATOR_PRINT
		}



		Iterator&operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator&operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}

		Iterator& operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}

		Iterator& operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}



		bool operator != (Element<T>* other)const
		{
			return this->Temp != other;
		}

		operator bool()const
		{
			return Temp;
		}


		T& operator* ()const
		{ 
			return Temp->Data;
		}

		T operator* ()
		{ 
			return Temp->Data;
		}

	};

	List()
	{
		Head = Tail = nullptr;
		this->size = 0;
#ifdef LIST_PRINT
		cout << "LConstructor >> \t" << this << endl;
#endif // LIST_PRINT
	}


	List(size_t size, T Data)
	{

		for (size_t i = 0; i < size; i++)
		{
			push_back(Data);
		}
#ifdef LIST_PRINT
		cout << "LSizeConstructor >> \t" << this << endl;
#endif // LIST_PRINT
	}


	List(const List& other):List()
	{
		Element<T>* it = other.Head;

		for (size_t i = 0; i < other.size; i++)
		{
			push_back(it->Data);
		}
#ifdef LIST_PRINT
		cout << "LCopyConstructor >> \t" << this << endl;
#endif // LIST_PRINT
	}


	List(const List&& other) : List()
	{
		Element<T>* it = other.Head;

		for (size_t i = 0; i < other.size; i++)
		{
			push_back(it->Data);
		}
		other.~List();
#ifdef LIST_PRINT
		cout << "LMoveConstructor >> \t" << this << endl;
#endif // LIST_PRINT
	}


	List(const std::initializer_list<T>& list):List()
	{
		for (const auto &element : list)
		{
			push_back(element);
		}

#ifdef PRINT
		cout << "L_Initializer_Constructor >> \t" << this << endl;
#endif//PRINT

	}





	List& operator = (const List& other)
	{
		this->clear();

		Element<T>* it = other.Head;

		for (size_t i = 0; i < other.size; i++)
		{
			push_back(it->Data);
		}
#ifdef LIST_PRINT
		cout << "LAssigment >> \t" << this << endl;
#endif // LIST_PRINT
		return *this;
	}

	List& operator = (const List&& other)
	{
		this->clear();

		Element<T>* it = other.Head;

		for (size_t i = 0; i < other.size; i++)
		{
			push_back(it->Data);
		}
		other.~List();
#ifdef LIST_PRINT
		cout << "LMove >> \t" << this << endl;
#endif // LIST_PRINT
		return *this;
	}




	~List()
	{
		clear();
#ifdef LIST_PRINT
		cout << "LDestructor >> \t" << this << endl;
#endif // LIST_PRINT

	}




	push_front(T Data = NULL)
	{

		Element<T>* New = new Element<T>(Data, this->Head);

		!Head ? Tail = (Head = New) : Head = (New->pNext = Head)->pPrev = New;

		size++;
	}

	void push_back(T Data = NULL)
	{

		Element<T>*New = new Element<T>(Data, nullptr, this->Tail);

		!Tail ? Tail = (Head = New) : Tail = (New->pPrev = Tail)->pNext = New;

		size++;
	}






	void pop_front(void)
	{
		if (size == 1)
		{
			size--;
			delete Head;
			Head = Tail = nullptr;
		}
		else if (!Head)return;
		else 
		{
			size--;
			delete ((Head = Head->pNext)->pPrev);
			Head->pPrev = nullptr;
		}
	}

	void pop_back(void)
	{
		
		if (size <= 1)
		{
			pop_front(); return;
		}
     		size--;
			delete (Tail = Tail->pPrev)->pNext;
			Tail->pNext = nullptr;

	}






	void clear(void)
	{
		while (this->size) pop_front();
	}





	void erase(size_t index)
	{
		if (index == 0)
		{
			pop_front(); return;
		}
		else  if (index == size - 1)
		{
			pop_back(); return;
		}

		Element<T>* it = get_element(index);

		it->pPrev->pNext = it->pNext->pPrev = it->pPrev;
		size--;
		delete it;
	}

	void insert(size_t index, T Data)
	{
		if (!Head)push_front(Data);
		else if (index == size - 1)push_back(Data);
		else if (index > size - 1)throw 2;
		else
		{
			Element<T>* it = get_element(index);										
			Element<T>* New = new Element<T>(Data, it, it->pPrev);		
			New->pPrev->pNext = it->pPrev = New;	
			size++;
		}
	}






	void print()const
	{
		for (Element<T>* it = this->Head; it ; it = it->pNext)
		{
			cout << it << "\t" << it->Data << "\t" << it->pNext << endl;
		}
		cout << "size >> " << this->size << endl;
	}

	void print_revers()
	{
		for (Element<T>* it = this->Tail; it; it = it->pPrev)
		{
			cout << it << "\t" << it->Data << "\t" << it->pPrev << endl;
		}
	}




	Element<T>* &get_element(size_t index)
	{
		Element<T>* it;
		size_t i;

		if (index > this->size - 1)throw 2;
		else if (index == 0)return Head;
		else if (index == this.size - 1)return Tail;
		
		else if (index >= ((this->size - 1) / 2) )
		{
			it = Tail;
			i = this->size - 1;
			while (it = it->pPrev)
			{
				if (--i == index)return it;
			}
		}
		else
		{
			it = Head;
			i = 0;
			while (it = it->pNext)
			{
				if (++i == index)return it;
			}
		}
		return it;

	}


	 Element<T>* begin()const
	 {
		return Head;
	 }


	Element<T>* end()const
	{
		return Tail;
	}


};


template<typename T>std::ostream& operator <<(std::ostream& os, const List<T>& other)
{
	other.print();
	return os;
}





