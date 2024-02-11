#include <iostream>
#include <cmath>

class CalculatorBase {
protected:
    float val;

public:
    CalculatorBase(float initialValue) : val(initialValue) {}

    float getValue() const {
        return val;
    }
};

class Calculator : public CalculatorBase {
public:
    Calculator(float initialValue) : CalculatorBase(initialValue) {}

    float add(float num) {
        val += num;
        return val;
    }

    float subtract(float num) {
        val -= num;
        return val;
    }

    float multiply(float num) {
        val *= num;
        return val;
    }

    int divide(int num) {
        if (num != 0) {
            val /= num;
            return static_cast<int>(val);
        }
        else {
            std::cout << "Error: Cannot divide by zero!!" << std::endl;
            return static_cast<int>(val);
        }
    }

    void power(int exponent) {
        val = std::pow(val, exponent);
    }

    float squareRoot() {
        if (val >= 0) {
            val = std::sqrt(val);
            return val;
        }
        else {
            std::cout << "Error: Cannot calculate square root of a negative number!!" << std::endl;
            return val;
        }
    }

    float negate() {
        val = -val;
        return val;
    }

    void checkEvenOdd() {
        if (static_cast<int>(val) % 2 == 0) {
            std::cout << "The current value is even." << std::endl;
        }
        else {
            std::cout << "The current value is odd." << std::endl;
        }
    }
};

int main() {
    // Create an instance of the Calculator class with an initial value of 5.0
    Calculator myCal(5.0);

    // Perform various operations and display the results
    myCal.add(5.0);
    std::cout << "After adding 5, Value: " << myCal.getValue() << std::endl;

    myCal.subtract(3.0);
    std::cout << "After subtracting 3, Value: " << myCal.getValue() << std::endl;

    myCal.multiply(2.0);
    std::cout << "After multiplying by 2, Value: " << myCal.getValue() << std::endl;

    myCal.divide(4);
    std::cout << "After dividing by 4 (integer division), Value: " << myCal.getValue() << std::endl;

    myCal.power(2);
    std::cout << "After raising to the power of 2, Value: " << myCal.getValue() << std::endl;

    myCal.squareRoot();
    std::cout << "After calculating square root, Value: " << myCal.getValue() << std::endl;

    myCal.negate();
    std::cout << "After negating, Value: " << myCal.getValue() << std::endl;

    // New function to check if the current value is even or odd
    myCal.checkEvenOdd();

    return 0;
}
