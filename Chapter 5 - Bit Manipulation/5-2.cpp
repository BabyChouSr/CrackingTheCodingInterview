//Binary to String

#include <iostream>

using namespace std;

string binaryToString(double x) { // i.e. 0.72
    if (x <= 0 || x >= 1) {return "ERROR";}
    string result = ".";
    
    // To print the decimal part, we can multiply by 2 and check if 2n is greater than or equal to 1 because
    // The binary representation goes from something like 0.1011_b (0.6875_[10]) = 1 * 1/2^1 + 1/2^3 + 1/2^4
    //                                                                           = 1 * 1/2^0 + 1/2^2 + 1/2^3
    // which effectively shifts the number one place so if the resultant is > 1 then we add one to the result string, else 0

    while (x > 0) {
        if (result.length() >= 32) {
            return "ERROR"; // can only have 32 characters, including the decimal
        }

        double r = x * 2;
        if (r >= 1) {
            result += '1';
            x = r - 1;
        } else {
            result += '0';
            x = r;
        }
    }
    return result;
}

int main() {
    double value = 0;
    double frac = 1.0 / 2 + 1.0 / 8 + 1.0/ 16;
    cout << binaryToString(frac);
    return 0;
}