#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;

int getMax(int mat[][3], int rows , int cols){
   int maxColSum = INT32_MIN;

   for(int j =0; j<cols ; j++){
      int rowSum = 0;
      for(int i =0; i<rows; i++){
         rowSum += mat[i][j];

      }
      maxColSum= max(maxColSum, rowSum);
   }
}

int main(){
   int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
   int rows  = 3;
   int cols = 3;
  
   return 0;

}
 
  

  
 

