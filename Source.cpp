
#include <iostream>
#include <cmath>

class OperationBase {
protected:
    float val;

public:
    OperationBase(float initialValue) : val(initialValue) {}

    float getValue() const {
        return val;
    }
};

class UnaryOperation : public OperationBase {
public:
    UnaryOperation(float initialValue) : OperationBase(initialValue) {}

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

class BinaryOperation : public OperationBase {
public:
    BinaryOperation(float initialValue) : OperationBase(initialValue) {}

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
};

int main() {
    UnaryOperation myUnaryOperation(5.0);
    BinaryOperation myBinaryOperation(5.0);

    // Perform various operations and display the results
    myBinaryOperation.add(5.0);
    std::cout << "After adding 5, Value: " << myBinaryOperation.getValue() << std::endl;

    myBinaryOperation.subtract(3.0);
    std::cout << "After subtracting 3, Value: " << myBinaryOperation.getValue() << std::endl;

    myBinaryOperation.multiply(2.0);
    std::cout << "After multiplying by 2, Value: " << myBinaryOperation.getValue() << std::endl;

    myBinaryOperation.divide(4);
    std::cout << "After dividing by 4 (integer division), Value: " << myBinaryOperation.getValue() << std::endl;

    myBinaryOperation.power(2);
    std::cout << "After raising to the power of 2, Value: " << myBinaryOperation.getValue() << std::endl;

    myBinaryOperation.squareRoot();
    std::cout << "After calculating square root, Value: " << myBinaryOperation.getValue() << std::endl;

    myUnaryOperation.negate();
    std::cout << "After negating, Value: " << myUnaryOperation.getValue() << std::endl;

    // New function to check if the current value is even or odd
    myUnaryOperation.checkEvenOdd();

    return 0;
}
