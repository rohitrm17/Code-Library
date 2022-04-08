/*
https://www.hackerrank.com/contests/aps-2022-vie-01/challenges/second-largest-list
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long int n;
    scanf("%lld" , &n);
    long long int a[n];
    for(int i=0 ; i<n ; i++)
        scanf("%lld" , &a[i]);
    
    if(n == 1)
    {
        printf("-1");
        return 0;
    }
    
    long long int m1=-1 , m2=-1;
    
    for(int i=0 ; i<n ; i++)
        if(m1 < a[i])
            m1 = a[i];
    
    for(int i=0 ; i<n ; i++)
        if(m2<a[i] && a[i]<m1)
            m2 = a[i];
    
    printf("%lld" , m2);
    
    return 0;
}