


#include "Employee_Pay_Rate_Project.h"

int main(int argc, char** argv)
{
    int employee_count;
    double tax_rate = 0.15;
    double temp_total;
    int width_name = 22; // Added 9/22/2018
    int width_pay_rate = 5; // Added 9/22/2018
    int width_hours = 9; // Added 9/22/2018
    int width_gross_pay = 9; // Added 9/22/2018
    int width_tax_amount = 11; // Added on 9/22/2018
    int width_net_pay = 8; // Added on 9/22/2018
    
    cout << "Please enter the number of employees for the data table." << endl;
    cout << endl;
    cout << "number of employees: ";
    cin >> employee_count;
    cout << endl;
    
    while(std::cin.fail())
    {
        cout << "This is not an integer, please try again." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> employee_count;
    }
    cout << "The number of employees you entered is " << employee_count << "." << endl;
    cout << endl;
    
    string* Employee_Attributes = new string[4 * employee_count];
    
    for (int i = 1; i <= employee_count; i++)
    {
        cout << "Please enter the last name of employee " << i << ":" << endl;
        cout << endl;
        
        cin >> Employee_Attributes[(i - 1) * 4];
        cout << endl;
        
        cout << "Please enter the first name of employee " << i << ":" << endl;
        cout << endl;
        
        cin >> Employee_Attributes[((i - 1) * 4) + 1];
        cout << endl;
        
        cout << "Please enter the pay rate of employee " << i << ":" << endl;
        cout << endl;
        
        cin >> Employee_Attributes[((i - 1) * 4) + 2];
        cout << endl;
        
        cout << "Please enter the hours worked by employee " << i << ":" << endl;
        cout << endl;
        
        cin >> Employee_Attributes[((i - 1) * 4) + 3];
        cout << endl;
    }
    
    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "The attributes you entered for your employee(s) are: " << endl;
    cout << endl;
    
    for (int i = 1; i <= employee_count; i++)
    {
        cout << "Employee " << i << ":" << endl;
        cout << endl;
        
        cout << "Last Name: " << Employee_Attributes[(i - 1) * 4] << endl;
        cout << "First Name: " << Employee_Attributes[((i - 1) * 4) + 1] << endl;
        cout << "pay rate: " << Employee_Attributes[((i - 1) * 4) + 2] << endl;
        cout << "hours worked: " << Employee_Attributes[((i - 1) * 4) + 3] << endl;
        cout << endl;
    }
    
    Employee** Employees = new Employee*[employee_count];
    double* Numerical_Employee_Attributes = new double[2 * employee_count];
    
    double numerical_conversion_holder_1;
    double numerical_conversion_holder_2;
    
    for (int i = 1; i <= employee_count; i++)
    {
        stringstream convert(Employee_Attributes[((i - 1) * 4) + 2]);
        convert >> numerical_conversion_holder_1;
        Numerical_Employee_Attributes[2 * (i - 1)] = numerical_conversion_holder_1;
        
        
        //stringstream convert(Employee_Attributes[((i - 1) * 4) + 3]);
        //convert >> numerical_conversion_holder_2;
        //Numerical_Employee_Attributes[(2 * (i - 1)) + 1] = numerical_conversion_holder_2;
    }
    
    for (int i = 1; i <= employee_count; i++)
    {
        //stringstream convert(Employee_Attributes[((i - 1) * 4) + 2]);
        //convert >> numerical_conversion_holder_1;
        //Numerical_Employee_Attributes[2 * (i - 1)] = numerical_conversion_holder_1;
        
        
        stringstream convert(Employee_Attributes[((i - 1) * 4) + 3]);
        convert >> numerical_conversion_holder_2;
        Numerical_Employee_Attributes[(2 * (i - 1)) + 1] = numerical_conversion_holder_2;
    }
    
    for (int i = 1; i <= employee_count; i++)
    {
        Employees[i - 1] = new Employee(Employee_Attributes[(i - 1) * 4], Employee_Attributes[((i - 1) * 4) + 1], Numerical_Employee_Attributes[2 * (i - 1)], Numerical_Employee_Attributes[(2 * (i - 1)) + 1]);
    }
    
    // Putting first and last name into a single array. // Added on 9/22/2018
    
    string* Last_First_Name = new string[employee_count];
    
    for (int i = 1; i <= employee_count; i++)
    {
        Last_First_Name[i - 1] = Employees[i - 1] -> get_Employee_Last_Name() + ", " +  Employees[i - 1] -> get_Employee_First_Name();
    }
    
    // Totals and Averages
    
    double* Totals = new double[5]; //pay_rate, hours, gross_pay, tax_amount, net_pay
    double* Averages = new double[5];
    
    for (int i = 1; i <= 5; i++)
    {
        Totals[i - 1] = 0;
        Averages[i - 1] = 0;
        
        if (i == 1)
        {
            for (int j = 1; j <= employee_count; j++)
            {
                Totals[i - 1] = Totals[i - 1] + (Employees[j - 1] -> get_pay_rate());
            }
            
            Averages[i - 1] = Totals[i - 1]/5.0;
        }
        
        if (i == 2)
        {
            for (int j = 1; j <= employee_count; j++)
            {
                Totals[i - 1] = Totals[i - 1] + (Employees[j - 1] -> get_hours());
            }
            
            Averages[i - 1] = Totals[i - 1]/5.0;
        }
        
        if (i == 3)
        {
            for (int j = 1; j <= employee_count; j++)
            {
                Totals[i - 1] = Totals[i - 1] + (Employees[j - 1] -> gross_pay());
            }
            
            Averages[i - 1] = Totals[i - 1]/5.0;
        }
        
        if (i == 4)
        {
            for (int j = 1; j <= employee_count; j++)
            {
                Totals[i - 1] = Totals[i - 1] + (Employees[j - 1] -> tax_amount(tax_rate));
            }
            
            Averages[i - 1] = Totals[i - 1]/5.0;
        }
        
        if (i == 5)
        {
            for (int j = 1; j <= employee_count; j++)
            {
                Totals[i - 1] = Totals[i - 1] + (Employees[j - 1] -> net_pay(tax_rate));
            }
            
            Averages[i - 1] = Totals[i - 1]/5.0;
        }
    }
    
    cout << "Employee              Pay     Hours     Gross     Tax      Net" << endl;
    cout << "Name                  Rate    Worked    Pay       Amount   Pay" << endl;
    cout << "========              ====    ======    =====     ======  ======" << endl;
    cout << endl;
    
    for (int i = 1; i <= employee_count; i++)
    {
    /*cout << left << setw(width_name) << Employees[i - 1] -> get_Employee_Last_Name();
    
    cout << ", ";
    
    cout << Employees[i - 1] -> get_Employee_First_Name();*/
    
    cout << left << setw(width_name) << Last_First_Name[i - 1];
    
    cout << fixed << showpoint;
    
    cout << right << setw(width_pay_rate) << setprecision(2) << Employees[i - 1] -> get_pay_rate();
    
    cout << right << setw(width_hours) << setprecision(2) << Employees[i - 1] -> get_hours();
    
    cout << right << setw(width_gross_pay) << setprecision(2) << Employees[i - 1] -> gross_pay();
     
    cout << right << setw(width_tax_amount) << setprecision(2) << Employees[i - 1] -> tax_amount(tax_rate);
     
    cout << right << setw(width_net_pay) << setprecision(2) << Employees[i - 1] -> net_pay(tax_rate);
      
    cout << endl;
    }
    cout << endl;
}
    
    
    
    