/*
1561. Maximum Number of Coins You Can Get
https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int n = piles.size();
        int sum = 0;
        for(int i = 1; i < 2*n/3; i += 2)  // até chegar na última moeda que vou pegar
            sum += piles[i];
        return sum;
    }
};