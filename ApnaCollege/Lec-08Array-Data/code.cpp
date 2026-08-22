#include <iostream>
using namespace std;

// int main(){
//     int marks[5] = {97, 85, 78, 94, 99};
//     int double_marks[5];

//     for (int i = 0; i < 5; i++){
//         double_marks[i] = marks[i] * 2;
//     }

//     for (int i = 0; i < 5; i++){
//         cout << double_marks[i] << " ";
//     }

//     return 0;
// }


int main(){
    int marks[] = {99, 100, 54, 36, 88};
    int size = 5; 
    // cout << sizeof(marks) << endl;
    for(int i = 0; i<size; i++){
        cout << marks[i] << endl;
    }
    return 0;
} 