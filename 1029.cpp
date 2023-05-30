/*
1029. Two City Scheduling
https://leetcode.com/problems/two-city-scheduling/
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        vector<pair<int,int>> v;
        int n = costs.size();

        // no first, a diferença aCosti - bCosti e no second a posição que está no vector costs
        for(int i = 0; i < n; i++)
            v.push_back(make_pair(costs[i][0] - costs[i][1], i));
        
        // orderna por aCosti - bCosti
        sort(v.begin(),v.end());

        int sum = 0;

        // soma os custos para a cidade A
        for(int i = 0; i < n/2; i++)
            sum+=costs[v[i].second][0];
        
        // soma os custos para a cidade B
        for(int i = n/2; i < n; i++)
            sum+=costs[v[i].second][1];
        

        return sum;
    }
};
