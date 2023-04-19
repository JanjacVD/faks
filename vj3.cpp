#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cigla {
public:
	int a, b, c;
	Cigla(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Cigla operator --(int){
		this->a --;
		this->b --;
		this->c --;
		return *this;
	}

	Cigla operator += (const Cigla &X){
		vector<int> indexesLeft;
		vector<int> indexesRight;
		if (this->a == X.a && this->b == X.b) this->c += X.c;
		else if (this->a == X.a && this->b == X.c) this->c += X.b;
		else if (this->a == X.b && this->b == X.a) this->c += X.c;
		else if (this->a == X.b && this->b == X.c) this->c += X.a;
		else if (this->a == X.c && this->b == X.a) this->c += X.b;
		else if (this->a == X.c && this->b == X.b) this->c += X.a;

		else if (this->b == X.a && this->c == X.b) this->a += X.c;
		else if (this->b == X.a && this->c == X.c) this->a += X.b;
		else if (this->b == X.b && this->c == X.a) this->a += X.c;
		else if (this->b == X.b && this->c == X.c) this->a += X.a;
		else if (this->b == X.c && this->c == X.a) this->a += X.b;
		else if (this->b == X.c && this->c == X.b) this->a += X.a;

		else if (this->a == X.a && this->c == X.c) this->b += X.b;
		else if (this->a == X.a && this->c == X.b) this->b += X.c;
		else if (this->a == X.b && this->c == X.a) this->b += X.c;
		else if (this->a == X.b && this->c == X.c) this->b += X.a;
		else if (this->a == X.c && this->c == X.a) this->b += X.b;
		else if (this->a == X.c && this->c == X.b) this->b += X.a;
		else {
			throw std::invalid_argument("Nepravilne dimenzije");
		}
		return *this;
	}

};
ostream& operator <<(ostream& izlaz, Cigla X) {
	izlaz << X.a << " " << X.b << " " << X.c << endl;
	return izlaz;
}

int main() {
	try {
		Cigla a(1, 2, 3); //1, 2 i 3 su duljine bridova cigle. Cigla je kvadar
		Cigla b(2, 3, 4);
		a += b; //Lijepimo ciglu b na plohu 2x3 (cigle se lijepe na plohu istih dimenzija), i dobivamo ukupno ciglu veličine 5x2x3

		cout << a; //5 x 2 x 3
		a += Cigla(3, 5, 1);
		cout << a; //5 3 3
		a += Cigla(3, 3, 2);
		cout << a; //7 x 3 x 3

		a--;
		a--;
		cout << a; // 5 x 1 x 1
		return 0;
	}
	catch (string e) {
		cout << e;
	}

}
