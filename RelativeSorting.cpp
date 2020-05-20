#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
//code
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int arr1[n], arr2[m];
        for(int i=0; i<n; i++)
        cin>>arr1[i];
        for(int i=0; i<m; i++)
        cin>>arr2[i];
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        mp[arr1[i]]++;
        
        vector<int> temp1;
        vector<int> temp2;
        int j=0;
        for(int i=0; i<m; i++){
            if(mp.count(arr2[i]) > 0){
                while(mp[arr2[i]]>0){
                    temp1.push_back(arr2[i]);
                    mp[arr2[i]]--;
                }
                mp.erase(arr2[i]);
            }
        }
        for(auto it : mp){
            for(int i=0; i<it.second; i++)
            temp2.push_back(it.first);
        }
        sort(temp2.begin(), temp2.end());
        
        for(int i=0; i<temp1.size(); i++)
        cout<<temp1[i]<<" ";
        for(int i=0; i<temp2.size(); i++)
        cout<<temp2[i]<<" ";
        
        
        cout<<endl;
    }
	return 0;
}
