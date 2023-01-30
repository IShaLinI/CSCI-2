#include <iostream>

using namespace std;

template <typename T>
T minElement(T arg1, T arg2);

template <typename T>
T maxElement(T arg1, T arg2);

int main(void) {

	int int1 = 15;
	int int2 = 27;

	double double1 = 43.2345;
	double double2 = 14.245;

	char char1 = 'U';
	char char2 = 'a';

	string string1 = "Three";
	string string2 = "Two";

	cout << "Integer Test:" << endl;
	cout << "Input: | " << int1 << " | " << int2 << " |\n";

	cout << "Min: " << minElement(int1, int2) << endl;
	cout << "Max: " << maxElement(int1, int2) << endl << endl;

	cout << "Double Test:" << endl;
	cout << "Input: | " << double1 << " | " << double2 << " |\n";

	cout << "Min: " << minElement(double1, double2) << endl;
	cout << "Max: " << maxElement(double1, double2) << endl << endl;

	cout << "Char Test:" << endl;
	cout << "Input: | " << char1 << " | " << char2 << " |\n";

	cout << "Min: " << minElement(char1, char2) << endl;
	cout << "Max: " << maxElement(char1, char2) << endl << endl;

	cout << "String Test:" << endl;
	cout << "Input: | " << string1 << " | " << string2 << " |\n";

	cout << "Min: " << minElement(string1, string2) << endl;
	cout << "Max: " << maxElement(string1, string2) << endl << endl;


	return 0;
}

template<typename T> 
T minElement(T arg1, T arg2)
{
	return (arg1 < arg2) ? arg1 : arg2;
}

template<typename T>
T maxElement(T arg1, T arg2)
{
	return (arg1 > arg2) ? arg1 : arg2;
}
