#include <iostream>
using namespace std;

class Masina {
public:
	int nrRoti;
	string Marca;
	float Pret;
	static int TVA;
	const int anFabricatie;

	Masina():anFabricatie(2024) {
		this->nrRoti = 4;
		this->Marca = "Dacia";
		this->Pret = 5000;
	}

	void afisare() {
		cout << "Marca: " << this->Marca << endl;
		cout << "Numar roti: " << this->nrRoti << endl;
		cout << "Pret: " << this->Pret << endl;
		cout << "TVA: " << this->TVA << endl;
		cout << "anFabricatie: " << this->anFabricatie << endl;
	}
	Masina(int _nrRoti, string marca, float pret, int an):anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->Marca = marca;
		this->Pret = pret;
	}

	float calculeazaPretTotal() {
		return this->Pret + (this->Pret * (this->TVA / 100.0f));
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA >= 0) {
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotalVector = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotalVector += vector[i].calculeazaPretTotal();
		}
		return pretTotalVector;
	}

};

int Masina::TVA = 19;

int main()
{
	Masina m1;
	m1.afisare();
	
	cout << endl;

	Masina m2(4, "Audi", 7000, 2020);
	m2.afisare();

	cout << endl;

	Masina::modificaTVA(21);

	Masina* pointer = new Masina(6, "Hummer", 55000, 1998);
	pointer->afisare();

	cout << "Pret total:" << pointer->calculeazaPretTotal() << endl<<endl;

	int nrMasini = 3;
	Masina* vector;
	vector = new Masina[nrMasini];

	for (int i = 0; i < nrMasini; i++) {
		vector[i].afisare();
		cout << endl;
	}
	cout << "Pret total flota: " << Masina::calculeazaPretTotalVector(nrMasini, vector) << endl;

	delete[]vector;

	return 1000;
}