/*
1833. Maximum Ice Cream Bars
https://leetcode.com/problems/maximum-ice-cream-bars/
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            sum += costs[i];
            if(coins >= sum) count++;  
            else break;
        }  
        return count;
    }
};