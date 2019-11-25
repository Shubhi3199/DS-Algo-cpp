#include <iostream>
using namespace std;

// using recursion (basic) - time complexity O(2^n)
int fibonacci(int x){
    if(x==0)
        return 0;
    else if(x==1){
        return 1;
    }else{
        return fibonacci(x-2) + fibonacci(x-1);
    }
}

// using a for loop fibonacci O(n) -

int fib(int y){
    if(y<=1){
        return y;
    }
    int t0=0, t1=1, i, sum;
    for(i=2; i<=y; i++){
        sum = t0 + t1;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

// fibonacci series using Memoization to reduce the time complexity of recursive way to O(n)

int F[10];  // global array declared to store the known values so that the are not calculated again.
int memFib(int z){
    if(z<=1){
        F[z] = z;
        return z;
    }else{
        if(F[z-2]== -1){
            F[z-2] = memFib(z-2);
        }
        if(F[z-1]== -1){
            F[z-1] = memFib(z-1);
        }
        return F[z-2] + F[z-1];
    }

}


int main(){
    int num;
    cout<<"Enter the number of term required in fibonacci series";
    cin>>num;
    cout<<"\nThe fibonacci series is : " <<memFib(num);
}