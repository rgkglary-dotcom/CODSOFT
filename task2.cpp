2#include <iostream>
#include <string>
using namespace std;
int main() 
{
    double num1, num2, result;
    string op;
    cout << "Enter your first number: ";
    cin >> num1;
    cout << "Enter your second number: ";
    cin >> num2;
    cout << "Enter the operation(addition, subtraction, multiplication, division) to perform: ";
    cin >> op;
    if (op == "addition") 
    {
        result = num1 + num2;
        cout << "Result: " << result << endl;
    }
    else if (op == "subtraction") 
    {
        result = num1 - num2;
        cout << "Result: " << result << endl;
    }
    else if (op == "multiplication") 
    {
        result = num1 * num2;
        cout << "Result: " << result << endl;
    }
    else if (op == "division") 
    {
        if (num2 != 0) 
        {
            result = num1 / num2;
            cout << "Result: " << result << endl;
        } 
        else 
        {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    }
    else 
    {
        cout << "Invalid operation. Please type addition, subtraction, multiplication, or division." << endl;
    }
    return 0;
}