#include <iostream>
using namespace std;

class Masina {
private:
	int nrRoti;
	string* Producatori;
	string Marca;//
	float Pret;//
	static int TVA;
	const int anFabricatie;

public:

	Masina() :anFabricatie(2024) {
		this->nrRoti = 4;
		this->Marca = "Dacia";
		this->Pret = 5000;
		this->Producatori = NULL;
	}

	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->Marca = marca;
		this->Pret = pret;
		this->Producatori = new string[this->nrRoti];
		for (int i = 0; i < this->nrRoti; i++) {
			this->Producatori[i] = "Michelin";
		}
	}

	Masina(const Masina& m):anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		this->Marca = m.Marca;
		this->Pret = m.Pret;
		this->Producatori = new string[m.nrRoti];
		for (int i = 0; i < m.nrRoti; i++) {
			this->Producatori[i] = m.Producatori[i];
		}
	}

	~Masina() {
		if(this->Producatori != NULL) {
			delete[]this->Producatori;
		}
	}

	string getMarca() {
		return this->Marca;
	}
	void setMarca(string Marca) {
		if (Marca.length() > 2) {
			this->Marca = Marca;
		}
	}

	float getPret() {
		return this->Pret;
	}
	void setPret(float Pret) {
		if (Pret > 0) {
			this->Pret = Pret;
		}
	}

	string* getProducatori() {
		return this->Producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->Producatori[index];
		}
		else {
			return "Nu a fosy gasit";
		}
	}

	void setNrRoti(int nrRoti, string* Producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->Producatori != NULL)
			{
				delete []this->Producatori;
			}
			this->Producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->Producatori[i] = Producatori[i];
			}
		}
	}

	void afisare() {
		cout << "Marca: " << this->Marca << endl;
		cout << "Numar roti: " << this->nrRoti << ": ";
		if (this->Producatori != NULL) {
			for (int i = 0; i < this->nrRoti; i++) {
				cout << this->Producatori[i] << ", ";
			}
		}
		cout << "Pret: " << this->Pret << endl;
		cout << "TVA: " << this->TVA << endl;
		cout << "anFabricatie: " << this->anFabricatie << endl;
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
	Masina m;
	cout << m.getMarca() << endl;
	m.setMarca("Audi");
	cout << m.getMarca() << endl;
	m.afisare();

	Masina m2(4, "BMW", 4500, 2021);
	m2.afisare();

	cout << endl << endl;

	cout << m2.getProducatori()[1] << endl;

	cout << m2.getProducator(1) << endl;;

	m2.setNrRoti(6, new string[6]{"Michelin", "Continental", "Bridgestone", "Pirelli", "Hankook", "POO"});
	cout << m2.getProducator(5) << endl;;

	Masina m3(m2);
	Masina m4 = m2;

	cout<<m4.getProducator(2);
}