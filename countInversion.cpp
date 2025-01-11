#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st ,int mid ,  int end){
    vector<int> temp ;
    int i= st , j= mid+1 ;
    int invCount = 0 ;
    while(i<=mid && j<=end){
        if(arr[i]<= arr[j]){
            temp.push_back(arr[i]);
            i++ ;
        }else {
            temp.push_back(arr[j]);
            j++ ; 
            invCount += (mid - i + 1) ; // counting inversions in one go 
        }
    }
    ///For left out elm (left or right koi bi ek )
    //Left 
    while(i<=mid){
          temp.push_back(arr[i]);
            i++ ;

    }

    //Right 
    while(j<=end){
           temp.push_back(arr[j]);
            j++ ;

    }
    
    // copy temp in orginal array 
    for(int idx=0 ; idx<temp.size() ; idx++){
        arr[idx+st] = temp[idx];
    }
    return invCount ; 

}

int countInv (vector<int> &arr, int st , int end ){

    if(st<end){
        int mid = st + (end-st)/2 ;
        // Recursively do for left and right part 

       int leftInversion = countInv(arr , st , mid); //Left 
        int rightInversion = countInv(arr , mid+1 , end); //Right

        int invCount = merge(arr , st , mid , end);

        return leftInversion + rightInversion + invCount ;
    }
    
return 0 ; 
}

int main(){
    vector<int> arr= {6,3,5,2,7} ; 
   int ans =  countInv(arr , 0 , arr.size()-1);
   cout<< ans << endl ; 
 
    return 0 ; 
}