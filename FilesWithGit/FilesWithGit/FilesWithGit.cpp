// CODE SECTION - Member1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Jacket {
	string brand;
	string material;
	string colour;
	string size;
	float price;

	Jacket(string br="", string mt="", string cl="", string si="", float pr=0.0) {
		brand = br;
		material = mt;
		colour = cl;
		size = si;
		price = pr;
	}
};

// CODE SECTION - END

//CODE SECTION - Member2
void InputData(struct Jacket*, int);
void WriteData(struct Jacket*, int);
void ReadData(struct Jacket*, int);
void FilterData(struct Jacket*, int);


int main()
{
	const int iterations = 5;	// Controls how many times the loops will run. Make this the size of the array and all for loops

	struct Jacket jackets[iterations];
	struct Jacket* p_jackets;

	p_jackets = jackets;

	InputData(p_jackets, iterations);
	WriteData(p_jackets, iterations);
	ReadData(p_jackets, iterations);
	FilterData(p_jackets, iterations);

	return 0;
}

void InputData(struct Jacket* p_jackets, int iterations) {

	for (int i = 0; i < iterations; i++) {
		cout << "\nINPUT DATA for JACKET " << i + 1 << " (NO SPACES)" << endl;
	
		
		cout << "\nPlease enter the Jacket's Brand: ";
		cin >> (p_jackets + i)->brand;
		cout << "Please enter the Jacket's Material: ";
		cin >> (p_jackets + i)->material;
		cout << "Please enter the Jacket's Colour: ";
		cin >> (p_jackets + i)->colour;
		cout << "Please enter the Jacket's Size: ";
		cin >> (p_jackets + i)->size;
		cout << "Please enter the Jacket's Price: ";
		cin >> (p_jackets + i)->price;

		cout << "\n*********************************\n";
	}
}

void WriteData(struct Jacket* p_jackets, int iterations) {

	fstream fs;	// I am opening a new fstream each time becuause I could not figure out how to pass fstream variables as parameters

	fs.open("Jackets.txt", ios::out);

	for (int i = 0; i < iterations; i++) {
		fs << "#Jacket " << i + 1 << endl;
		fs << (p_jackets + i)->brand << endl;
		fs << (p_jackets + i)->material << endl;
		fs << (p_jackets + i)->colour << endl;
		fs << (p_jackets + i)->size << endl;
		fs << (p_jackets + i)->price << endl;
		fs << "#-------------\n" << endl;
	}

	fs.close();
}

//CODE SECTION - END

//CODE SECTION - Member1
void ReadData(struct Jacket* p_jackets, int iterations) {
	string data;
	
	fstream fs;

	fs.open("Jackets.txt", ios::in);
	while (getline(fs, data)) {
		cout << data << endl;
	}

	fs.close();
}

void FilterData(struct Jacket* p_jackets, int iterations) {
	bool jacketFound = false;
	string input;
	cout << "\n\nWhat Size Jacket are you looking for?\nPlease Enter a Size(XS, S, M, L, XL, XXL etc.): ";
	cin >> input;

	for (int i = 0; i < iterations; i++) {
		if (input == (p_jackets + i)->size) {
			cout << "\n\nJacket Found, printing details.\n";
			cout << "\nJacket Brand: " << (p_jackets + i)->brand;
			cout << "\nJacket Material: " << (p_jackets + i)->material;
			cout << "\nJacket Colour: " << (p_jackets + i)->colour;
			cout << "\nJacket Size: " << (p_jackets + i)->size;
			cout << "\nJacket Price: " << (p_jackets + i)->price;
			jacketFound = true;
		}
		else if(input != (p_jackets + 1)->size) {
			cout << "\nSearching...\n";
		}
	}

	if (jacketFound == false) {
		cout << "\nSorry, no Jacket in " << input << " size could be found.";
	}
	
}