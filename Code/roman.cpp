/*
 * roman.cpp
 *
 *  Created on: 2015Äê1ÔÂ31ÈÕ
 *      Author: Claire
 */
class Solution {
public:
    int romanToInt(string s) {
       reverse(s.begin(),s.end());
       unordered_map<char,int> nums = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
       int total=nums[s[0]];
       for(size_t i=1;i<s.length();i++){
           if(nums[s[i]]>=nums[s[i-1]]) total+=nums[s[i]];
           else total -= nums[s[i]];
       }
       return total;
    }
};



