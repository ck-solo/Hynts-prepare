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


// int main(){
//     int size = 5; 
//     int marks[size] ; 
//     for(int i = 0; i<size; i++){
//         cin >> marks[i];
//     }
//     for(int i = 0; i<size; i++){
//         cout << marks[i] << endl;
//     }
//     return 0;
// } 


// Find smallest / largest in Array

// int main(){
//     int nums[] = {5, 15, 22, 1, -15,24};
//     int size = 6;
//     int smallest = INT_MAX;
//     int largest = INT_MIN;
//     for(int i =0; i<= size; i++){
//         smallest = min(nums[i], smallest);
//         largest = max(nums[i], largest);
//     }    
//     cout << "Smallest : " << smallest << endl;
//     cout << "Largest : " << largest << endl;
//     return 0;
// }


// Add the array values

// int main(){
//     int arr[5] = {1,2,3,4,5};
//     int sum = 0;
//     for(int i = 0; i < 5; i++){
//         sum += arr[i];
//     }
//     cout << "Sum of array : " << sum;
//     return 0;
// }


// Pass By Reference 
 void changeArr(int arr[5], int size){
    cout << "in Function\n";
    for(int i = 0; i< size; i++){
        arr[i] = 2 * arr[i];
    }
 }

 int main(){
    int arr[] = {1,2,3};
    changeArr(arr, 3);

    cout << "in main\n";
    for(int i = 0; i<3; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
 }
