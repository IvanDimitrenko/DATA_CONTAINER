#pragma once

#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<string>
using std::endl;
using std::cout;
using std::cin;

namespace Forward_List
{
	//#define PRINT
	//#define PRINT_ITERATOR

	template<typename T>  class Element;
	template<typename T> class ForwardList;




	template<typename T> class Iterator
	{
		template<typename T> friend class ForwardList;

		Element<T>* Temp;

	public:


		Iterator(Element<T>* &Temp = nullptr) //: Temp(Temp)
		{
			this->Temp = Temp;

#ifdef PRINT_ITERATOR
			cout << "FL_IteratorConstructor >> \t" << this << endl;
#endif // PRINT_ITERATOR

		}



		~Iterator()
		{
#ifdef PRINT_ITERATOR
			cout << "FL_IteratorDestructor >> \t" << this << endl;
#endif // PRINT_ITERATOR
		}



		Iterator&operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}



		Iterator& operator++(int)// & Iterator...
		{
			Iterator old = *this;
			Temp = Temp->pNext;
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



		Iterator& operator += (size_t index)
		{

			size_t current = 0;

			while (Temp)
			{
				if (current == index)
				{
					return Temp->Data;
				}
				++Temp; current++;
			}
			return Iterator;
		}



		Iterator& operator[](size_t index)
		{

			Temp += index;
			return *this;

		}


		T& operator*()
		{
			return Temp->Data;
		}

	};





