/*
Elliot Putnam
CS210-H7882
The purpose of this program is to take user input data for initial amount, monthly
deposits, interest rate, and total years and output the year-end interest gain.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Initialize class
class Investment {

// Initialze private variables
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestRate;
    int numberOfYears;

public:

    // Constructor for investment WITHOUT monthly deposits
    Investment(double initialInvestment, double interestRate, int numberOfYears) {
        this->m_initialInvestment = initialInvestment;
        this->m_interestRate = interestRate;
        this->numberOfYears = numberOfYears;
        this->m_monthlyDeposit = 0;
    }

    // Constructor for investment WITH monthly deposits
    Investment(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
        this->m_initialInvestment = initialInvestment;
        this->m_monthlyDeposit = monthlyDeposit;
        this->m_interestRate = interestRate;
        this->numberOfYears = numberOfYears;
    }

    // Method for calculating monthly compounding interest
    double calculateMonthlyCompoundingInterest() {
        double monthlyRate = m_interestRate / 1200.0;
        int numberOfMonths = numberOfYears * 12;
        double balance = m_initialInvestment;
        for (int i = 1; i <= numberOfMonths; i++) {
            balance += m_monthlyDeposit;
            balance *= 1 + monthlyRate;
        }
        return balance;
    }


    // Method for displaying output
    void printTable() {
        double balance = m_initialInvestment;
        double monthlyRate = m_interestRate / 1200.0;
        int numberOfMonths = numberOfYears * 12;
        cout << setw(10) << "Year" << setw(20) << "Year-End Balance" << setw(20) << "Year-End Interest" << endl;
        for (int i = 1; i <= numberOfYears; i++) {
            double yearEndInterest = 0;
            for (int j = 1; j <= 12; j++) {
                balance += m_monthlyDeposit;
                double monthlyInterest = balance * monthlyRate;
                yearEndInterest += monthlyInterest;
                balance *= 1 + monthlyRate;
            }
            cout << setw(10) << i << setw(20) << fixed << setprecision(2) << balance << setw(20) << yearEndInterest << endl;
        }
    }
};

// Method for receiving user inputs
void promptUser(double& initialInvestment, double& monthlyDeposit, double& interestRate, int& numberOfYears) {
    cout << "Enter initial investment: ";
    cin >> initialInvestment;
    cout << "Enter monthly deposit: ";
    cin >> monthlyDeposit;
    cout << "Enter annual interest rate: ";
    cin >> interestRate;
    cout << "Enter number of years: ";
    cin >> numberOfYears;
    cout << endl;
}

// Define main method
int main() {

    // Initialize variables
    double initialInvestment, monthlyDeposit, interestRate;
    int numberOfYears;

    // calls method to prompt for user input
    promptUser(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

    // Creates objects for each investment type
    Investment investment1(initialInvestment, interestRate, numberOfYears);
    Investment investment2(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

    // Displays line for each balance type
    cout << "Year-end balance without deposits" << fixed << setprecision(2) << ": $" << investment1.calculateMonthlyCompoundingInterest() << endl;
    cout << endl;

    // Calls printTable for object investment1
    investment1.printTable();
    cout << endl;
    
    // Displays line for each balance type
    cout << "Year-end balance with monthly deposits of $" << monthlyDeposit << ": $" << investment2.calculateMonthlyCompoundingInterest() << endl;
    cout << endl; 
    
    // Calls printTable for object investment2
    investment2.printTable();
    cout << endl;
    
    return 0;
    
}