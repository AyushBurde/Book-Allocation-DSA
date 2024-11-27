#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;



int isPossible(vector<int> &arr, int n, int m , int maxAllowedPages) { //O(n)
    int painter =1 , time= 0 ;

    for (int i =0; i<n; i++){
        if(arr[i]> maxAllowedPages){
            return false;
        }

        if(time + arr[i] <= maxAllowedPages){
            time = time+arr[i];
        } else {
            painter ++;
            time = arr[i]; 
        }
    }

    return painter > m ? false : true;
}
int minTimeToPaint(vector<int> &arr, int n, int m ){
    if(m>n){  // checking if our students is higher than the no. of books
        return -1;
    }

    int sum =0 , maxVal = INT8_MIN; // Finding the maximum no. 
    for (int i =0; i<n ; i++) { 
        sum=sum+arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int ans= -1 ;
    int st= maxVal , end =sum ; // range of possible ans

    while( st<=end ){ // log(sum) * n 
        int mid = st + (end-st)/2;

        if(isPossible(arr, n , m , mid)){ // if valid then check on left sife for more small val
            ans= mid;
            end=mid-1;
        } else { // if not then check on the right 
            st=mid+1;
        }
    }
return ans;
    
}

int main (){

    vector<int> arr = {40,30,10,20};
    int n =4 , m=2;
    cout<< minTimeToPaint(arr, n , m );
    return 0;
}