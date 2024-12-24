#include <iostream>
#include <vector>
#include <string>

#include "..\src\FinancialFunctions.h"

// References
// https://code.visualstudio.com/docs/languages/cpp
// https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites

int main()
{
    // Test
    // A 3 year bond with a face value of $100 makes annual coupon payments of 10%. 
    // The current interest rate (with annual compounding) is 9%.
    std::vector<double> times { 1, 2, 3 }; 
    std::vector<double> cashflows { 10, 10, 110 };
    double rate = 0.09;

    double price = FinancialFunctions::Bonds::price(times, cashflows, rate);
    double ytm = FinancialFunctions::Bonds::ytm(times, cashflows, price);

    std::cout << "Bond price, 9 percent discretely compounded interest = " << price << '\n';
    std::cout << "Bond yield to maturity = " << ytm << '\n';

    return 0;
}
