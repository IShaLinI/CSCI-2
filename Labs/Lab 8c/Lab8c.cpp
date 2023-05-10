//Andrew Card

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

//Amortization Schedule Entry
class AmortizationScheduleEntry{
    private:
        int paymentNumber;
        double paymentAmount;
        double principal;
        double interest;
        double balance;
    public:
        AmortizationScheduleEntry(int _paymentNumber, double _paymentAmount, double _principal, double _interest, double _balance){
            paymentNumber = _paymentNumber;
            paymentAmount = _paymentAmount;
            principal = _principal;
            interest = _interest;
            balance = _balance;
        }

        int getPaymentNumber(){
            return paymentNumber;
        }

        double getPaymentAmount(){
            return paymentAmount;
        }

        double getPrincipal(){
            return principal;
        }

        double getInterest(){
            return interest;
        }

        double getBalance(){
            return balance;
        }
};

//Amortization Schedule
class AmortizationSchedule{
    private:
        double loanAmount;
        double interestRate;
        int numberOfYears;
        double monthlyPayment;
        double totalPayment;
        double totalInterest;
        vector<AmortizationScheduleEntry> entries;
    public:
        AmortizationSchedule(double _loanAmount, double _interestRate, int _numberOfYears){
            loanAmount = _loanAmount;
            interestRate = _interestRate;
            numberOfYears = _numberOfYears;
            monthlyPayment = 0;
            totalPayment = 0;
            totalInterest = 0;
            entries.clear();

            calculate();

        }

        void calculate(){
            //Calculate the monthly payment
            monthlyPayment = loanAmount * (interestRate / 12) / (1 - pow(1 + (interestRate / 12), -1 * numberOfYears * 12));

            //Calculate the total payment
            totalPayment = monthlyPayment * numberOfYears * 12;

            //Calculate the total interest
            totalInterest = totalPayment - loanAmount;

            //Calculate the amortization schedule
            double balance = loanAmount;
            for(int i = 1; i <= numberOfYears * 12; i++){
                double interest = balance * (interestRate / 12);
                double principal = monthlyPayment - interest;
                balance -= principal;
                entries.push_back(AmortizationScheduleEntry(i, monthlyPayment, principal, interest, balance));
            }
        }

        double getLoanAmount(){
            return loanAmount;
        }

        double getInterestRate(){
            return interestRate;
        }

        int getNumberOfYears(){
            return numberOfYears;
        }

        double getMonthlyPayment(){
            return monthlyPayment;
        }

        double getTotalPayment(){
            return totalPayment;
        }

        double getTotalInterest(){
            return totalInterest;
        }

        vector<AmortizationScheduleEntry> getEntries(){
            return entries;
        }

        //Print the amortization schedule to a csv file
        void print(string fileName){
            ofstream outFile(fileName);

            outFile << "Payment Number,Payment Amount,Principal,Interest,Balance\n";

            for(int i = 0; i < entries.size(); i++){
                outFile << entries[i].getPaymentNumber() << "," << entries[i].getPaymentAmount() << "," << entries[i].getPrincipal() << "," << entries[i].getInterest() << "," << entries[i].getBalance() << "\n";
            }

            outFile.close();
        }
};

int main(){

    system("cls");

    double loanAmount;
    double term;
    double interestRate = 0.024;

    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the term (in years): ";
    cin >> term;

    AmortizationSchedule schedule(loanAmount, interestRate, 5);

    cout << "Loan Amount: " << schedule.getLoanAmount() << endl;
    cout << "Interest Rate: " << schedule.getInterestRate() << endl;
    cout << "Number of Years: " << schedule.getNumberOfYears() << endl;

    cout << "Monthly Payment: " << schedule.getMonthlyPayment() << endl;
    cout << "Total Payment: " << schedule.getTotalPayment() << endl;
    cout << "Total Interest: " << schedule.getTotalInterest() << endl;

    schedule.print("schedule.csv");

    return 0;
}