// var LinkCycle = function(head){
//     let slow = head;
//     let fast = head;
//     while(fast !== null && fast.next !== null){
//         slow = slow.next;
//         fast = fast.next.next;
//         if(slow === fast){
//             let start = head;
//             while(start !== slow){
//                 start = start.next;
//                 slow = slow.next;
//             }
//             return start;
//         }
//     }
//     return nulll;
// }


// print all elements of a linked list

// function ListNode(val) {
//     this.val = val;
//     this.next = null;
// }
// var printlist = function(head) {
//     let current = head;
//     while (current !== null) {
//         console.log(current.val);
//         current = current.next;
//     }
// };
// let node1 = new ListNode(10);
// let node2 = new ListNode(20);
// let node3 = new ListNode(30);
// let node4 = new ListNode(40);
// node1.next = node2;
// node2.next = node3;
// node3.next = node4;
// let head = node1;
// printlist(head);
// 10 → 20 → 30 → 40 → null



// count the nodes 
// function countNodes(head) {
//     let current = head;
//     let count = 0;
//     while (current !== null) {
//         count++;
//         current = current.next;
//     }
//     return count;
// }


// sum of nodes 
// function sumList(head) {
//     let current = head;
//     let sum = 0;
//     while (current !== null) {
//         sum = sum + current.val;
//         current = current.next;
//     }
//     return sum;
// }


// search of value 
// function search(head, value) {
//     let current = head;
//     while (current !== null) {
//         if (current.val === value) {
//             return true;
//         }
//         current = current.next;
//     }
//     return false;
// } 


// find the maximum value 
function findMax(head) {
    if (head === null) {
        return null;
    }
    let current = head;
    let max = head.val;
    while (current !== null) {
        if (current.val > max) {
            max = current.val;
        }
        current = current.next;
    }
    return max;
}


// revise 

// var LinkCycle = function(head){
//     let slow = head;
//     let fast = head;
//     while(fast !== null && fast.next !== null){
//         slow = slow.next;
//         fast = fast.next.next;
//         if(slow === fast){
//             let start = head;
//             while(start !== slow){
//                 start = start.next;
//                 slow = slow.next;
//             }
//             return start;
//         }
//     }
//     return nulll;
// }


