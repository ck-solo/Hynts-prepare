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

int sumN(int n ){
    int sum = 0;
    for(int i = 0; i<=n;i++){
        sum=sum+i;
    }
    return sum ;
}

int main(){
    cout << sumN(5) << endl;
    return 0;
}
  

