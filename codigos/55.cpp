/*
55. Jump Game
https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return true;    // se n = 1, ja está no final 

        int reach = 0;     //  posição maxima de nums que pode ser alcançada 

        for(int i = 0; i < n; i++){
            
            reach = max(reach,i+nums[i]);  // o novo alcance maximo é max(alcanço anterior, alcance da posição atual + alcance dado(valor) da posição) 

            if(reach == i) return false;  // ficou preso

            if(reach >= n-1) return true;  // consegue alcançar final, opcional
        }

        return true;
    }
};
