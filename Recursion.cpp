#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>

int Factorial (int num);

int main(){
    int n;
    std::cout << "Insert integer to calculate it's factorial: ";
    std::cin >> n;
    std::cout << "The factorial of " << n << " is " << Factorial(n);
    return 0;
}

int Factorial(int num){
    if (num == 1) return 1;
    else return (num * Factorial(num - 1));
}