//O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int num = gas.size();
        int total=0,sum=0;
        int j=0;
        for(int i =0;i<num;i++){
              total += gas[i]-cost[i];
              sum += gas[i]-cost[i];
              if(sum<0){
                  sum=0;
                  j=i+1;
              }
        }
            
        return total>=0?j:-1;
    }
};

//O(n2)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        
        int num = gas.size();
        
        for(int i =0;i<num;i++){
            int j= i;
            int tank=gas[j];
            
            while(tank>=cost[j]){
                tank-=cost[j];
                j = (j+1)%num;
                tank+=gas[j];
                if(j==i) return i;
            }
            
        }
        return -1;
    }
};
