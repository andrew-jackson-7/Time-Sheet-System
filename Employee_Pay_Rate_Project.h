//
//  Employee_Pay_Rate_Project.h
//  
//
//  Created by Andrew Jackson on 9/2/18.
//
//

#ifndef ____Employee_Pay_Rate_Project__
#define ____Employee_Pay_Rate_Project__

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iomanip> // Added 9/20/18

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::string;
using std::setw; // Added on 9/20/18
using std::fixed; // Added on 9/22/2018
using std::left; // Added on 9/22/2018
using std::right; // Added on 9/22/2018
using std::setprecision; // Added on 9/22/2018
using std::showpoint; // Added on 9/22/2018

class Employee
{
    private:
    
    string Employee_Last_Name;
    string Employee_First_Name;
    double pay_rate;
    double hours;
    
    public:
    
    Employee(string Employee_Last_Name, string Employee_First_Name, double pay_rate, double hours);
    
    //set functions
    void set_Employee_Last_Name(string Employee_Last_Name);
    void set_Employee_First_Name(string Employee_First_Name);
    void set_pay_rate(double pay_rate);
    void set_hours(double hours);
    
    //get functions
    string get_Employee_Last_Name();
    string get_Employee_First_Name();
    double get_pay_rate();
    double get_hours();
    
    //other functions
    double gross_pay();
    double tax_amount(double tax_rate);
    double total_gross_pay();
    double average();
    double net_pay(double tax_rate);
};
#endif /* defined(____Employee_Pay_Rate_Project__) */
