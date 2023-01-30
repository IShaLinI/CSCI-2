#include <iostream>
#include <string>

using namespace std;

template<class T>
struct Student {
	string name;
	int ID;
	T testAvg, hwAvg, finalAvg;
	float testWeight, hwWeight, finalWeight;

	void display(void);
	double calculateWeightedAverage(void);
	char getGrade(void);

	void setAvgs(T testAvg, T hwAvg, T finalAvg);
	void setWeights(float testWeight, float hwWeight, float finalWeight);

};


int main(void) {

	Student<double> TestStudent;

	cout << "Enter Students Name: "; 
	string name;
	getline(cin, name);

	cout << "Enter Students ID: ";
	int id;
	cin >> id;

	cout << "Test Average: ";
	double testAvg;
	cin >> testAvg;

	cout << "HW Average: ";
	double hwAvg;
	cin >> hwAvg;

	cout << "Final Average: ";
	double finalAvg;
	cin >> finalAvg;

	cout << "Test Weight: ";
	float testWeight;
	cin >> testWeight;

	cout << "HW Weight: ";
	float hwWeight;
	cin >> hwWeight;

	cout << "Final Weight: ";
	float finalWeight;
	cin >> finalWeight;


	TestStudent.name = "Jimmy";

	TestStudent.ID = id;

	TestStudent.setAvgs(testAvg, hwAvg, finalAvg);
	TestStudent.setWeights(testWeight, hwWeight, finalWeight);

	cout << endl;

	TestStudent.display();

	return 0;
}

template<class T>
void Student<T>::display(void)
{

	cout << "Student: " << name << endl;
	cout << "ID: " << ID << endl;
	cout << "Grade: " << calculateWeightedAverage() << " | " << getGrade() << endl;

}

template<class T>
double Student<T>::calculateWeightedAverage(void)
{
	return hwWeight*hwAvg + testWeight*testAvg + finalWeight*finalAvg;
}

template<class T>
char Student<T>::getGrade(void)
{	
	double grade = calculateWeightedAverage();

	if (grade >= 90) {
		return 'A';
	}
	else if(grade >= 80)
	{
		return 'B';
	}
	else if (grade >= 70) {
		return 'C';
	}
	else if (grade >= 60) {
		return 'D';
	}
	
	return 'F';
}

template<class T>
void Student<T>::setAvgs(T testAvg, T hwAvg, T finalAvg)
{

	if (testAvg > 0 && hwAvg > 0 && finalAvg > 0) {
		this->testAvg = testAvg;
		this->hwAvg = hwAvg;
		this->finalAvg = finalAvg;
	}
	else
	{
		throw out_of_range("Averages must be positive");
	}


}

template<class T>
void Student<T>::setWeights(float testWeight, float hwWeight, float finalWeight)
{
	if (testWeight > 0 && hwWeight > 0 && finalWeight > 0) {
		if ((testWeight + hwWeight + finalWeight) == 1) {
			this->testWeight = testWeight;
			this->hwWeight = hwWeight;
			this->finalWeight = finalWeight;
		}
		else
		{
			throw out_of_range("Weights must sum to 100");
		}
	}
	else
	{
		throw out_of_range("Weights must be positive");
	}
}
