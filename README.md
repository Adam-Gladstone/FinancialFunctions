<a name="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Adam-Gladstone/FinancialFunctions">
    <img src="FinancialFunctions/Assets/icons8-bonds-80.png" alt="logo" width="80" height="80">
  </a>

  <h3 align="center">FinancialFunctions</h3>

  <p align="center">
    <br />
    <a href="https://github.com/Adam-Gladstone/FinancialFunctions"><strong>Explore the docs >></strong></a>
    <br />
    <br />
    <a href="https://github.com/Adam-Gladstone/FinancialFunctions/issues">Report Bug</a>
    ·
    <a href="https://github.com/Adam-Gladstone/FinancialFunctions/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project
__FinancialFunctions__ is an RStudio project to demonstrate creating an R package using Rcpp (https://cran.r-project.org/web/packages/Rcpp/index.html). The project exposes some native C++ functions to R. If you are interested in writing code in C++ and being able to call it from R, then this project might be of interest to you.

The C++ functions that are exposed to R/RStudio are based on finance, specifically basic fixed income pricing, only because I am somewhat familiar with this area. In reality, any area would do (statistics, machine learning, natural language processing, and so on) because the focus of the project is on **using Rcpp to allow us to call C++ functions**.

There are several other articles that cover using Rcpp:
- https://www.r-bloggers.com/2021/07/using-r-calling-c-code-with-rcpp/
- https://dirk.eddelbuettel.com/papers/rcpp_rfinance_may2012.pdf
- https://dirk.eddelbuettel.com/papers/rcpp_workshop_introduction_user2012.pdf
- http://adv-r.had.co.nz/Rcpp.html

My intention here was to create a simple but realistic package that can be copied, extended and reused.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With
For reference, the project uses the following versions of R/RStudio:
* R version 4.4.1 (2024-06-14 ucrt) -- "Race for Your Life"
* RStudio 2024.04.2+764 "Chocolate Cosmos" Release (e4392fc9ddc21961fd1d0efd47484b43f07a4177, 2024-06-05) for windows
* Rtools, version 4.4

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->

## Getting Started
The project can be downloaded from the GitHub repository in the usual way.

The solution consists of a single project:
__FinancialFunctions.Rproj__

The project structure is generated using the RStudio File > New Project ... menu and selecting the __R Package__ project type.

The following directories and files are created:

__\man\FinancialFunctions-package.Rd__

This is an R markdown template file that is used for describing the package. You can edit this in RStudio. Pressing the Preview button displays the formatted contents in the Help window.

__\R\RcppExports.R__

This file contains the R language function calls generated by Rcpp.

__\src\RcppExports.cpp__

This file contains the C++ functions generated by Rcpp.

__\src\rcpp_functions.cpp__

(This was renamed from *rcpp_hello_world.cpp*). This contains the rcpp functions that connect the R functions to the C++ code.

- __\src\FinancialFunctions.h__
- __\src\FinancialFunctions.cpp__

These contain the C++ source code that we want to call from R. 

There are two functions declared in the header file: ``price`` and ``ytm`` (yield-to-maturity).

The price function computes the present value of a stream of periodic cashflows using a single discount rate. The yield-to-maturity function computes the single rate of return implied by the periodic cashflows and the price (present value).

The price function takes a vector of times and a vector of cashflows (for a bond these are the coupons and the final principal repayment). In addition, the function takes a single rate, which is used to discount all the cashflows.

The yield-to-maturity function also takes a vector of times and a vector of cashflows (as above) and a (bond) price. From this, it iteratively determines the single rate at which the periodic stream of cashflows should be discounted to obtain the supplied price.

__DESCRIPTION__

This file contains descriptive information about this package (Package name, Type, Version, Date, Author, and so on). It also contains metadata about the package dependencies.

__NAMESPACE__

This file contains three directives. Firstly, ``useDynLib(...)`` ensures that the dynamic library that is part of this package is loaded and registered. Next, the ``importFrom(...)`` directive imports variables from other packages (other than baseR, which are always imported). In this case, we import variables from the ``Rcpp`` and the ``evalCpp`` packages. The final directive, ``exportPattern(...)``, declares which identifiers should be globally visible from the namespace of this package. The default is to export all identifiers that start with a letter. This is defined in the regular expression.

The __CHANGELOG.md__, __LICENSE.md__ and __README.md__ (this document)are part of the project repository.

There is a separate __test__ directory that contains code to test the functions:
* __FinancialFunctions.R__
This is a simple example/test of the basic functionality.

* __FinancialFunctions.xlsx__
This is a spreadsheet that replicates the bond price and yield-to-maturity calculations.

* __TestFinancialFunctions.cpp__
This is a C++ test which can be built and run (and debugged) from Visual Studio code. This requires some additional setup of VSCode to support C++ development. See https://code.visualstudio.com/docs/languages/cpp for a description of how to do this.

### Prerequisites
Rcpp

### Installation


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage
- Open the ``.Rproj`` file in RStudio.
- Ensure that you have installed Rcpp. If not, run ```install.packages("Rcpp")```
- Select *Build binary package* from the *Build* menu.
- If the build has been successful, you should find a file FinancialFunctions_1.0.zip in the install location.
- Open the zip file and copy the contents of FinancialFunctions into your ..\R\R-4.4.1\library directory.
- Run the example file FinancialFunctions.R

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->

## Roadmap

Future directions:

See the [open issues](https://github.com/Adam-Gladstone/FinancialFunctions/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the GPL-3.0 License. See `LICENSE.md` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->

## Contact

Adam Gladstone - (https://www.linkedin.com/in/adam-gladstone-b6458b156/)

Project Link: [https://github.com/Adam-Gladstone/FinancialFunctions](https://github.com/Adam-Gladstone/FinancialFunctions)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Helpful resources

* [Choose an Open Source License](https://choosealicense.com)
* [GitHub Pages](https://pages.github.com)


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- PROJECT SHIELDS -->

[![Issues][issues-shield]][issues-url]

[![GPL-3 License][license-shield]][license-url]

[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[issues-shield]: https://img.shields.io/github/issues/Adam-Gladstone/FinancialFunctions.svg?style=for-the-badge

[issues-url]: https://github.com/Adam-Gladstone/FinancialFunctions/issues

[license-shield]: https://img.shields.io/github/license/Adam-Gladstone/FinancialFunctions.svg?style=for-the-badge

[license-url]: https://github.com/Adam-Gladstone/FinancialFunctions/LICENSE.md

[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555

[linkedin-url]: https://www.linkedin.com/in/adam-gladstone-b6458b156/

<a name="readme-top"></a>