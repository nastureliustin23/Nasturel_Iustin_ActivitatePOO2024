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

};

int Masina::TVA = 19;

int main()
{
	Masina m;
	m.afisare();
	return 1000;
}