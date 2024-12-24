\name{FinancialFunctions-package}
\alias{FinancialFunctions-package}
\alias{FinancialFunctions}
\docType{package}
\title{
  Simple bond valuation functions in C++ used to demonstrate R <-> C++ via Rcpp
}
\description{
  This package exposes simple bond valuation functions. 
  The purpose of the package is to demonstrate the use of Rcpp for hooking up 
  R and C++ code.
}
\details{
  The package exposes two functions: bond_price and bond_ytm.
  The bond_price function calculates the price today (present value) of a stream 
  of periodic cashflows using a single rate to discount these.
  The bond_ytm (yield-to-maturity) function determines the yield of the bond's 
  cashflows.
}
\author{
Adam Gladstone, adam_gladstone@hotmail.com.

Maintainer: Adam Gladstone <adam_gladstone@hotmail.com>
}
\references{
  Financial functions: https://ba-odegaard.no/gcc_prog/index.html.
  Rcpp: https://cran.r-project.org/web/packages/Rcpp/index.html
}
\keyword{ package }
\seealso{
  https://cran.r-project.org/web/packages/Rcpp/index.html
}
\examples{
  \dontrun{
    ## Example: a 3 year bond with a face value of $100 makes annual coupon 
    ## payments of 10%. The current interest rate (with annual compounding) is 9%.
    times <- c(1, 2, 3)
    cashflows <- c(10, 10, 110)
    rate <- 0.09

    ## Calculate price and yield to maturity
    price <- FinancialFunctions::bond_price(times, cashflows, rate)
    ytm <- FinancialFunctions::bond_ytm(times, cashflows, price)
        
  }
}
