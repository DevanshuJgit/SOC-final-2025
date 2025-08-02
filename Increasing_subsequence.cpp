#include<iostream>
#include <algorithm>
using namespace std;
// You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array,
// i.e., the longest subsequence where every element is larger than the previous one.
// A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements.
// Input
// The first line contains an integer n: the size of the array.
// After this there are n integers x_1,x_2,\ldots,x_n: the contents of the array.
// Output
// Print the length of the longest increasing subsequence.

int maxel(int ar[],int n){
  int sum =ar[0] ;
  for(int i=0 ; i<n ; ++i){
    if(sum<=ar[i])
      sum = ar[i] ; 
  }
  return sum ;
}
int main(){
  int n ; cin >>n;
  int arr[n];
  for(int i=0 ; i<n ; ++i)
     cin >>arr[i] ;
  int count[n] ;
  for(int i=0 ; i<n ; ++i)
     count[i]=1 ;
  for(int i=0 ; i<n ; ++i){
   for(int j=0 ; j<i ; ++j){
       if(arr[j]<arr[i])
     count[i]=max(count[i],count[j]+1) ;
   }
  }
  int f= maxel(count,n) ;
  cout <<f ;   
}

