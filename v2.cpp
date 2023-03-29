#include <iostream>;
#include <vector>;
#include <algorithm>;
using namespace std;

class Knjiga{
public:
	string name;
	string author;
	int borrowed;
	int available;

	Knjiga(string _name, string _author, int _num1, int _num2) {
		name = _name;
		author = _author;
		borrowed = _num1;
		available = _num2;
	}
};
class Knjiznica{
public:
	string name;
	string address;
	vector<Knjiga> books;

	Knjiznica(string _name, string _address, Knjiga _book) {
		name = _name;
		address = _address;
		books.push_back(_book);
	}

	vector<Knjiga> PriKrajuZaliha() {
		vector<Knjiga> b;
		for (int i = 0; i < books.size(); i++) {
			if (this->books[i].available < 10) {
				b.push_back(this->books[i]);
			}
		}
		return b;
	}

	void Sortiraj() {
		for (int i = 0; i < books.size(); i++) {
			for (int j = i+1; j < books.size(); j++)
			{
				if (books[j].borrowed > books[i].borrowed) {
					Knjiga tempBook = books[j];
					books[j] = books[i];
					books[i] = tempBook;
				}
			}
		}
	}
	void addBook(Knjiga b) {
		this->books.push_back(b);
	}

	
};

Knjiznica NajvisePrimjeraka(vector<Knjiznica> libs) {
	int k = 0;
	int c = 0;
	for (int i = 0; i < libs.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < libs[i].books.size(); j++) {
			count += libs[i].books[j].available;
		}
		if (count > c) {
			k = i;
		}
	}
	return libs[k];
}
int main() {
	Knjiga knjiga("Knjiga 1", "Autor 1", 20, 15);
	/*Knjiga knjiga1("Knjiga 1", "Autor 1", 30, 1005);
	Knjiga knjiga2("Knjiga 1", "Autor 1", 24, 15);
	Knjiga knjiga3("Knjiga 1", "Autor 1", 26, 15);
	Knjiga knjiga4("Knjiga 1", "Autor 1", 27, 5);
	Knjiga knjiga5("Knjiga zaliha", "Autor z", 2, 1);
	Knjiga knjiga6("Knjiga 1", "Autor 1", 29, 15);*/
	
	Knjiznica knjiznica("Knjiznica 1", "Adresa 1", knjiga); // knjiga je automatski dodana knjižnici
	Knjiznica knjiznica2("Knjiznica 2", "Adresa 2", knjiga); // knjiga je automatski dodana knjižnici
	//vector < Knjiznica> libraries;

	/*knjiznica.addBook(knjiga1);
	knjiznica.addBook(knjiga2);
	knjiznica.addBook(knjiga3);
	knjiznica2.addBook(knjiga4);
	knjiznica2.addBook(knjiga5);
	knjiznica2.addBook(knjiga6);
	libraries.push_back(knjiznica);
	libraries.push_back(knjiznica2);*/
	//Knjiznica MaxValue = NajvisePrimjeraka(libraries);
		//cout << MaxValue.name << " ";

	//knjiznica.Sortiraj();
	//for (int i = 0; i < knjiznica.books.size(); i++)
	//{
	//}
}
