#pragma once
#ifndef MATRICE_H
#define MATRICE_H
#include "VectorDinamic.h"
using namespace std;
typedef int TElem;

#define NULL_TELEMENT 0

class Matrice {
private:
	int numarLinii;
	int numarColoane;
	VectorDinamic linie;
	VectorDinamic coloana;
	VectorDinamic valoare;
	VectorDinamic numere;
public:
	int valid(int i, int j);
	// constructor
	//arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int numLinii, int numColoane);

	// returnare numar linii
	int nrLinii() const;
	void resize_matrice();
	// returnare numar coloane
	int nrColoane() const;

	// returnare element de pe o linie si o coloana
	//arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii ii consideram de la 0
	TElem element(int i, int j) const;

	// modifica elementul de pe o linie si o coloana si returneaza vechea valoare
	//arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem e);

	//destructor
	void transpusa();
	void printm();
};




#endif // !MATRICE_H
