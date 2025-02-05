
#include<iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr , int st , int end ){
    int idx=st-1 , pivot= arr[end];

    for(int j= st ; j<end ; j++){
        if(arr[j]<= pivot){
            idx++ ; 
            swap(arr[j] , arr[idx]);
        }     
    }
    //for placing our pivot 
    idx++ ; 
    swap(arr[end] , arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr , int st , int end){
    if(st<end){
       int Idx= partition(arr , st , end );
        quickSort(arr, st, Idx-1); //Left 
        quickSort(arr, Idx+1 , end ); //Right
    }

}

int main(){
    vector<int> arr= {5,2,6,4,1,3};
    quickSort(arr , 0 , arr.size()-1);
    for(int val : arr){
        cout<< val << " " ;
    }
    cout<< endl ;
    return 0 ;
}