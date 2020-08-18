#pragma once

#include<iostream>
#include<conio.h>
#include<string>
using std::endl;
using std::cout;
using std::cin;

namespace Forward_List
{


	//#define PRINT

	/*template<typename T> class Iterator
	{

		template<typename T>friend class ForwardList, friend class Element;

	private:
		Element<T> Iterator;
	public:
		Element<T>&operator++(Element<T>* )
		{
			Iterator;
		}

	};*/
	


template<typename T>  class Element
	{
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


		
		template<typename T>
		friend class ForwardList;
	
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


		ForwardList(size_t size):ForwardList()
		{
			while(size--)
			{
				push_front(NULL);
			}


#ifdef PRINT
			cout << "L_SizeConstructor >> \t" << this << endl;
#endif//PRINT
		}



		ForwardList(const std::initializer_list<T>& list)
		{

			// foreach
			for (const auto &element : list)
			{
				push_back(element);
			}


#ifdef PRINT
			cout << "L_DataConstructor >> \t" << this << endl;
#endif//PRINT
		}



		ForwardList(const ForwardList& other)
		{
			Element<T>* Iterator = other.Head;

			for (size_t i = 0; i < other.SIZE; i++, Iterator++)
			{
				push_back(Iterator->Data);
			}

#ifdef PRINT
			cout << "L_CopyConstructor >> \t" << this << endl;
#endif//PRINT
		}



	    ForwardList(const ForwardList &&  other)
		    {

			  Element<T>* Iterator = other.Head;

			  for (size_t i = 0; i < other.SIZE ; i++ , Iterator = Iterator->pNext)
			  {
				   push_back(Iterator->Data);
			  }

			  other.~ForwardList();

#ifdef PRINT
			cout << "L_MoveConstructor >> \t" << this << endl;
#endif//PRINT
		   }




		ForwardList& operator = (const ForwardList& other )
	   {
			this->clear();			

			Element<T>* Iterator = other.Head;

			for (size_t i = 0; i < other.SIZE; i++, Iterator = Iterator->pNext)
			{
				push_back(Iterator->Data);
			}


         #ifdef PRINT
			cout << "L_CopyAssigment >> \t" << this << endl;
         #endif//PRINT

			return *this;
		}



	    ForwardList& operator = (const ForwardList&& other)
		  {
			
			this->clear();

			Element<T>* Iterator = other.Head;

			for (size_t i = 0 ; i < other.SIZE; i++, Iterator = Iterator->pNext)
			{
				push_back(Iterator->Data);
		    }

			other.~ForwardList();

			#ifdef PRINT
					cout << "L_MoveAssigment >> \t" << this << endl;
			#endif//PRINT

			return *this;

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
			while (SIZE) pop_front();
			
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
			Element<T>* Iterator = this->Head;
			for (size_t i = 0; i < index - 1; i++)
			{
				Iterator = Iterator->pNext;
		 	}

		    Element<T>* New = new Element<T>(Data, Iterator->pNext);

			Iterator->pNext = New;

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

			
	
			Element<T>* Node = Head;

			size_t i = 0;

			while (Node)
			{
				if (i == index)
				{
					return Node->Data;
				}
				Node = Node->pNext; i++;
			}
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
	
		size_t size = (left.get_size() > right.get_size()) ? left.get_size()  : right.get_size();		 

		for (size_t i = 0; i < size ; i++)
		{	
			if (i < left.get_size() && i < right.get_size())
			{
				Temp.push_back(left[i] + right[i] );
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

		for (size_t i = 0; i <  right.get_size() ; i++)
		{
			Temp.push_back(right[i]);
		}
		return Temp;
}


}