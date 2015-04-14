//My DP solution
class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if(n==0) return 0;
        if(n==1) return num[0];
        if(n==2) return num[0]>num[1]? num[0]:num[1];
        int local[n],global[n];
        local[0] = global[0]=num[0];
        local[1] = num[1];global[1]=max(global[0],local[1]);
        local[2] = local[0]+num[2];global[2]=max(global[1],local[2]);
        for(int i =3;i<n;i++){
            local[i] = max(local[i-2],local[i-3])+num[i];
            global[i]=max(global[i-1],local[i]);
            
        }
        return global[n-1];
    }
};

//A simpler DP
class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if(!n) return 0;
        int f=num[n-1],g=0,preg,pref;
        for(int i =n-2;i>=0;i--){
            preg = g;
            pref = f;
            f = preg+num[i];
            g = max(preg,pref);
        }
        return max(f,g);
    }
};
