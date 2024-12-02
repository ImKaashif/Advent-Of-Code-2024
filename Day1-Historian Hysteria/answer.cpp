// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int distance(vector<int> l1, vector<int> l2, int n) {
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    
    int ans=0;
    
    for(int i=0; i<n; i++) {
        ans += abs(l1[i]-l2[i]);
    }

    return ans;
}

int similarity_score(vector<int> l1, vector<int> l2, int n) {
  unordered_map<int, int> counter;
  
  int ans = 0;
  
  for(int i=0; i<n; i++) {
    counter[l2[i]]++;
  }
  
  for(int i=0; i<n; i++) {
    ans += l1[i]*counter[l1[i]];
  }
  
  return ans;
}

int main() {
    // Write C++ code here
    int n;
    vector<int> l1, l2; 
    cin>>n;
    for(int i=0; i<n; i++) {
        int j;
        cin>>j;
        l1.push_back(j);
    }
    for(int i=0; i<n; i++) {
        int j;
        cin>>j;
        l2.push_back(j);
    }
    
    cout<<distance(l1, l2, n)<<\n;
    cout<<similarity_score(l1, l2, n);

    return 0;
}