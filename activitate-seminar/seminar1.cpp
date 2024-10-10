#include <iostream>
using namespace std;

struct coordonateGPS
{
	int latitudine;
	int longitudine;
	float altitudine;
	string locatie;
};

void afisarecoord(coordonateGPS l)
{
	cout << "Latitudine:" << l.latitudine << endl;
	cout << "Longitudine:" << l.longitudine << endl;
	cout << "Altitudine:" << l.altitudine << endl;
	cout << "Locatie:" << l.locatie << endl;
}

void overwrite(coordonateGPS& l, coordonateGPS& l2)
{
	l.latitudine = l2.latitudine;
	l.longitudine = l2.longitudine;
	l.altitudine = l2.altitudine;
	l.locatie = l2.locatie;
}

coordonateGPS initCoord(int latitudine, int longitudine, float altitudine, string locatie)
{
	coordonateGPS l;
	l.latitudine = latitudine;
	l.longitudine = longitudine;
	l.altitudine = altitudine;
	l.locatie = locatie;

	return l;
}

int main()
{
	coordonateGPS l;
	l.latitudine = 46;
	l.longitudine = 22;
	l.altitudine = 1010;
	l.locatie = "Predeal";

	afisarecoord(l);
	cout << endl;

	coordonateGPS l2;
	cout << "Introduceti latitudinea" << endl;
	cin >> l2.latitudine;
	cout << "Introduceti longitudinea" << endl;
	cin >> l2.longitudine;
	cout << "Introduceti altitudinea" << endl;
	cin >> l2.altitudine;
	cout << "Introduceti locatia" << endl;
	cin >> l2.locatie;
	cout << endl;

	afisarecoord(l2);

	cout << endl << "Vrei sa suprascrii noua locatie?" << endl;
	cout << "1 - da      0 - nu" << endl;
	int ans;
	cin >> ans;
	cout << endl;
	if (ans)
	{
		overwrite(l, l2);
		afisarecoord(l);
	}



	return 0;
}