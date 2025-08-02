#include<iostream>
using namespace std;
//Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
//Each throw produces an outcome between 1 and  6.
//For example, if n=3, there are 4 ways:
//1+1+1
//1+2
//2+1
//3
//Input
// The only input line has an integer n.
// Output
// Print the number of ways modulo 10^9+7.
//Constraints
int solve(int n){
  if(n==0)
    return 1;
  int arr[6]={1,2,3,4,5,6} ;
  int count=0;
  for(auto x : arr){
   if(n-x>=0) 
    count+=solve(n-x) ;
  }
  return count ;  
}
int main(){
  int n; cin>> n;
  cout <<solve(n) ;
}