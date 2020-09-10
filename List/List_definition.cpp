#include"List.h"

template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	this->size = 0;
#ifdef LIST_PRINT
	cout << "LConstructor >> \t" << this << endl;
#endif // LIST_PRINT
}


template<typename T>List<T>::List(size_t size, T Data)
{

	for (size_t i = 0; i < size; i++)
	{
		push_back(Data);
	}
#ifdef LIST_PRINT
	cout << "LSizeConstructor >> \t" << this << endl;
#endif // LIST_PRINT
}


template<typename T>List<T>::List(const List& other) : List<T>::List()
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


template<typename T>List<T>::List(const List&& other) : List<T>::List()
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


template<typename T>List<T>::List(const std::initializer_list<T>& list) : List<T>::List()
{
	for (const auto &element : list)
	{
		push_back(element);
	}

#ifdef PRINT
	cout << "L_Initializer_Constructor >> \t" << this << endl;
#endif//PRINT

}


template<typename T>List<T>&List<T>::operator = (const List<T>& other)
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


template<typename T>List<T>& List<T>::operator = (const List<T>&& other)
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


template<typename T>List<T>::~List()
{
	clear();
#ifdef LIST_PRINT
	cout << "LDestructor >> \t" << this << endl;
#endif // LIST_PRINT

}


template<typename T> void List<T>::push_front(T Data )
{

	Element<T>* New = new Element<T>(Data, this->Head);

	!Head ? Tail = (Head = New) : Head = (New->pNext = Head)->pPrev = New;

	size++;
}


template<typename T> void List<T>::push_back(T Data)
{

	Element<T>*New = new Element<T>(Data, nullptr, this->Tail);

	!Tail ? Tail = (Head = New) : Tail = (New->pPrev = Tail)->pNext = New;

	size++;
}


template<typename T> void List<T>::pop_front(void)
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


template<typename T> void List<T>::pop_back(void)
{

	if (size <= 1)
	{
		pop_front(); return;
	}
	size--;
	delete (Tail = Tail->pPrev)->pNext;
	Tail->pNext = nullptr;

}


template<typename T> void List<T>::clear(void)
{
	while (this->size) pop_front();
}


template<typename T> void List<T>::erase(size_t index)
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


template<typename T> void List<T>::insert(size_t index, T Data)
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


template<typename T> void List<T>::print()const
{
	for (Element<T>* it = this->Head; it; it = it->pNext)
	{
		cout << it << "\t" << it->Data << "\t" << it->pNext << endl;
	}
	cout << "size >> " << this->size << endl;
}


template<typename T> void List<T>::print_revers()
{
	for (Element<T>* it = this->Tail; it; it = it->pPrev)
	{
		cout << it << "\t" << it->Data << "\t" << it->pPrev << endl;
	}
}


template<typename T>List<T>::Element<T>*& List<T>::get_element(size_t index)
{
	Element<T>* it;
	size_t i;

	if (index > this->size - 1)throw 2;
	else if (index == 0)return Head;
	else if (index == this.size - 1)return Tail;

	else if (index >= ((this->size - 1) / 2))
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



template<typename T>const List<T>::Iterator List<T>::begin()const { return this->Head; }
template<typename T>const List<T>::Iterator List<T>::end()const { return nullptr; }


template<typename T> List<T>::Iterator List<T>::begin() { return Head; }
template<typename T>List<T>::Iterator List<T>::end()  { return nullptr; }




template<typename T>const List<T>::ReverseIterator List<T>::rbegin()const { return this->Head; }

template<typename T>const List<T>::ReverseIterator List<T>::rend()const { return nullptr; }

template<typename T>List<T>::ReverseIterator List<T>::rbegin() { return this->Head; }

template<typename T>List<T>::ReverseIterator List<T>::rend() { return nullptr; }