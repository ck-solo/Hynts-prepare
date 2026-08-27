#include <iostream>
#include <vector>
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
//  void changeArr(int arr[5], int size){
//     cout << "in Function\n";
//     for(int i = 0; i< size; i++){
//         arr[i] = 2 * arr[i];
//     }
//  }

//  int main(){
//     int arr[] = {1,2,3};
//     changeArr(arr, 3);

//     cout << "in main\n";
//     for(int i = 0; i<3; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
//  }


// Linear Search 
// int main(){
//     int array[] = {4,2,7,8,5,124,17,6,12,15,9,13,14,78};
//     int size = 14;
//     int target = 12; 
//     int index = -1;
//     for(int i = 0; i<=size; i++){ 
//         if(array[i] == target){
//             index = i;
//             break;
//         }
//     }
//     if(index != -1){
//         cout << "Element is present at index " << index << endl;
//     }else{
//         cout << "Element is not present in the array" << endl;
//     }
    
//     return 0;
// }


// int linearSearch(int arr[], int size, int target){
//     for(int i=0; i<size; i++ ){
//         if(arr[i] == target){
//             return i;
//         }
//     } 
//     return -1;
// }

// int main(){
//     int arr[] = {4,2,7,8,5,124,17,6,12,15,9,13,14,78};
//     int size = 14;
//     int target = 12; 
//     int index = linearSearch(arr, size, target);
//     if(index != -1){
//         cout << "Element is present at index " << index << endl;
//     }else{
//         cout << "Element is not present in the array" << endl;
//     }
//     return 0;
// }

// reverse an array

// void reverseArray(int arr[], int n) {
//     int left = 0;
//     int right = n - 1;
//     while (left < right) {
//         swap(arr[left], arr[right]);
//         left++;
//         right--;
//     }
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     int n = 5;
//     reverseArray(arr, n);
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


// linear search for a value that appears twice


// int main() {
//     vector<int> arr = {10, 20, 30, 20, 40};
//     int target = 20;
//     vector<int> indices;
//     for (int i = 0; i < arr.size(); i++) {
//         if (arr[i] == target) {
//             indices.push_back(i);
//         }
//     }
//     for (int index : indices) {
//         cout << index << " ";
//     }
//     return 0;
// }



// Conatenate Array With Reverse
//  vector<int> Concatenate(int nums[], int n) {
//     vector<int> ans;
//     // Original array
//     for (int i = 0; i < n; i++) {
//         ans.push_back(nums[i]);
//     }
//     // Reverse of array
//     for (int i = n - 1; i >= 0; i--) {
//         ans.push_back(nums[i]);
//     }
//     return ans;
// }

// int main() {
//     int nums[] = {1, 2, 3};
//     int n = sizeof(nums) / sizeof(nums[0]);
//     vector<int> ans = Concatenate(nums, n);
//     for (int x : ans) {
//         cout << x << " ";
//     }
//     return 0;
// }

//Find Largest and second largest in array 


 int findLargest(int nums[], int n) {
    int largest = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    return largest;
}

int main() {
    int nums[] = {4, 2, 9, 1, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    int ans = findLargest(nums, n);

    cout << "Largest element: " << ans;

    return 0;

}   