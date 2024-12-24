///////////////////////////////////////////////////////////////////////////////
//
// Financial Functions
// Based on: "Financial Numerical Recipes in C++", Bernt Arne Ødegaard (2014)
//

#include <cmath>
#include <stdexcept>

#include "FinancialFunctions.h"

namespace {

  void check_vector_sizes(const std::vector<double>& times, 
                          const std::vector<double>& cashflows)
  {
    if(times.size() <= 0)
      throw std::invalid_argument("The times vector is empty.");
    
    if(cashflows.size() <= 0)
      throw std::invalid_argument("The cashflows vector is empty.");
    
    if(times.size() != cashflows.size())
      throw std::invalid_argument("The times and the cashflows vectors are different sizes.");
  }
}

namespace FinancialFunctions
{
  namespace Bonds 
  {
    // Calculate the bond price with discrete annual compounding    
    double price(const std::vector<double>& times, 
                 const std::vector<double>& cashflows, 
                 const double rate)
    {
      check_vector_sizes(times, cashflows);
      
      double price = 0;

      for (std::size_t i = 0; i < times.size(); ++i) 
      {
        price += cashflows[i] / (std::pow(1 + rate, times[i]));
      }

      return price;
    }

    // Calculate bond yield to maturity (ytm) with discrete, annual compounding
    double ytm(const std::vector<double>& times,
               const std::vector<double>& cashflows,
               const double bondprice) 
    {
      check_vector_sizes(times, cashflows);
      
      constexpr double ACCURACY = 1e-5;
      constexpr unsigned int MAX_ITERATIONS = 200;
      double bot = 0.0;
      double top = 1.0;
      
      while (price(times, cashflows, top) > bondprice) 
      {
        top = top * 2; 
      }

      double rate = 0.5 * (top + bot);

      for(std::size_t i = 0; i < MAX_ITERATIONS; ++i)
      {
        double diff = price(times, cashflows, rate) - bondprice;
        
        if(std::fabs(diff) < ACCURACY) 
          return rate;

        if (diff > 0.0) 
        { 
          bot = rate;
        }
        else
        { 
          top = rate; 
        }
      
        rate = 0.5 * (top + bot);
      }
    
      return rate;
    }
  }
}
