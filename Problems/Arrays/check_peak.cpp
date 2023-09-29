// https://practice.geeksforgeeks.org/problems/peak-element/1?page=1&difficulty[]=0&company[]=Adobe&sortBy=submissions
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int checkPeak(int i , int arr[],int n){
        if(i==0){
            if(arr[1]<=arr[0])return 0;
            else return -1;
        }
        if(i==n-1){
            if(arr[n-2]<=arr[n-1])return n-1;
            else return -1;
        }
        if(arr[i-1]<=arr[i] && arr[i+1]<=arr[i])return i;
        else return -1;
    }
    int solve(int l , int h , int arr[], int n){
        if(l==h)return checkPeak(l,arr,n);//returns -1 if not , index if it is
        int mid = l + (h-l)/2;
        int a = solve(l,mid,arr,n);
        if(a!=-1)return a;
        int b = solve(mid+1 , h , arr,n);
        return b;
    }
    int peakElement(int arr[], int n)
    {
       // Your code here
       if(n==1)return 0;
       return solve(0,n-1,arr,n);
    }



