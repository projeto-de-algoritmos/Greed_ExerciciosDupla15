/*
2405. Optimal Partition of String
https://leetcode.com/problems/optimal-partition-of-string/
*/

class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        unordered_set<char> st;
        int n = s.length();
        for(int i = 0; i < s.length(); i++){
            if(st.count(s[i])){
                count++;
                st.clear();
                st.insert(s[i]);
            }
            else st.insert(s[i]);
        }
    return count; 
    }
};

//  abacaba = ab ac ab a