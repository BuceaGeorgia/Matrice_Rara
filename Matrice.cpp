//4

#include "Matrice.h"
#include "VectorDinamic.h"
#include<iostream>
using namespace std;

void Matrice::transpusa()
{
	//theta(N)
	//N-numarul de elemente din matrice
	Matrice m(numarColoane,numarLinii);
	for (int i = 0;i <numarColoane;i++)
	{
		int p,r;
		p = coloana.element(i);
		r = i + 1;
		if (p != -1)
		{
			while (coloana.element(r) == -1&& r<numarColoane)
				r++;
			while (p != coloana.element(r)&&coloana.element(r)!=-1) {
				m.modifica(coloana.element(i),linie.element(p), valoare.element(p));
				p++;
			}
		}
	}
	
	//m.printm();
}

void Matrice::printm() {
	linie.print();

	coloana.print();
	valoare.print();
}
Matrice::Matrice(int numLinii, int numColoane) { 
	// theta(n)
	//n-numarul de coloane
	for (int i = 0;i < numColoane;i++)
	{
		coloana.adaugamax(i, -1);//theta(1)
		numere.adaugamax(i, 0);
	}
	coloana.adaugamax(numColoane, 0);
	coloana.setsize(0);
	numarLinii = numLinii;
	numarColoane = numColoane;
}

int Matrice::nrLinii()const {
	return numarLinii;
}
void Matrice::resize_matrice()
{
	valoare.resizesterge();
	linie.resizesterge();
}
int Matrice::nrColoane()const {
	return numarColoane;
}


TElem Matrice::element(int i, int j)const {
	// theta(n)
	//n-numarul de coloane
	try {

		int ok = 0;
		TElem e;
		
		int p = 0,r=coloana.element(numarColoane);
		for (int i = j+1;i < nrColoane();i++)
		{
			if (coloana.element(i) != -1)
			{
				r = coloana.element(i);
				break;
			}
		}
		while (linie.element(coloana.element(j) + p) != i && coloana.element(j)+p < r)
		{
			p++;
		}
		if (linie.element(coloana.element(j) + p) == i)
			return valoare.element(coloana.element(j) + p);
			return NULL_TELEMENT;
	}
	catch (int param) {
		return NULL_TELEMENT;
	}

}

TElem Matrice::modifica(int i, int j, TElem e) {
	//O(n)
	//n-numarul de coloane
	int p;
	try {

		if (coloana.element(j)==-1)
		{
			int sum = 0;
			for (int q = 0;q < j;q++)
			{
				sum += numere.element(q);
			}
		coloana.modifica(j, coloana.element(numarColoane)); //thete(1)
		coloana.setsize(coloana.dim() + 1);//theta(1)
		p = coloana.element(nrColoane());//theta(1)
		coloana.modifica(nrColoane(),p + 1);//theta(1)

		linie.adaugamax(coloana.element(j), i);//theta(linie.size)
		valoare.adaugamax(coloana.element(j), e);//theta(valoare.size)
		p = numere.element(j);//theta(1)
		numere.modifica(j, p + 1);//theta(1)

		}
		else
		{
			int ok = 0;
			
			if (ok == 0)
			{

				int q=-1,ok2=0;
				for (int w = j + 1;w < nrColoane();w++)//theta(numarColoane)
				{
					if (coloana.element(w) != -1)//theta(1)
					{
						
						if (ok2 == 0)
						{
							q = coloana.element(w);//theta(1)
							ok2 = 1;
						}
						coloana.modifica(w, coloana.element(w) + 1);//theta(1)
					}
				}
				if (q == -1)
				{
					linie.adaugamax(coloana.element(numarColoane), i);//theta(linie.size)
					valoare.adaugamax(coloana.element(numarColoane), e);//theta(linie.size)
				}
				else {
					linie.adaugamax(q, i);//theta(linie.size)
					valoare.adaugamax(q, e);//theta(linie.size)
				}
				p = coloana.element(nrColoane());//theta(1)
				coloana.modifica(nrColoane(), p + 1);//theta(1)
			}
		}
	}

	catch (char param) {
		return NULL_TELEMENT;
	}
}
int Matrice::valid(int i, int j)
{
	if (i < 0 || j < 0)
		return 0;
	if (i > nrLinii() || j < nrColoane())
		return 0;
	return 1;
}


