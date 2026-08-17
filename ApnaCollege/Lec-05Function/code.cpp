#include <iostream>
using namespace std;

// int printHello(){
//     cout << "Hello World \n";
//     return 3;
// } 

// int sum(int a, int b){
//     int s = a + b;
//     return s;
// }

 
// sum up to n 

// int sumN(int n ){
//     int sum = 0;
//     for(int i = 0; i<=n;i++){
//         sum=sum+i;
//     }
//     return sum ;
// }

// int main(){
//     cout << sumN(5) << endl;
//     return 0;
// }
  

//factorial of number 

// int factorial(int n){
//     int fact = 1;
//     for(int i = 1; i<=n; i++){
//         fact = fact * i;
//     }
//     return fact;

// }

// int main(){
//     cout << factorial(5) << endl;
//     return 0;
// }


// Sum of digit of number 
// int sumDigit(int n){
//     int sum = 0;
//     while(n > 0){
//         int lastDigit = n % 10;
//         n = n / 10;
//         sum = sum + lastDigit;
//     }
//     return sum;
// }

// int main(){
//     cout << sumDigit(145) << endl;

//     return 0;
// }



// nCr Binomial coefficient for n & r

int factorial(int n){
    int fact = 1;
    for(int i = 1; i <=n; i++){
        fact = fact * i;
    }
    return fact;
}

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

long long factorial(int n) {
    long long fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n))
        cout << factorial(n);
    else
        cout << "Not a prime number";

    return 0;
}

int nCr(int n, int r ){
     int fact_n = factorial(n);
     int fact_r = factorial(r);
     int fact_n_minus_r = factorial(n-r); 
     return (fact_n/ (fact_r*fact_n_minus_r));
}

int main(){
    int n = 5;
    int r = 3;
    
    cout << nCr(n,r) << endl;
    return 0;
}

int main
