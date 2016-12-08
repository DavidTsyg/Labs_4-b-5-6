#include <iostream>

using namespace std;

struct Toy
{
	char toy_model[64];
	char toy_condition[64];
};


struct Dog
{
	char name[128];
	int age;
    Toy toy;

};


int main()
{

	Dog *p1;
	int n;
	cout << "How many dogs are there ? ";
	cin >> n;
	p1 = new Dog[n];

	for (int i = 0; i<n; i++)
	{
		cin.clear();
		cout << "Dog № " << i + 1;
		cin.clear();
        cout << endl << "The dog's name ? ";
		cin >> p1[i].name;
		cin.clear();

		cout << endl << "The dog's age ?";
		cin >> p1[i].age;
		cin.clear();

		cout << endl << "The toy's model ? ";
		cin >> p1[i].toy.toy_model;
		cin.clear();

		cout << endl << "The toy's condition ?";
		cin >> p1[i].toy.toy_condition;
		cin.clear();
	}

	for (int i = 0; i<n; i++)
		cout << p1[i].name << " " << p1[i].age << " " << p1[i].toy.toy_model << " " << p1[i].toy.toy_condition << endl;
    int l = 0;

	for (int i = 0; i < n; i++)
        if (p1[i].age > 10) l++;
    if (l) cout << "Dogs, which deserve a new toy : " << l << endl;
    delete [] p1;
	return 0;
}
