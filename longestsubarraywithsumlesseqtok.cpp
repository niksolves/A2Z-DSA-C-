#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 //  brute
// int maxsubarray(vector<int> &nums,int k){
//     int n=nums.size();
//     int sum=0;
//     int maxlen=0;
//     for(int i=0;i<n;i++){
//         sum=0;
//         for(int j=i;j<n;j++){
//             sum=sum+nums[j];
//             if(sum<=k){
//                 maxlen=max(maxlen,j-i+1);
//             }
//         }
        
//     }
//     return maxlen;
// }
  

//better
//     int maxsubarray(vector<int> &nums,int k){
//     int sum=0;
//     int n=nums.size();
//     int l=0;
//     int r=0;
//     int maxlen=0;
//      while(r<n){
//         sum=sum+nums[r];
//             while(sum>k){
//                 sum=sum-nums[l];
//                 l++;
//                 }
//                  maxlen=max(maxlen,(r-l+1));
//         r++;
//      }
    
//     return maxlen;
//  }

//optimal
    int maxsubarray(vector<int> &nums,int k){
    int sum=0;
    int n=nums.size();
    int l=0;
    int r=0;
    int maxlen=0;
     while(r<n){
        sum=sum+nums[r];
            if(sum>k){
                sum=sum-nums[l];
                l++;
                }
                 maxlen=max(maxlen,(r-l+1));
        r++;
     }
    
    return maxlen;
 }

int main(){
    int k;
      cin>>k;
      vector<int> nums={2,5,6,7,2,3,8};
      
      int ans=maxsubarray(nums,k);
      cout<<ans;
}
