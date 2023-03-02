#include <iostream>
#include <iomanip>

using namespace std;

template <typename T> 
struct Person {
	string name;
	string gender;
	typename T age;

	void printDetails(void) {
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Age: " << age << endl;
		cout << "Minor? : " << (isMinor() ? "Yes" : "No") << endl;
	}
	bool isMinor(void) {
		return age < 18;
	}
};

int main(void) {
	
	cout << fixed << setprecision(16);

	Person<float> p1 = { "James", "M", 18.1234672 }; //James knows his age pretty well.
	Person<double> p2 = {"Kevin", "M", 27.240102031203041}; //Kevin REALLY knows his age pretty well.
	Person<int> p3 = { "Stephanie", "F", 14};

	p1.printDetails();
	cout << endl;

	p2.printDetails();
	cout << endl;

	p3.printDetails();
	cout << endl;

	return 0;
}