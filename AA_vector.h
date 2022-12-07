#pragma once
#include <iostream>
using namespace std;

template<class T>
class AA_Vector
{
private:
	T* ptr;
	int vector_size;
	int vector_capacity;
public:
	AA_Vector();
	AA_Vector(int s);
	AA_Vector(T Initialization, int size);
	AA_Vector(const AA_Vector& v);
	~AA_Vector();
	int push_back(T n);
	T pop_back();
	//void erase(T* n);
	bool operator==(const AA_Vector<T>& v);
	void print();

	AA_Vector operator = (const AA_Vector& v)
	{
		if (this != &v)
		{
			if (ptr != nullptr)
				delete[] ptr;
			ptr = new T[v.vector_size()];
			vector_size = v.vector_size();
			for (int i = 0; i < vector_size; i++)
			{
				ptr[i] = v.ptr[i];
			}
		}

		return *this;
	}
	AA_Vector operator = (const AA_Vector&& v)
	{
		if (this != &v)
		{
			delete[] ptr;
			ptr = v.ptr;
			vector_size = v.vector_size;
			delete[] v.ptr;
		}
		return *this;
	}
	T& operator [] (int i)
	{
		return (ptr[i]);
	}
	

};


template<class T>
AA_Vector<T>::AA_Vector()
{
	vector_size = 0;
	ptr = nullptr;
	vector_capacity = 0;
}

template<class T>
AA_Vector<T>::AA_Vector(int s)
{
	vector_size = s;
	vector_capacity = s * 1.5;
	ptr = new T[vector_capacity];
	for (int i = 0; i < vector_size; i++)
	{
		
		ptr[i] = 0;
	}
}


template<class T>
AA_Vector<T>::AA_Vector(T Initialization, int size)
{
	vector_size = size;
	vector_capacity = size * 1.5;
	ptr = new T[vector_capacity];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = Initialization;
	}
}

template<class T>
AA_Vector<T>::AA_Vector(const AA_Vector& v)
{
	ptr = new T[v.vector_capacity];
	vector_size = v.vector_size;
	vector_capacity = v.vector_capacity;
	for (int i = 0; i < vector_size; i++)
	{
		ptr[i] = v.ptr[i];
	}
}

template<class T>
AA_Vector<T>::~AA_Vector()
{
	delete[] ptr;
}

template<class T>
inline bool AA_Vector<T>::operator==(const AA_Vector<T>& v)
{
	bool ok = true;
	if (vector_size == v.vector_size)
	{
		for (int i = 0; i < vector_size; i++)
		{
			if (ptr[i] == v.ptr[i])
				continue;
			else
			{
				ok = false;
				break;
			}
		}
	}
	else
		ok = false;
	return ok;
}

template<class T>
void AA_Vector<T>::print()
{
	for (int i = 0; i < vector_size; i++)
	{
		cout << ptr[i] << endl;
	}
}

template<class T>
inline int AA_Vector<T>::push_back(T n)
{
	vector_size++;
	vector_capacity = vector_size * 1.5;
	ptr[vector_size - 1] = n;
	return 0;
}

template<class T>
inline T AA_Vector<T>::pop_back()
{
	vector_size--;
	return ptr[vector_size - 1];
}

/*
template<class T>
inline void AA_Vector<T>::erase(T* n)
{

}
*/


