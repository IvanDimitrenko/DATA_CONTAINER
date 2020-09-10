#include"List.h"


template<typename T> List<T>::Iterator::Iterator(Element<T>* Temp)
{
	this->Temp = Temp;

#ifdef ITERATOR_PRINT
	cout << "DefItConstructor >> \t" << this << endl;
#endif // ITERATOR_PRINT
}


template<typename T> List<T>::Iterator::~Iterator()
{
#ifdef ITERATOR_PRINT
	cout << "ItDestructor >> \t" << this << endl;
#endif // ITERATOR_PRINT
}


/*template<typename T> const List<T>::Iterator List<T>::begin()const { return this->Head; }


template<typename T> const List<T>::Iterator List<T>::end()const { return nullptr; }


template<typename T>  List<T>::Iterator List<T>::begin() { return this->Head; }


template<typename T>  List<T>::Iterator List<T>::end() { return nullptr; }*/


template<typename T> List<T>::Iterator& List<T>::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}


template<typename T> List<T>::Iterator&List<T>::Iterator::operator--()
{
	Temp = Temp->pPrev;
	return *this;
}


template<typename T> List<T>::Iterator& List<T>::Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}


template<typename T> List<T>::Iterator& List<T>::Iterator:: operator--(int)
{
	Iterator old = *this;
	Temp = Temp->pPrev;
	return old;
}


template<typename T> bool List<T>::Iterator::operator != (Element<T>* other)const
{
	return this->Temp != other;
}


template<typename T>  List<T>::Iterator::operator bool()const {  return Temp; }


template<typename T> T& List<T>::Iterator::operator * ()const {  return Temp->Data; }
