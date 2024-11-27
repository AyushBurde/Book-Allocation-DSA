#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible (vector<int> &arr, int N , int C, int mid){ // placing the cows 
    int cows= 1 , lastPos= arr[0];

    for(int i=1; i<N; i++){
        if(arr[i]- arr[i-1] >= mid ){
            cows ++;
            lastPos= arr[i];
        }

        if(cows == C){
            return true;
        }
    }
    return false;
}


int getDistance (vector<int> &arr, int N , int C){
    // st=1 , end = maxVal - minVal;
    sort(arr.begin(), arr.end());
    int st=1 , end= arr[N-1] - arr[0], ans = -1 ;

    while(st<= end ){
        int mid = st+ (end-st)/2;

        if(isPossible(arr, N , C , mid) ) { // if yes go to right 
            ans = mid;
            st= mid +1 ;
        }  else { // left
            end = mid-1 ;
        }
    } 
};

int main (){
int N = 5, C=3;
vector<int> arr= { 1,2,8,4,9};

cout<< getDistance(arr , N , C);

    return 0;
}

