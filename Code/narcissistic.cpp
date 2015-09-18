#include<limits.h>
#include<iterator>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<unordered_map>

using namespace std;

int m,n;

int main(){
	freopen("input","rw",stdin);
	while(!cin.eof()){
		cin>>m>>n;
		bool flag = true;
		int start = m,sum = 0;
		vector<int> bits;
		while(start){
			bits.push_back(start%10);
			sum+=bits.back()*bits.back()*bits.back();
			start/=10;
		}
		for(int i=m;i<=n;i++){

			if(sum == i) {
				if(!flag) cout<<" "<<i;
				else {
					cout<<i;
					flag = false;}
				}
			bits[0]++;
			if(bits[0]!=10) {
				sum-=(bits[0]-1)*(bits[0]-1)*(bits[0]-1);
				sum+=bits[0]*bits[0]*bits[0];
			}else{
				for(int j=0;j<bits.size();j++){
					if(bits[j]==10){
						sum-=9*9*9;
						bits[j]=0;
						if(j<bits.size()-1)	{
							sum-=bits[j+1]*bits[j+1]*bits[j+1];
							bits[j+1]++;
							sum+=bits[j+1]*bits[j+1]*bits[j+1];
						}
						else {
							bits.push_back(1);
							sum+=1;
						}
					}else break;
				}
			}

		}
		if(flag) cout<<"no"<<endl;
		else cout<<endl;
	}
}
