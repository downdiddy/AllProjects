/*
Nihal Puchakatla
preferredCustomer.cpp
3/16/2025
version 1.2
This program finds how much discount to give based on how much a customer has spent
*/

#include <iostream>
#include <iomanip>
using namespace std;

class customerData{
private:
    string cusID;
public:
    customerData(string a){
        cusID = a;
    }
    //setters and getters
    void setcusID(string id){
        cusID = id;
    }
    string getcusID(){
        return cusID;
    }
};
class preferredCustomer : public customerData{
    private:
        double pAMT;
        int disLevel;
    public:
        preferredCustomer(double b, string n) : customerData(n){//constrcutor
            disLevel = 0;
            pAMT = b;
        }
        //setter and getters
        double getpAMT(){
            return pAMT;
        }
        void setpAMT(double amt){
        pAMT = amt;
        }
        int getDiscount(){//gives the right discount based on how they have spent in the store
            if(pAMT >= 500){
                disLevel = 5;
                if(pAMT >= 1000){
                    disLevel = 6;
                    if(pAMT >= 1500){
                        disLevel = 7;
                        if(pAMT >= 2000){
                            disLevel = 10;
                        }
                    }
                }
            }
            return disLevel;
        }
};

int main(){
    string customerID;
    double spentHistory;
    cout << "What is your Customer ID and how much have you spent in the store?: ";
    cin >> customerID >> spentHistory;//gets inputs from the user for ID and amount spent
    while(spentHistory < 0){
        cout << "That number does not count, please enter a proper amount: ";
        cin >> spentHistory;
    }
    preferredCustomer pc(spentHistory, customerID);//creates an object based on the given parameters
    cout << "since you have spent $" << fixed << setprecision(2) << spentHistory << ", you get a " << pc.getDiscount() << "% discount on your future purchases. Please keep on shopping to get a bigger discount in the future! Thank you!";//retusn the discount amount
}