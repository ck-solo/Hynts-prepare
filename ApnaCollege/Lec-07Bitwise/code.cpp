#include <iostream>
using namespace std;

// int main(){

//     int a = 4, b = 8;
//     cout << (a&b) << endl; 
//     cout << (a|b) << endl; 
//     cout << (a^b) << endl; 
  

//     return 0;
// }

// Find out how to find if a number is power of 2 without any loop


bool isPowerTwo(int n){
    return n > 0  && (n & (n - 1)) == 0;

}

int main(){
    int n = 18;
    
    if(isPowerTwo(n))
        cout << "Power of 2";
        else 
            cout << "Not a power of 2.";
        
    return 0;
}