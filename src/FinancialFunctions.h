///////////////////////////////////////////////////////////////////////////////
//
// Financial Functions
// Based on: "Financial Numerical Recipes in C++", Bernt Arne Ødegaard (2014)
//
//

#include <vector>

namespace FinancialFunctions
{
  namespace Bonds 
  {
    // Calculate the bond price with discrete annual compounding
    double price(const std::vector<double>& times, 
                 const std::vector<double>& amounts, 
                 const double rate);

    // Calculate bond yield to maturity (ytm) with discrete, annual compounding
    double ytm(const std::vector<double>& times,
               const std::vector<double>& cashflows,
               const double bondprice);
  }
}
