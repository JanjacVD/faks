#include <iostream>
#include <vector>

using namespace std;

class Slika {
public:
	int price;
	static int total, n;
	Slika(int _price) : price(_price) {
		n++;
		total += _price;
	}
	static double ProsjecnaCijena() {
		return(double) total / n;

	}
};

int Slika::total = 0;
int Slika::n = 0;
int a() {

	Slika Slika1(2000); // 2000 eura

	Slika Slika2(3000); // 3000 eura

	Slika Slika3(1800); // 1800 eura

	cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura

	return 0;
}
