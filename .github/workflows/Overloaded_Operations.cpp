/*
Nihal Puchakatla
Overloaded_Fractrions.cpp
3/16/2025
version 2.0
This program gets two fractions from the user then divides or multiples them, then compares the fractions.
*/

#include <iostream>
using namespace std;

class Fraction{
    private:
        int n, d;
        string same;
    public:
        Fraction(){
            n = 0.0;
            d = 0.0;
        }
        Fraction(int a, int b){// Constuctor
            n = a;
            d = b;
        } 
        //setter and getter
        void setNum(int a){
            n = a;
        }
        void setDem(int a){
            d = a;
        }
        void setSame(string a){
            same = a;
        }
        int getNum(){
            return n;
        }
        int getDem(){
            return d;
        }
        string getSame(){
            return same;
        }
        void gcf(){//simplies the fraction
            int smaller, larger;
            if(n < d){
                smaller = n;
                larger = d;
            }
            else{
                smaller = d;
                larger = n;
            }
            int r = larger % smaller;
            while(r != 0){
                larger = smaller;
                smaller = r;
                r = larger % smaller;
            }
            n = n / smaller;
            d = d / smaller;
        }
        //main part of the class
        friend Fraction operator/(const Fraction f1, const Fraction f2) {// the overloading function that divides the Fractions
            return Fraction((f1.n * f2.d), (f1.d * f2.n));
        }
        friend string operator==(const Fraction f1, const Fraction f2) {// the overloading function that checks if the Fractions are the same
            if((f1.n * f2.d) == (f2.n * f1.d))
                return "the same";
            else
                return "not the same";
        }
        friend Fraction operator*(const Fraction f1, const Fraction f2) {// the overloading function that multiples the Fractions
            return Fraction((f1.n * f2.n), (f1.d * f2.d));
        }
        friend istream& operator>>(istream& i, Fraction& f) {
            char s = '/';
            i >> f.n >> s >> f.d;
            return i;
        }
        friend ostream& operator << (ostream &O, const Fraction& f){ //the overloading function for printing out the Fraction object in the proper way
            char s = '/';
            if(f.n == f.d)
                O << "The answer is 1\n";
            else if(f.d == 1)
                O << "The answer is " << f.n << endl;
            else if(f.d == 0)
                O << "The answer is not a valid answer";
            else
                O << f.n << s << f.d << endl;
            return O;
        }
};
int main() {
    string check, oper;//to determine what the user wants to do
    int numerator, denominator;
    Fraction f1, f2, answer; //all fraction objects
    cout << "Would you like to multiply or divide two fractions (Yes or No)?: ";
    cin >> check;
    while ((check != "yes") && (check != "Yes") && (check != "No") && (check != "no")) { //input checker
        cout << "Not a valid response, try again: ";
        cin >> check;
    }
    if ((check == "yes") || (check == "Yes")) {
        cout << "Multiply or Divide?: ";
        cin >> oper;
        while((oper != "multiply") && (oper != "divide")){
            cout << "Not a valid response, try again: ";
            cin >> oper;
        }
        cout << "Would you like to compare them after? ";
        cin >> check;
        cout << "Type the first fraction(ex: 3/4): ";
        cin >> f1;
        cout << "Type the second fraction(ex: 3/4): ";
        cin >> f2;
        if (oper == "divide") //based on input, second then first
            answer = f1 / f2;
        else if(oper == "multiply")
            answer = f1 * f2;
        while ((check != "yes") && (check != "Yes") && (check != "No") && (check != "no")) { //input checker
            cout << "Not a valid response, try again: ";
            cin >> check;
        }
        if ((check == "Yes") || (check == "yes")) {
            string result = f1 == f2;
            cout << "\nThe fractions are " << result << endl << endl;
        }//prints out the the answer in a more fractional way
        answer.gcf();
        cout << endl << answer;
    }
    else
        cout << "Thank you, have a good day!";
}