// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<int> &arr){
//     int n=arr.size();
//     int i=1,j=0;
//     for(;i<n;i++){ 
//         if(abs(arr[i]-arr[j])<=1){
//             j++;
//         }
//         else if(abs(arr[i]-arr[j])>1 && abs(arr[i-1]-arr[j])<=1){
//             swap(arr[i-1],arr[i]);
//             j++;
//         }else{

//         }
//     }
        
// }


// int main(){
//     int t;
//     cin>>t;

//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> arr(n);
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }

//         solve(arr);

//         bool flag=false;
//         for(int i=0;i<n;i++){
//             if(abs(arr[i]-arr[i+1])<=1){
//                 flag=true; 
//             }else{
//                 flag=false;
//             }          
//         }
//         if(!flag){
//             cout<<"Yes, it is Ethereal Wrap"<<endl;
//         }else {
//             cout<<"No, it is a normal invisibility cloak"<<endl;
//         }

        
//     }
// }

#include <bits/stdc++.h>
using namespace std;

bool flag(vector<int>& v) {
    sort(v.begin(),v.end());

    for (int i=0; i<v.size();i++) {
        if (i>0 && v[i]-v[i-1]>1) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin>>t;

    while(t--){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(flag(arr)){
        cout<<"Yes, it is Ethereal Wrap"<<endl;
    }else{
        cout<<"No, it is a normal invisibility cloak"<<endl;
    }
    }
    return 0;
}

