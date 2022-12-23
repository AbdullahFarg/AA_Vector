#pragma once
#include <iostream>
#include <iterator>
using namespace std;

/**
 * @brief this is template class
 * @tparam T
*/
template<class T>
/**
 * @brief  vector class
 * @tparam T
*/
class AA_Vector
{
	using iterator = T*;
private:
	T* ptr;
	int vector_size;
	int vector_capacity;
public:
	AA_Vector();
	AA_Vector(int s);
	AA_Vector(T* Initialization, int size);
	AA_Vector(const AA_Vector& v);
	~AA_Vector();
	int push_back(T n);
	T pop_back();
	void erase(iterator it);
	void erase(iterator it1, iterator it2);
	void clear();
	iterator begin() { return iterator(&ptr[0]); }
	iterator end() { return iterator(&ptr[vector_size]); }
	bool operator==(const AA_Vector<T>& v);
	void print();
	/**
	 * @brief copy assignment
	 * @param v
	 * @return T*
	*/
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
	/**
	 * @brief move assignment
	 * @param v
	 * @return T*
	*/
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
	/**
	 * @brief overlode [] operator
	 * @param i
	 * @return *T
	*/
	T& operator [] (int i)
	{
		return (ptr[i]);
	}
};

/**
 * @brief empty constractor
 * @tparam T
*/
template<class T>
AA_Vector<T>::AA_Vector()
{
	vector_size = 0;
	ptr = nullptr;
	vector_capacity = 0;
}
/**
 * @brief paramitaraize constractor
 * @tparam T
 * @param s the size of vector
*/
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

/**
 * @brief Initialization the vector by an array
 * @tparam T
 * @param Initialization the array
 * @param size the size of array
*/
template<class T>
AA_Vector<T>::AA_Vector(T* Initialization, int size)
{
	vector_size = size;
	vector_capacity = size * 1.5;
	ptr = new T[vector_capacity];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = Initialization[i];
	}
}
/**
 * @brief copy constractor
 * @tparam T
 * @param v the vector that we take a copy from it
*/
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
/**
 * @brief destractor
 * @tparam T
*/
template<class T>
AA_Vector<T>::~AA_Vector()
{
	delete[] ptr;
}

/**
 * @brief overlode == operator
 * @tparam T
 * @param v
 * @return bool
*/
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
/**
 * @brief ptint the vector
 * @tparam T
*/
template<class T>
void AA_Vector<T>::print()
{
	for (int i = 0; i < vector_size; i++)
	{
		cout << ptr[i] << endl;
	}
}
/**
 * @brief add elemint to vector from behind
 * @tparam T
 * @param n the elemint
 * @return int
*/
template<class T>
inline int AA_Vector<T>::push_back(T n)
{
	vector_size++;
	vector_capacity = vector_size * 1.5;
	ptr[vector_size - 1] = n;
	return 0;
}
/**
 * @brief delete an elemint form behind
 * @tparam T
 * @return T
*/
template<class T>
inline T AA_Vector<T>::pop_back()
{
	vector_size--;
	return ptr[vector_size - 1];
}

template<class T>
inline void AA_Vector<T>::erase(iterator it1, iterator it2)
{
	if (it1 == it2) it2++;
	if (it1 >= end() || it1 < begin() || it2 >= end() || it2 < begin() || it1 > it2) {
		cout << "Invalid iterator!\n";
		return;
	}
	if (it1 < it2) {
		for (auto i = it1, j = it2; j != end(); j++, i++) {
			*i = *j;
		}
		auto k = it2 - it1;
		vector_size -= k;
	}
}

template<class T>
inline void AA_Vector<T>::clear()
{
	if (ptr != nullptr)
		delete[] ptr;
	ptr = nullptr;
	vector_capacity = 0;
	vector_size = 0;
}

template<class T>
inline void AA_Vector<T>::erase(iterator it)
{
	if (it >= end() || it < begin()) {
		cout << "Invalid iterator!\n";
		return;
	}
	AA_Vector::erase(it, it);
}
