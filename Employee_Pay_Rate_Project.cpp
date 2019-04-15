//
//  Employee_Pay_Rate_Project.cpp
//  
//
//  Created by Andrew Jackson on 9/2/18.
//
//

#include "Employee_Pay_Rate_Project.h"

Employee::Employee(string Temp_Employee_Last_Name, string Temp_Employee_First_Name, double Temp_pay_rate, double Temp_hours)
{
    this -> Employee_Last_Name = Temp_Employee_Last_Name;
    this -> Employee_First_Name = Temp_Employee_First_Name;
    this -> pay_rate = Temp_pay_rate;
    this -> hours = Temp_hours;
}

// get functions

string Employee::get_Employee_Last_Name()
{
    return this -> Employee_Last_Name;
}

string Employee::get_Employee_First_Name()
{
    return this -> Employee_First_Name;
}

double Employee::get_pay_rate()
{
    return this -> pay_rate;
}

double Employee::get_hours()
{
    return this -> hours;
}

// set functions

void Employee::set_Employee_Last_Name(string Temp_Employee_Last_Name)
{
    this -> Employee_Last_Name = Temp_Employee_Last_Name;
}

void Employee::set_Employee_First_Name(string Temp_Employee_First_Name)
{
    this -> Employee_First_Name = Temp_Employee_First_Name;
}

void Employee::set_pay_rate(double pay_rate)
{
    this -> pay_rate = pay_rate;
}

void Employee::set_hours(double hours)
{
    this -> hours = hours;
}

// other functions

double Employee::gross_pay()
{
    if ((this -> hours) > 40.0)
    {
        double calculated_regular_pay = 40 * (this -> pay_rate);
        double overtime_hours = (this -> hours) - 40.0;
        double calculated_overtime_pay = overtime_hours * 1.5 * (this -> pay_rate);
        double pay_total = calculated_regular_pay + calculated_overtime_pay;
        return pay_total;
    }
    
    else
    {
        double calculated_regular_pay = (this -> hours) * (this -> pay_rate);
        return calculated_regular_pay;
    }
}

double Employee::tax_amount(double tax_rate)
{
     if ((this -> hours) > 40.0)
    {
        double calculated_regular_pay = 40 * (this -> pay_rate);
        double overtime_hours = (this -> hours) - 40.0;
        double calculated_overtime_pay = overtime_hours * 1.5 * (this -> pay_rate);
        double pay_total = calculated_regular_pay + calculated_overtime_pay;
        return pay_total * tax_rate;
    }
    
    else
    {
        double calculated_regular_pay = (this -> hours) * (this -> pay_rate);
        return calculated_regular_pay * tax_rate;
    }
}

double Employee::net_pay(double tax_rate)
{
    double pay_total;
    double taxed_amount;
    
    if ((this -> hours) > 40.0)
    {
        double calculated_regular_pay = 40 * (this -> pay_rate);
        double overtime_hours = (this -> hours) - 40.0;
        double calculated_overtime_pay = overtime_hours * 1.5 * (this -> pay_rate);
        pay_total = calculated_regular_pay + calculated_overtime_pay;
        taxed_amount = pay_total * tax_rate;
    }
    
    else
    {
        double calculated_regular_pay = (this -> hours) * (this -> pay_rate);
        pay_total = calculated_regular_pay;
        taxed_amount = pay_total * tax_rate;
    }
    
    return (pay_total - taxed_amount);
}

/*double Employee::total_gross_pay(Employee Employees*[], int employee_count)
{
    double temp_total = 0.0;
    
    for (int i = 0; i < employee_count; i++)
    {
        double temp_total = temp_total + Employee::gross_pay(**Employees[i]);
    }
    
    return temp_total;
}

double Employee::average(Employee Employees*[], int employee_count)
{
    double temp_total = 0.0;
    
    for (int i = 0; i < employee_count; i++)
    {
        double temp_total = temp_total + Employee::gross_pay(**Employees[i]);
    }

    return temp_total/employee_count;
}*/
    
    
    
    
    
    
    
