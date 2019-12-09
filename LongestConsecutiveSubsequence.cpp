#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    
    unordered_map<int, bool> m;
    for(int i=0; i<n; i++){
        m[arr[i]]=true;
    }
    int i=0, max =1 , start = arr[0];
    
    while(i<n){
        int len = 1, start_ = arr[i];
        if(m.count(start_)==1){
            int t=start_ + 1;
            while(m.count(t)==1){
                len++;
                t++;
            }
            
        }
        if(len>max ){
            max=len;
            start=arr[i];
        }
        i++;
    }
    vector<int> v;
    while(max--){
        v.push_back(start);
        start++;
    }
    return v;
}