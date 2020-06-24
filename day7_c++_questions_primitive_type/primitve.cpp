#include<stdio.h>
#include<iostream>
using namespace std;


 short parity1(unsigned long x) {
       short result = 0;
       while (x) {
          result ^= (x & 1);
          x >>= 1;
          }
         
           return result;
}

int main() {
    cout<<parity1(50);
}