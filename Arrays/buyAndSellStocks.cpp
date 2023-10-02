//
// https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_6194560

#include <iostream>
#include <vector>

using namespace std;

// Brute force
// Find the profits one can make by buying and selling on each of the days
// Find the maximum profit
// T.C = O(N*N)
// S.C = O(!)

// Optimal Solution
// If we decide to sell the stock on ith day, then to have the maximum profit for that case
// we need to buy the stock at the minimum price between 1 to i-1th day
// Keep updating the mininum and find the profit between the buy and sell
int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int maxProfit = 0;

    int minPrice = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);

        // keep updating the minimum to the least value encountered
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int main()
{
    vector<int> v = {7, 1, 5, 4, 3, 6};
    cout << bestTimeToBuyAndSellStock(v) << endl;

    v.clear();
    v = {7, 7, 9, 8, 6, 7, 6, 10, 5};
    cout << bestTimeToBuyAndSellStock(v) << endl;

    return 0;
}