#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

//returns 1 if x is divisible by y otherwise 0
int is_divisible(int x, int y){
    if(x%y==0){return 1;} else{return 0;}
}

//returns 1 if n is prime otherwise 0
int is_prime(int n){
    if(n == 1){return 0;}
    if(n == 2){return 1;}
    int upper_bound = pow(n, 0.5) + 1;
    int i;
    for(i = 2; i < upper_bound; i++){
        if(is_divisible(n, i) == 1){return 0;}
    }
    return 1;
}

int nthprime(int n){
    int i = 0;
    int total_primes = 0;
    int current_prime = 0;
    while(total_primes < n+1){
        if(is_prime(i) == 1){current_prime = i; total_primes += 1;}
        i += 1;
    }
    return current_prime;
}

//returns the largest prime factor of an integer n
int largest_prime_factor(int n){
    //we repeatedly factor out prime numbers from n
    //we attempt 2, if we cannot then we attempt 3, and so on
    //if no prime numbers may be factored from n which are less than sqrt(n)+1 we may say n is prime
    //and it will be its own largest prime factor
    int i = 1;
    int factor;
    while(is_prime(n) == 0){
        factor = nthprime(i);
        if(is_divisible(n, factor) == 1){
            n /= factor;
            i = 1;
        }
        else if(factor < pow(n, 0.5) + 1){
            i += 1;
        }
        if(is_prime(n)){return n;}
        }
    }

//takes an integer from the user and returns its largest prime factor
int main(){
    char numinp[10];
    scanf("%s", numinp);
    int num = strtol(numinp, NULL, 10);
    printf("%d", largest_prime_factor(num));
    return 0;
}