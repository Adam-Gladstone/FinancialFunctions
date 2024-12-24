#include <Rcpp.h>

#include <vector>

#include "FinancialFunctions.h"

//' Calculate the bond price with discrete annual compounding
//'
//' @param times A vector of cashflow periods.
//' @param cashflows A vector of cashflow amounts.
//' @param rate The single rate at which to discount all cashflows.
//' @export

// [[Rcpp::export]]
double bond_price(Rcpp::NumericVector times, Rcpp::NumericVector cashflows, double rate)
{
  std::vector<double> _times = Rcpp::as<std::vector<double>>(times);
  std::vector<double> _cashflows = Rcpp::as<std::vector<double>>(cashflows);
  
  double price = FinancialFunctions::Bonds::price(_times, _cashflows, rate);
 
  return price;
}

// Calculate bond yield to maturity (ytm) with discrete, annual compounding
//'
//' @param times A vector of cashflow periods.
//' @param cashflows A vector of cashflow amounts.
//' @param price The bond price for which we want to calculate the yield.
//' @export

// [[Rcpp::export]]
double bond_ytm(Rcpp::NumericVector times, Rcpp::NumericVector cashflows, double price)
{
 std::vector<double> _times = Rcpp::as<std::vector<double>>(times);
 std::vector<double> _cashflows = Rcpp::as<std::vector<double>>(cashflows);
 
 double ytm = FinancialFunctions::Bonds::ytm(_times, _cashflows, price);
 
 return ytm;
}
