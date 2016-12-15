
#include <iostream>
using namespace std;

int Sum(double x, int y)
{
	return x + y;
}
int Sub(double x, int y)
{
	return x - y;
}
int main(int argc, char *argv[])
{
	int x, y;
	if (!sscanf_s(argv[1], "%d", &x))
	{
		cout << "arg1 is not valid" << endl;;
		system("pause");
		return 1;
	}
	if (!sscanf_s(argv[2], "%d", &y))
	{
		cout << "arg2 is not valid" << endl;;
		system("pause");
		return 1;
	}
	cout << "Addition: " << Sum(x, y) << endl;
	cout << "Subtraction: " << Sub(x, y) << endl;
	system("pause");
	return 0;
}
