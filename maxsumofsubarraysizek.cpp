#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int maxsum(vector<int> nums,int k){
    int sum=0;
    int n=nums.size();
    int l=0;
    int r=k-1;
    for(int i=l;i<=r;i++){
        sum=sum+nums[i];
    }
    int maxsum=sum;
    while(r<n-1){
        sum=sum-nums[l];
        l++;
        r++;
        
        sum=sum+nums[r];
       maxsum=max(sum,maxsum);
    }
    return maxsum;
}

int main(){
    int k;
      cin>>k;
      vector<int> nums={-2,5,6,7,2,3,-8};
      
      int ans=maxsum(nums,k);
      cout<<ans;
}
