#pragma once
#ifndef VECTORDINAMIC_H
#define VECTORDINAMIC_H
//VectorDinamic.h
typedef int TElem;

class VectorDinamic {
private:
	int size;
	int cap;
	TElem *vect;
	void resize();

public:
	void resizesterge();
	void print();
	void setsize(int i);
	void resizemax(int i);
	int valid(int i) const;
	VectorDinamic() {
		size = 0;
		cap = 1;
		vect = new TElem[1];
	}
	// constructor
//arunca exceptie in cazul in care capacitate e <=0
	VectorDinamic(int capacitate);

	// returnare dimensiune
	int dim() const;
	// returnare element
	//arunca exceptie daca i nu e valid
	//indicii ii consideram de la 0
	TElem element(int i) const;

	//modifica element de pe pozitia i si returneaza vechea valoare
			//arunca exceptie daca i nu e valid
	TElem modifica(int i, TElem e);
	// adaugare element la sfarsit
	void adaugaSfarsit(TElem e);


	// adaugare element pe o pozitie i 
	//arunca exceptie daca i nu e valid
	void adauga(int i, TElem e);

	// sterge element de pe o pozitie i si returneaza elementul sters
	//arunca exceptie daca i nu e valid
	TElem sterge(int i);
	~VectorDinamic();
	void adaugamax(int i, TElem e);
};






/*
// returnare iterator
IteratorVectorDinamic iterator();

//destructor
~VectorDinamic();

};*/


#endif // !VECTORDINAMIC_H


