#include<iostream>
#include <cmath>
#include <vector>
using namespace std;
//Consider an infinite string that consists of all positive integers in increasing order:
//12345678910111213141516171819202122232425...
//Your task is to process q queries of the form: what is the digit at position k in the string?
//Input
//The first input line has an integer q: the number of queries.
//After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.
//Output
//For each query, print the corresponding digit.
vector<int> ftc(int n){
 vector<int> arr ;
 for(int i=1 ; i<n+1; ++i){
  int a = log10(i)+1 ;
  if(a==1)
     arr.push_back(i) ;
  else{
    int k=i ;
    int ar[a] ;
    for(int j=a-1 ; j>=0 ; --j){
      ar[j]=k%10 ;
      k/=10 ;
    }
    for(int j=0 ; j<a ; ++j){
     arr.push_back(ar[j]) ;
    }
  }   
 }
 return arr;
}
int main(){
   int t; 
   cin >>t ;
   int arr[t] ;
   for (int i = 0; i < t; i++)
   {
    cin >>arr[i] ;
   }
   for(int i=0 ; i<t ; ++i){
   vector<int> ap = ftc(arr[i]) ;
   cout <<ap[arr[i]-1] <<'\n' ;
   }
  }