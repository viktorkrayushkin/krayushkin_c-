#include <iostream>
#include <iomanip>

using namespace std;

constexpr long int Factorial(int n) {
    return (n <= 1 ? 1 : (n * Factorial(n - 1)));
}

constexpr long double e(int accuracy) {
    return (accuracy == 0 ? 1 : e(accuracy - 1) + ((long double)1.0 / (long double)Factorial(accuracy)));
}

int main() {
    cout.precision(17);
    cout << e(27) << endl;
}