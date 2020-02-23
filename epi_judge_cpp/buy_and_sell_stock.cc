#include <vector>
#include <cfloat>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
    double maxProfit = 0;
    double minVal = DBL_MAX;
    
    for(int i = 0; i < prices.size(); i++) {
        if(prices[i] < minVal) {
            minVal = prices[i];
            continue;
        }
        
        maxProfit = fmax(maxProfit, prices[i] - minVal);
    }
    
    return maxProfit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
