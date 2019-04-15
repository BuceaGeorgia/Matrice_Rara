#include "VectorDinamic.h"
#include <exception>
#include <iostream>
using namespace std;
TElem VectorDinamic::modifica(int i, TElem e) {
	// theta(1)
	if (i >= 0)
	{
		TElem old = vect[i];
		this->vect[i] = e;
		return old;
	}
	else
		throw (10);
}
TElem VectorDinamic::element(int i) const {
	if (i >= 0)
		return this->vect[i];
	else
		throw (10);
}

int VectorDinamic::dim() const {
	return this->size;
}

VectorDinamic::VectorDinamic(int capacitate)
{

	this->size = 0;
	this->cap = capacitate;
	this->vect = new TElem[capacitate];
}

void VectorDinamic::adaugaSfarsit(TElem e)
{
	if (size == cap)
	{
		resize();
	}
	vect[size] = e;
	size = size + 1;
}

void VectorDinamic::adauga(int i, TElem e) {

	if (valid(i) == 1)
	{
		size = size + 1;
		if (size >= cap)
		{
			resize();
		}
		int l;
		for (int j = size - 2;j >= i;j--)
		{
			l = vect[j];
			vect[j + 1] = vect[j];
		}
		vect[i] = e;
	}
	else {
		throw(10);
	}
}
void VectorDinamic::resize() {
	//theta(size)
	TElem *v;
	cap = 2 * cap;
	v = new TElem[cap];
	for (int i = 0;i < size;i++)
	{
		v[i] = vect[i];
	}
	delete[] this->vect;
	vect = v;
}
void VectorDinamic::resizesterge() {
	//theta(size)
	TElem *v;
	cap = size+1;
	v = new TElem[cap];
	for (int i = 0;i < size;i++)
	{
		v[i] = vect[i];
	}
	delete[] this->vect;
	vect = v;

}

int VectorDinamic::valid(int i)const {
	if (i < 0 || i>size)
		return 0;
	return 1;
}

TElem VectorDinamic::sterge(int i) {

	if (valid(i) == 1)
	{
		TElem p;
		p = vect[i];
		for (int j = i;j < size - 1;j++)
		{
			vect[j] = vect[j + 1];
		}
		size = size - 1;
		resizesterge();
		return p;
	}
	else {
		throw(10);
	}
}




VectorDinamic::~VectorDinamic() {
	delete[]this->vect;
}
void VectorDinamic::adaugamax(int i, TElem e) {
	if (i >= 0) {
		if (size >= cap)
			resize();
		/*if (i >= cap)
		{
			resizemax(i);
		}*/
		int l;
		for (int j = size - 1;j >= i;j--)
		{
			l = vect[j];
			vect[j + 1] = vect[j];
		}
		vect[i] = e;
		size += 1;
	}
	else {
		throw(10);
	}
}
void VectorDinamic::resizemax(int i)
{
	TElem *v;
	cap = 2 * (cap + i);
	v = new TElem[cap];
	for (int i = 0;i < size;i++)
	{
		v[i] = vect[i];
	}
	delete[] vect;
	vect = v;
}
void VectorDinamic::setsize(int i)
{
	size = i;
}
void VectorDinamic::print()
{
	for (int i = 0;i < cap;i++)
		printf("%d ", vect[i]);
	printf("\n");
	printf("\n");
}