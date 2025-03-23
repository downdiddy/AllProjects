#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class mPayment
{
    private:
        double amount;
        double interest;
        int numYears;
    public:
        //Setter and getter methods
        mPayment(double a, double i, int n)
        {
            amount = a;
            interest = i;
            numYears = n;
        }
        void setAmount(double a)
        {
            amount = a;
        }
        double getAmount()
        {
            return amount;
        }
        void setInterest(double i)
        {
            interest = i;
        }
        double getInterest()
        {
            return interest;
        }
        void setNumYears(int n)
        {
            numYears = n;
        }
        int getNumYears()
        {
            return numYears;
        }
        double monthlyPayment()
        {
            return amount * (interest / 1200.0) * pow(1 + interest / 1200.0, numYears * 12) / (pow(1 + interest / 1200.0, numYears * 12) - 1);
        }
        double totalPayment()
        {
            return monthlyPayment() * numYears * 12;
        }
};

int main()
{
    double amt, rate;
    int years;
    cout << "Enter the amount of the loan, then the interest rate, and finally the number of years: ";
    cin >> amt >> rate >> years;
    while((amt < 0.0) || (rate < 0.0) || (years < 0))
    {
        cout << "Not valid numbers, please enter valid amount of the loan, then the interest rate, and finally the number of years: ";
        cin >> amt >> rate >> years;
    }
    mPayment loan(amt, rate, years);
    cout << "The monthly payment is: $" << fixed << setprecision(2) << loan.monthlyPayment() << endl;
    cout << "The total payment is: $" << fixed << setprecision(2) << loan.totalPayment() << endl;
    return 0;
}