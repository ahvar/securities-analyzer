
#ifndef PORTFOLIO_H_
#define PORTFOLIO_H_

#include "security.h"
#include <vector>

/**
  Portfolio is a select group of securities held by an individual trader or investment firm. The securities are stored in
  a vector and provide functionality for adding, removing, and sorting the list of securities. 
*/
class Portfolio {

public:
  
  /** 
    Constructs a portfolio from the list of pointers to stocks passed as the parameter.
    
    @param list a list of pointers to Stocks.
  */
  Portfolio( std::vector<Stock *> list) : stocks(list){}

  /** Default constructor */
  Portfolio(){}

  /**
    Portfolio destructor
  */
  ~Portfolio();

  /** 
    Adds the Security s to this portfolio.
    @param s the security to the vector of stocks
  */
  void addStock( Stock *s ) { stocks.push_back(s); }

  /** 
    Overloads the right shift operator to output the Portfolio name, each stock in the portfolio, and the total amount invested, to the console. 
    @param out reference to ostream
    @param ptfo reference to Portfolio to be output
    @return out reference to ostream
  */
  friend std::ostream &operator<<( std::ostream &out, Portfolio &ptfo );

private:
  /** The total value in the portfolio */
  double total;
  /** A list of stocks */
  std::vector<Stock *> stocks;
  /** Description of the amount of risk in this portfolio as either, "conservative", "moderate", "aggressive". */
  std::string risk;

};

#endif