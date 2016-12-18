// ����������������� ������� - ���������� �� ������ ������� �������

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// ������ �������
template <class valType>
class vect
{
protected:
	valType *pVect;
	int size;       // ������ �������
	int startInd; // ������ ������� �������� �������
public:
	vect(int _size = 10, int _startInd = 0);
	vect(const vect &v);                // ����������� �����������
	~vect();
	int getSize() { return size; } // ������ �������
	int getStartInd() { return startInd; } // ������ ������� ��������
	int getValue(int index) { return pVect[index - startInd]; };
	valType& operator[](int pos);             // ������
	bool operator==(const vect &v) const;  // ���������
	bool operator!=(const vect &v) const;  // ���������
	vect& operator=(const vect &v);     // ������������

											  // ��������� ��������
	vect  operator+(const valType &val);   // ��������� ������
	vect  operator-(const valType &val);   // ������� ������
	vect  operator*(const valType &val);   // �������� �� ������

											  // ��������� ��������
	vect  operator+(const vect &v);     // ��������
	vect  operator-(const vect &v);     // ���������
	valType  operator*(const vect &v);     // ��������� ������������

											  // ����-�����
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
template <class valType> //����������� �����������
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

template <class valType> // ������
valType& vect<valType>::operator[](int pos)
{
	if ((pos - startInd >= 0) && (pos - startInd < size))
		return pVect[pos - startInd];
	else throw(pos);
} /*-------------------------------------------------------------------------*/

template <class valType> // ���������
bool vect<valType>::operator==(const vect &v) const
{
	if (size != v.size) return false;
	if (startInd != v.startInd) return false;
	for (int i = 0; i < size; i++)
		if (pVect[i] != v.pVect[i]) return false;
	return true;
} /*-------------------------------------------------------------------------*/

template <class valType> // ���������
bool vect<valType>::operator!=(const vect &v) const
{
	if (v == *this) return false;
	else return true;
} /*-------------------------------------------------------------------------*/

template <class valType> // ������������
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

template <class valType> // ��������� ������
vect<valType> vect<valType>::operator+(const valType &val)
{
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = pVect[i] + val;
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // ������� ������
vect<valType> vect<valType>::operator-(const valType &val)
{
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = pVect[i] - val;
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // �������� �� ������
vect<valType> vect<valType>::operator*(const valType &val)
{
	vect tmp(size, startInd);
	for (int i = 0; i < size; i++)
		tmp.pVect[i] = val*pVect[i];
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // ��������
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

template <class valType> // ���������
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

template <class valType> // ��������� ������������
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


  //����������������� �������