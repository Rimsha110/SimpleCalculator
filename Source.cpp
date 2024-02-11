#include <iostream>
#include <cmath> //SQRT function
using namespace std;

class Calculator
{
private:
    float val;

public:
    // Constructor to initialize the Calculator with an initial value
    Calculator(float initialValue) : val(initialValue)
    {
    }

    // Function to perform addition
    float add(float num)
    {
        val += num;
        return val;
    }

    // Function to perform subtraction
    float subtract(float num)
    {
        val -= num;
        return val;
    }

    // Function to perform multiplication
    float multiply(float num)
    {
        val *= num;
        return val;
    }

    // Function to perform integer division
    int divide(int num)
    {
        if (num != 0)
        {
            val /= num;
            return static_cast<int>(val);
        }
        else
        {
            cout << "Error: Cannot divide by zero!!" << endl;
            return static_cast<int>(val);
        }
    }

    // Function to calculate the power of the current value to a given exponent
    void power(int exponent)
    {
        val = pow(val, exponent);
    }

    // Function to calculate the square root of the current value
    float squareRoot()
    {
        if (val >= 0)
        {
            val = sqrt(val);
            return val;
        }
        else
        {
            cout << "Error: Cannot calculate square root of a negative number!!" << endl;
            return val;
        }
    }

    // Function to negate the current value
    float negate()
    {
        val = -val;
        return val;
    }

    // Function to check if the current value is even or odd
    void checkEvenOdd()
    {
        if (static_cast<int>(val) % 2 == 0)
        {
            cout << "The current value is even." << endl;
        }
        else
        {
            cout << "The current value is odd." << endl;
        }
    }

    // Function to get the current value
    float getValue() const
    {
        return val;
    }
};

int main()
{
    // Create an instance of the Calculator class with an initial value of 5.0
    Calculator myCal(5.0);

    // Perform various operations and display the results
    myCal.add(5.0);
    cout << "After adding 5, Value: " << myCal.getValue() << endl;

    myCal.subtract(3.0);
    cout << "After subtracting 3, Value: " << myCal.getValue() << endl;

    myCal.multiply(2.0);
    cout << "After multiplying by 2, Value: " << myCal.getValue() << endl;

    myCal.divide(4);
    cout << "After dividing by 4 (integer division), Value: " << myCal.getValue() << endl;

    myCal.power(2);
    cout << "After raising to the power of 2, Value: " << myCal.getValue() << endl;

    myCal.squareRoot();
    cout << "After calculating square root, Value: " << myCal.getValue() << endl;

    myCal.negate();
    cout << "After negating, Value: " << myCal.getValue() << endl;

    // New function to check if the current value is even or odd
    myCal.checkEvenOdd();

    return 0;
}