	template<typename T>  class Element
	{

		template<typename T>friend class ForwardList;
		template<typename T>friend class Iterator;

	private:
		T Data;
		Element* pNext;
	public:


		Element(T Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
		{
#ifdef PRINT
			cout << "E_Constructor >> \t" << this << endl;
#endif//PRINT
		}


		Element(Element* pNext = nullptr)
		{
#ifdef PRINT
			cout << "E_DefConstructor >> \t" << this << endl;
#endif//PRINT
		}



		~Element()
		{

#ifdef PRINT
			cout << "E_Destructor >> \t" << this << endl;
#endif//PRINT
		}




	};



	template<typename T>class ForwardList
	{

	private:

		Element<T>* Head;
		size_t SIZE = 0;

	public:

		ForwardList()
		{
			this->Head = nullptr;
#ifdef PRINT
			cout << "L_DefConstructor >> \t" << this << endl;
#endif//PRINT
		}


		ForwardList(size_t size)
		{
			this->Head = nullptr;

			for (size_t i = 0; i < size; i++)
			{
				push_front(NULL);
			}


#ifdef PRINT
			cout << "L_SizeConstructor >> \t" << this << endl;
#endif//PRINT
		}



		ForwardList(const std::initializer_list<T>& list)
		{


			for (const auto &element : list)
			{
				push_back(element);
			}

#ifdef PRINT
			cout << "L_DataConstructor >> \t" << this << endl;
#endif//PRINT
		}



		ForwardList(ForwardList& other) : ForwardList(other.SIZE)
		{

			for (Iterator<T> ito = other.begin(), itt = begin(); ito; ++itt, ++ito)
			{
				*itt = *ito;
			}

#ifdef PRINT
			cout << "L_CopyConstructor >> \t" << this << endl;
#endif//PRINT
		}


		ForwardList(const ForwardList &&  other) : ForwardList(other.SIZE)
		{

			for (Iterator<T> ito = other.begin(), itt = begin(); ito; ++itt, ++ito)
			{
				*itt = *ito;
			}

			other.~ForwardList();

#ifdef PRINT
			cout << "L_MoveConstructor >> \t" << this << endl;
#endif//PRINT
		}



		ForwardList& operator = (ForwardList& other)
		{

			this->resize(other.get_size());

			Iterator<T> ito(other.Head), itt(this->Head);

			for (size_t i = 0; i < other.SIZE; i++, ++itt, ++ito)
			{
				*itt = *ito;
			}


#ifdef PRINT
			cout << "L_CopyAssigment >> \t" << this << endl;
#endif//PRINT

			return *this;
		}


		ForwardList& operator = (ForwardList&& other)
		{

			this->resize(other.get_size());

			Iterator<T> ito(other.Head), itt(this->Head);


			for (size_t i = 0; i < other.SIZE; i++, ++itt, ++ito)
			{
				*itt = *ito;
			}

			other.~ForwardList();

#ifdef PRINT
			cout << "L_CopyAssigment >> \t" << this << endl;
#endif//PRINT

			return *this;
		}


	/*	ForwardList& operator = (const ForwardList&& other)
		{

			this->clear();

			Element<T>* Iterator = other.Head;

			for (size_t i = 0; i < other.SIZE; i++, Iterator = Iterator->pNext)
			{
				push_back(Iterator->Data);
			}

			other.~ForwardList();

#ifdef PRINT
			cout << "L_MoveAssigment >> \t" << this << endl;
#endif//PRINT


			return *this;
		}
		*/



		void resize(size_t SIZE)
		{
			this->clear();

			for (size_t i = 0; i < SIZE; i++)
			{
				push_front();
			}
		}



		~ForwardList()
		{

			clear();
#ifdef PRINT
			cout << "L_Destructor >> \t" << this << endl;
#endif//PRINT
		}



		void push_front(T Data = NULL)
		{
			Head = new Element<T>(Data, Head);
			this->SIZE++;
		}




		void push_back(T Data = NULL)
		{
			insert(SIZE, Data);
		}




		void clear()
		{
			while (SIZE)
			{
				pop_front();
			}
		}




		void erase(size_t index)
		{
			if (index >= SIZE || SIZE == 0 /*!Head*/) return;

			else if (index == 0)
			{
				pop_front(); return;
			}

			Element<T>* Iterator = this->Head;
			for (size_t i = 0; i < index - 1; i++/*,Iterator = Iterator->pNext*/)
			{
				Iterator = Iterator->pNext;
			}
			Element<T>* To_Delete = Iterator->pNext;

			Iterator->pNext = Iterator->pNext->pNext;

			//	Iterator->pNext = To_Delete->pNext;
			delete To_Delete;

			SIZE--;
		}




		void insert(size_t index, T Data)
		{
			if (index > SIZE)
			{
				push_back(Data); return;
			}

			else if (this->SIZE == 0 || index == 0)
			{
				push_front(Data); return;
			}

			Element<T>* it = this->Head;

			for (size_t i = 0; i < index - 1; i++)
			{
				it = it->pNext;
			}

			Element<T>* New = new Element<T>(Data, it->pNext);

			it->pNext = New;

			SIZE++;
		}



		void pop_front()
		{
			if (!Head) return;

			Element<T>* Iterator = this->Head;

			Head = Head->pNext;

			delete Iterator;

			SIZE--;
		}



		void pop_back()
		{
			erase(SIZE - 1);
		}



		void print()const
		{
			cout << endl;

			size_t i = 0;

			for (Element<T>* Iterator = Head; Iterator; Iterator = Iterator->pNext, i++)
			{
				cout << Iterator << '\t' << Iterator->Data << "\t Index >> " << i << '\t' << Iterator->pNext << endl;
			}

			cout << endl << "Size >> " << SIZE << endl;
		}


		size_t get_size()const
		{
			return SIZE;
		}


		T& operator[](size_t index)const
		{

			if (index >= SIZE)
			{
				MessageBox(NULL, L"run-time check failure #2", L"ForwardList", MB_OK);
				throw 2;
			}

			Element<T>* Node = Head;

			size_t i = 0;

			while (Node)
			{
				if (i++ == index) return Node->Data;

				Node = Node->pNext;

			}
		}

		Iterator<T> begin()
		{
			return Head;
		}
		Iterator<T> end()
		{
			return nullptr;
		}
	};


	template<typename T>std::ostream& operator <<(std::ostream& os, const ForwardList<T>& other)
	{
		other.print();
		return os;
	}


	template<typename T>ForwardList<T> plus(const ForwardList<T>& left, const ForwardList<T>& right)
	{
		ForwardList<T> Temp;

		size_t size = (left.get_size() > right.get_size()) ? left.get_size() : right.get_size();

		for (size_t i = 0; i < size; i++)
		{
			if (i < left.get_size() && i < right.get_size())
			{
				Temp.push_back(left[i] + right[i]);
				continue;
			}

			right.get_size() == size ?

				Temp.push_back(right[i])
				:
				Temp.push_back(left[i]);
		}
		return Temp;
	}


	template<typename T> ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
	{
		ForwardList<T> Temp(left);

		for (size_t i = 0; i < right.get_size(); i++)
		{
			Temp.push_back(right[i]);
		}
		return Temp;
	}


}