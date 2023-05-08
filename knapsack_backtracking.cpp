#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int n, int W, vector<int> weight, vector<int> value, int cur, int cur_value){
    if(n==0 || W==0 || cur==n){
        return cur_value;
    }

    int max_Val = cur_value;

    if(weight[cur]<=W){
        max_Val = max(max_Val, knapsack(n,W-weight[cur],weight,value,cur+1,cur_value+value[cur]));
    }

    max_Val = max(max_Val, knapsack(n,W,weight,value,cur+1,cur_value));

    return max_Val;
    
}

int main(){
    int n,W;
    cout<<"Enter the number of items and the maximum weight: ";
    cin>>n>>W;
    vector<int> weight(n);
    vector<int> value(n);

    for(int i=0;i<n;i++){
        cout<<"Enter the weight and value of item "<<i+1<<": ";
        cin>>weight[i]>>value[i];
    }

    int profit = knapsack(n,W,weight,value,0,0);
    cout<<"The maximum profit is: "<<profit<<endl;
}