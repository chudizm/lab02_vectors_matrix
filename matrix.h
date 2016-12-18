//����������������� �������
#pragma once
#include "vector.h"
#include <iostream>
using namespace std;


template <class valType>
class matrix : public vect<vect<valType> >
{
public:
	matrix(int _size = 10);
	matrix(const matrix &mt);                    // �����������
	matrix(const vect<vect<valType> > &mt); // �������������� ����
	bool operator==(const matrix &mt) const;      // ���������
	bool operator!=(const matrix &mt) const;      // ���������
	matrix& operator= (const matrix &mt);        // ������������
	matrix  operator+ (const matrix &mt);        // ��������
	matrix  operator- (const matrix &mt);        // ���������
	matrix  operator* (const matrix &mt);
												   // ���� / �����
	friend istream& operator>>(istream &is, matrix &mt)
	{
		for (int i = 0; i < mt.size; i++)
		{
			is >> mt.pVect[i];
		}
		return is;
	}
	friend ostream & operator<<(ostream &os, const matrix &mt)
	{
		for (int i = 0; i < mt.size; i++)
		{
			for (int j = 0; j<mt.pVect[i].getStartInd(); j++) cout << "    ";
			os << mt.pVect[i] << endl;
		}
		return os;
	}
};

template <class valType>
matrix<valType>::matrix(int _size) : vect<vect<valType> >(_size)
{
	if (_size > MAX_MATRIX_SIZE) throw (_size);
	for (int i = 0; i < _size; i++)
		pVect[i] = vect<valType>(_size - i, i);
} /*-------------------------------------------------------------------------*/

template <class valType> // ����������� �����������
matrix<valType>::matrix(const matrix<valType> &mt) :
	vect<vect<valType> >(mt) {}

template <class valType> // ����������� �������������� ����
matrix<valType>::matrix(const vect<vect<valType> > &mt) :
	vect<vect<valType> >(mt) {}

template <class valType> // ���������
bool matrix<valType>::operator==(const matrix<valType> &mt) const
{
	if (size != mt.size) return false;
	//	if (startInd != mt.startInd) return false;
	for (int i = 0; i < size; i++)
	{
		if (pVect[i] != mt.pVect[i]) return false;
	}
	return true;
} /*-------------------------------------------------------------------------*/

template <class valType> // ���������
bool matrix<valType>::operator!=(const matrix<valType> &mt) const
{
	if (*this == mt) return false;
	else return true;
} /*-------------------------------------------------------------------------*/

template <class valType> // ������������
matrix<valType>& matrix<valType>::operator=(const matrix<valType> &mt)
{
	if (*this != mt)
	{
		if (size != mt.size)
		{
			delete[]pVect;
			pVect = new vect<valType>[mt.size];
		}
		size = mt.size;
		startInd = mt.startInd;
		for (int i = 0; i < size; i++)
			pVect[i] = mt.pVect[i];
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class valType> // ��������
matrix<valType> matrix<valType>::operator+(const matrix<valType> &mt)
{
	matrix<int> tmp = vect<vect<valType> >::operator+(mt);
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class valType> // ���������
matrix<valType> matrix<valType>::operator-(const matrix<valType> &mt)
{
	matrix<int> tmp = vect<vect<valType> >::operator-(mt);
	return tmp;
} /*-------------------------------------------------------------------------*/
template <class valType> // ���������
matrix<valType> matrix<valType>::operator*(const matrix<valType> &mt)
{
	matrix<valType> tmp(size);
	for (int i = 0; i<size; i++)
	{
		for (int j = i; j<size; j++)
		{
			int tmp2 = 0;
			for (int k = i; k < j + 1; k++)
				tmp2 += pVect[i].getValue(k) * mt.pVect[k].getValue(j);
			tmp[i][j] = tmp2;
		}
	}
	return tmp;
}
