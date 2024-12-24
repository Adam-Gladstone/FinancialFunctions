################################################################################
#
# Test Financial Functions
#
################################################################################

library(FinancialFunctions)

# Check that the package loaded, and that the functions are visible
library(pkgload)
functions = names(pkg_env("FinancialFunctions"))
as.data.frame(functions)
getLoadedDLLs()

# Example: a 3 year bond with a face value of $100 makes annual coupon 
# payments of 10%. The current interest rate (with annual compounding) is 9%.
times <- c(1, 2, 3)
cashflows <- c(10, 10, 110)
rate <- 0.09

# Calculate price and yield to maturity
price <- FinancialFunctions::bond_price(times, cashflows, rate)
ytm <- FinancialFunctions::bond_ytm(times, cashflows, price)

# Display the results
price
ytm
