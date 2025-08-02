#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//There is a street of length x whose positions are numbered 0,1,\ldots,x. Initially there are no traffic lights, 
//but n sets of traffic lights are added to the street one after another.
//Your task is to calculate the length of the longest passage without traffic lights after each addition.
//Input
//The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
//Then, the next line contains n integers p_1,p_2,\ldots,p_n: the position of each set of traffic lights. Each position is distinct.
//Output
//Print the length of the longest passage without traffic lights after each addition.
int main(){
   int x , n;
   cin >>x >>n ;
   int ap[n], d1=0 , d2=x ;
   for(int i=0 ; i<n ; ++i)
      cin >>ap[i] ;   
   //sort(arr, arr+n) ;
   int max_len[n] ;
   for(int i=0 ; i<n ; ++i){
    int arr[i+1] ;
    for(int l=0 ; l<=i ; ++l)
       arr[l]=ap[l] ;
    sort(arr,arr+i+1) ;    
     int dis[2+i] , k=i+1 ;
     dis[0]=abs(arr[0]-d1);
     dis[1+i]=abs(d2-arr[i]) ;
     for(int j=1 ; j<1+i ; ++j){
       dis[j]=abs(arr[j]-arr[j-1]) ;
     }
     sort(dis,dis+i+2);
     max_len[i] = dis[1+i] ;
   }
   for(int i=0 ; i<n ; ++i){
    cout <<max_len[i] <<" " ;
   }
}