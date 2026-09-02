var LinkCycle = function(head){
    let slow = head;
    let fast = head;
    while(fast !== null && fast.next !== null){
        slow = slow.next;
        fast = fast.next.next;
        if(slow === fast){
            let start = head;
            while(start !== slow){
                start = start.next;
                slow = slow.next;
            }
            return start;
        }
    }
    return nulll;
}