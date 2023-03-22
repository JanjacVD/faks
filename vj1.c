#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pedalina {
public:
	string color;
	int capactiy;
};

class Lokacija {
public:
	string fullName;
	vector<double> coordinates;
	vector<Pedalina> items;

};
int main() {
	int n;
	int m;
	vector<Lokacija> locations;
	cout << "Unesite broj lokacija (N): ";
	cin >> n;
	Lokacija newLocation;

	for (int i = 0; i < n; i++)
	{
		cout << " Unesite odgovornu osobu i GPS koordinate za " << i + 1 << ". lokaciju:";
		double x;
		double y;
		cin.ignore();
		getline(cin, newLocation.fullName);
		cin >> x;
		cin >> y;
		newLocation.coordinates.push_back(x);
		newLocation.coordinates.push_back(y);
		locations.push_back(newLocation);
	}
	cout << " Unesite broj pedalina (M): ";
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int j;
		Pedalina newItem;
		cout << " Unesite redni broj lokacije kojoj pripada "<< i+1 <<".pedalina: ";
		cin >> j;
		cout << " Unesite boju i kapacitet pedaline: ";
		cin >> newItem.color;
		cin >> newItem.capactiy;
		locations[j - 1].items.push_back(newItem);
	}

	cout << " Ispis lokacija i pedalina: \n";
	for (int i = 0; i < n; i++)
	{
		cout << i+1 <<". " << locations[i].coordinates[0] << " " << locations[i].coordinates[1] << " " << locations[i].fullName << " - pedaline: ";
		int l = locations[i].items.size();
		for (int k = 0; k < l; k++)
		{
			cout << locations[i].items[k].color << " " << locations[i].items[k].capactiy << " ";
		}
		cout << "\n";
	}
	return 0;
}
