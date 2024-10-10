#include <iostream>
using namespace std;

struct Tara {
	char* denumire;
	int nrlocuitori;
	string capitala;
	bool areIesireLaMare;
};

void afisareTara() {

}

void afisarePointerTara(Tara* pt) {
	cout << "Nume: " << pt->denumire << endl;
	cout << "Numar locuitori: " << pt->nrlocuitori << endl;
	cout << "Capitala: " << pt->capitala << endl;
	cout << "Are iesire la mare: " << (pt->areIesireLaMare ? "DA" : "NU") << endl;
}

Tara* citirePointerLaTara() {

	Tara* p = new Tara();

	cout << "Denumire: ";
	char buffer[100];
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);

	cout << "Capitala: ";
	cin >> p->capitala;

	cout << "Numar locuitori: ";
	cin >> p->nrlocuitori;

	cout << "Are iesire la mare? (0-NU; 1-DA) ";
	cin >> p->areIesireLaMare;

	return p;
}

int main()
{
	Tara tara;
	tara.areIesireLaMare = false;

	Tara* pTara;
	pTara = new Tara();
	pTara->areIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");
	pTara->nrlocuitori = 200;

	afisarePointerTara(pTara);
	cout << endl;
	delete[]pTara->denumire;
	delete pTara;

	/*
	Tara* p2Tara = citirePointerLaTara();
	cout << endl;
	afisarePointerTara(p2Tara);
	*/

	int nrPointeri = 2;

	Tara* vector;
	vector = new Tara[nrPointeri];

	delete[]vector;

	Tara** pointeri;
	pointeri = new Tara * [nrPointeri];

	for (int i = 0; i < nrPointeri; i++) {
		cout << endl;
		pointeri[i] = citirePointerLaTara();
	}

	for (int i = 0; i < nrPointeri; i++)
	{
		cout << endl;
		afisarePointerTara(pointeri[i]);
	}

	/*
	delete[]pointeri

	creaza un memory leak, adica ramane o zona de memorie alocata dar inaccesibila;
	*/

	for (int i = 0; i < nrPointeri; i++)
	{
		delete[]pointeri[i]->denumire;
		delete pointeri[i];
	}
	delete[]pointeri;
}