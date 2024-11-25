#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;



int isValid(vector<int> &arr, int n, int m , int maxAllowedPages) {
    int students =1 , pages= 0 ;

    for (int i =0; i<n; i++){
        if(arr[i]> maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages = pages+arr[i];
        } else {
            students ++;
            pages = arr[i]; 
        }
    }

    return students > m ? false : true;
}
int allocateBooks(vector<int> &arr, int n, int m ){
    if(m>n){  // checking if our students is higher than the no. of books
        return -1;
    }

    int sum =0; // finding sums of all arrays
    for (int i =0; i<n ; i++) {
        sum=sum+arr[i];
    }

    int ans= -1 ;
    int st=0 , end =sum ; // range of possible ans

    while( st<=end ){
        int mid = st + (end-st)/2;

        if(isValid(arr, n , m , mid)){ // if valid then check on left sife for more small val
            ans= mid;
            end=mid-1;
        } else { // if not then check on the right 
            st=mid+1;
        }
    }
return ans;
    
}

int main (){

    vector<int> arr = {2,1,3,4};
    int n =4 , m=2;
    cout<< allocateBooks(arr, n , m );
    return 0;
}