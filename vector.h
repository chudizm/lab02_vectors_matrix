// Верхнетреугольная матрица - реализация на основе шаблона вектора

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class valType>
class vect
{
protected:
	valType *pVect;
	int size;       // размер вектора
	int startInd; // индекс первого элемента вектора
public:
	vect(int _size = 10, int _startInd = 0);
	vect(const vect &v);                // конструктор копирования
	~vect();
	int getSize() { return size; } // размер вектора
	int getStartInd() { return startInd; } // индекс первого элемента
	int getValue(int index) { return pVect[index - startInd]; };
	valType& operator[](int pos);             // доступ
	bool operator==(const vect &v) const;  // сравнение
	bool operator!=(const vect &v) const;  // сравнение
	vect& operator=(const vect &v);     // присваивание

											  // скалярные операции
	vect  operator+(const valType &val);   // прибавить скаляр
	vect  operator-(const valType &val);   // вычесть скаляр
	vect  operator*(const valType &val);   // умножить на скаляр

											  // векторные операции
	vect  operator+(const vect &v);     // сложение
	vect  operator-(const vect &v);     // вычитание
	valType  operator*(const vect &v);     // скалярное произведение

											  // ввод-вывод
	friend istream& operator>>(istream &is, vect &v)
	{
		for (int i = 0; i < v.size; i++)
			is >> v.pVect[i];
		return is;
	}
	friend ostream& operator<<(ostream &os, const vect &v)
	{
		for (int i = 0; i < v.size; i++)
		{
			os << setw(3) << v.pVect[i] << ' ';
		}
		return os;
	}
};

/*template <class valType>
vect<valType>::vect(int _size, int _startInd)
{
	if ((_size < 1) || (_size > MAX_VECTOR_SIZE)) 
		throw (_size);
	if ((_startInd < 0) || (_startInd >= MAX_VECTOR_SIZE))
		throw(_startInd);
	size = _size;
	startInd = _startInd;
	pVect = new valType[size];
}*/ /*-------------------------------------------------------------------------*/
template <class valType>
vect<valType>::vect(int _size, int _startInd)
{
	if ((_size < 1) || (_size > MAX_VECTOR_SIZE)) 
		throw (_size);
	if ((_startInd < 0) || (_startInd >= MAX_VECTOR_SIZE))
		throw(_startInd);
	size = _size;
	startInd = _startInd;
	pVect = new valType[size];
}
template <class valType> //конструктор копирования
vect<valType>::vect(const vect<valType> &v)
{
	size = v.size;
	startInd = v.startInd;
	pVect = new valType[size];
	for (int i = 0; i < size; i++)
		pVect[i] = v.pVect[i];
} /*-------------------------------------------------------------------------*/

template <class valType>
vect<valType>::~vect()
{
	delete[]pVect;
	pVect = NULL;
} /*-------------------------------------------------------------------------*/

template <class valType> // доступ
valType& vect<valType>::operator[](int pos)
{
	if ((pos - startInd >= 0) && (pos - startInd < size))
		return pVect[pos - startInd];
	else throw(pos);
} /*-------------------------------------------------------------------------*/

template <class valType> // сравнение
bool vect<valType>::operator==(const vect &v) const
{
	if (size != v.size) return false;
	if (startInd != v.startInd) return false;
	for (int i = 0; i < size; i++)
		if (pVect[i] != v.pVect[i]) return false;
	return true;
} /*-------------------------------------------------------------------------*/

template <class valType> // сравнение
bool vect<valType>::operator!=(const vect &v) const
{
	if (v == *this) return false;
	else return true;
} /*-------------------------------------------------------------------------*/

template <class valType> // присваивание
vect<valType>& vect<valType>::operator=(const vect &v)
{
	if (*this != v)
	{
		if (size != v.size)
		{
			delete[] pVect;
			pVect = new valType[v.size];
		}
		size = v.size;
		startInd = v.startInd;
		for (int i = 0; i < size; i++)
			pVect[i] = v.pVect[i];
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class valType> // прибавить скаляр
vect<valType> vect<valType>::operator+(const valType &val)
{
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = pVect[i] + val;
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // вычесть скаляр
vect<valType> vect<valType>::operator-(const valType &val)
{
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = pVect[i] - val;
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // умножить на скаляр
vect<valType> vect<valType>::operator*(const valType &val)
{
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = val*pVect[i];
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // сложение
vect<valType> vect<valType>::operator+(const vect<valType> &v)
{
	if (size != v.size)
	{
		throw(v);
	}
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = pVect[i] + v.pVect[i];
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // вычитание
vect<valType> vect<valType>::operator-(const vect<valType> &v)
{
	if (size != v.size)
	{
		throw(v);
	}
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = pVect[i] - v.pVect[i];
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // скалярное произведение
valType vect<valType>::operator*(const vect<valType> &v)
{
	if (size != v.size) {
		throw(v);
	}
	int tmp = 0;
	for (int i = 0; i < size; i++)
		tmp = tmp + v.pVect[i] * pVect[i];
	return tmp;
} /*-------------------------------------------------------------------------*/


  //Верхнетреугольная матрица