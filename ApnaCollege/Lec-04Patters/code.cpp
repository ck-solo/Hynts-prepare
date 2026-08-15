#include <iostream>
using namespace std;

// int main(){
//     int n = 4;
//     for(int i =1; i<=n; i++){
//         for(int j = 1; j <= n; j++){
//             cout <<  "* ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// int main(){
//     int n = 4;
//     for(int i = 0; i<=n; i++){
//         char ch = 'A';
//         for(int j =0; j<=n; j++){
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;

//     }
//     return 0;

// }




// int main(){
//     int n = 3;
//     int count = 1;
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<n ; j++){
//             cout << count << " "; 
//             count++;   
//         }
//         cout << endl;
//     }
//     return 0;
// }


// int main(){
//     int n = 3;
//     char ch = 'A';
//     for(int i = 0; i<=n; i++){
//         for(int j = 0; j<n; j++){
//             cout << ch << " ";
//             ch++;
//         }
//         cout << endl;
//     }
//     return 0;
// }




// int main(){
//     int n = 4;
//      for(int i = 0; i<n; i++){
//         for(int j = 0; j < i+ 1 ; j++){
//             cout << "* " << " ";
//         }
//         cout << endl;
//      }
//      return 0;
// }



// int main(){
//     int n = 3;
//     for(int i = 0; i<=n; i++){
//         for(int j = 0; j<i+1; j++){
//             cout<< i+1 << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Alphabet Triangel Pattern
// int main(){
//     int n = 3;
//     char ch = 'A';
//     for(int i = 0; i<=n; i++){
//         for(int j = 0; j<i + 1; j++){
//             cout << ch << " ";
//         }
//         ch++;
//         cout << endl;
//     }
//     return 0;
// }



// int main(){
//     int n = 3;
//     for(int i = 0; i<n; i++){
//         for(int j = 1; j<= i+1; j++){
//             cout << j << " ";
//         }
//     cout << endl;
//     }

//     return 0;
// }



// int main(){
//     int n = 3;
//     for(int i = 0; i<n; i++){
//         for(int j = 1; j<= i+1; j++){
//             cout << j << " ";
//         }
//     cout << endl;
//     }

//     return 0;
// }


// Reverse number
// int main(){
//     int n = 3;
//     for(int i = 0; i<n; i++){
//         for(int j = i+1; j>0; j--){
//             cout << j << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// Floyd Traingle Number Pattern 
// int main(){
//     int n = 3;
//     int num = 1;
//     for(int i =0; i<=n; i++){
//         for(int j =1; j<= i+ 1; j++){
//             cout << num << " ";
//             num++;
//         } 
//     cout << endl;
//     }
//     return 0;
// }


// Floyd Traingle Alphabet Patter
int main(){
    int n = 4;
    for(int i = 0; i <=n; i++){
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++){
            cout << ch << " ";
            ch--; 
        }
        cout << endl;
    }
    return 0;
}

