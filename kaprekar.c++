#include <iostream>

// Function to get the number of digits in a number
int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        ++count;
    }
    return count;
}

// Function to sort the digits of a number in ascending order
int sortDigitsAsc(int number) {
    int numDigits = countDigits(number);
    int* digits = new int[numDigits];

    // Extracting digits
    for (int i = 0; i < numDigits; ++i) {
        digits[i] = number % 10;
        number /= 10;
    }

    // Sorting digits in ascending order    
    for (int i = 0; i < numDigits - 1; ++i) {
        for (int j = 0; j < numDigits - i - 1; ++j) {
            if (digits[j] < digits[j + 1]) {
                // Swap
                int temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }

    // Reconstructing the number
    int result = 0;
    for (int i = numDigits - 1; i >= 0; --i) {
        result = result * 10 + digits[i];
    }

    delete[] digits;
    return result;
}

// Function to sort the digits of a number in descending order
int sortDigitsDesc(int number) {
    int numDigits = countDigits(number);
    int* digits = new int[numDigits];

    // Extracting digits
    for (int i = 0; i < numDigits; ++i) {
        digits[i] = number % 10;
        number /= 10;
    }

    // Sorting digits in descending order
    for (int i = 0; i < numDigits - 1; ++i) {
        for (int j = 0; j < numDigits - i - 1; ++j) {
            if (digits[j] > digits[j + 1]) {
                // Swap
                int temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
            }
        }
    }

    // Reconstructing the number
    int result = 0;
    for (int i = numDigits - 1; i >= 0; --i) {
        result = result * 10 + digits[i];
    }

    delete[] digits;
    return result;
}

int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    int steps = 0;

    while (number != 495) {
        int asc = sortDigitsAsc(number);
        int desc = sortDigitsDesc(number);
        number = desc - asc;
        ++steps;
    }

    std::cout << "Pasos: " << steps << std::endl;

    return 0;
}