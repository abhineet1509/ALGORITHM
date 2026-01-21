// ================= NODE =================
class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

// ================= LINKED LIST =================
class LinkedList {
    constructor() {
        this.head = null;
    }

    insert(val) { // insert at end
        let node = new ListNode(val);
        if (!this.head) {
            this.head = node;
            return;
        }
        let temp = this.head;
        while (temp.next) temp = temp.next;
        temp.next = node;
    }

    print(head = this.head) {
        let temp = head;
        let res = [];
        while (temp) {
            res.push(temp.val);
            temp = temp.next;
        }
        console.log(res.join(" -> "));
    }
}

// ================= FUNCTIONS =================

// 1. Reverse Linked List
function reverseList(head) {
    let prev = null, curr = head;
    while (curr) {
        let next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 2. Delete node by value
function deleteNode(head, val) {
    if (!head) return null;
    if (head.val === val) return head.next;

    let curr = head;
    while (curr.next && curr.next.val !== val) {
        curr = curr.next;
    }
    if (curr.next) curr.next = curr.next.next;
    return head;
}

// 3. Detect Loop
function hasCycle(head) {
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) return true;
    }
    return false;
}

// 4. Middle Node
function middleNode(head) {
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
}

// 5. Remove Nth from End
function removeNthFromEnd(head, n) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let slow = dummy, fast = dummy;

    for (let i = 0; i <= n; i++) fast = fast.next;

    while (fast) {
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
}

// 6. Rotate List
function rotateRight(head, k) {
    if (!head || !head.next) return head;

    let len = 1, tail = head;
    while (tail.next) {
        tail = tail.next;
        len++;
    }

    k %= len;
    if (k === 0) return head;

    tail.next = head;
    let steps = len - k;
    let newTail = tail;
    while (steps--) newTail = newTail.next;

    let newHead = newTail.next;
    newTail.next = null;
    return newHead;
}

// 7. Merge Two Sorted Lists
function mergeTwoLists(l1, l2) {
    let dummy = new ListNode(-1);
    let curr = dummy;

    while (l1 && l2) {
        if (l1.val < l2.val) {
            curr.next = l1;
            l1 = l1.next;
        } else {
            curr.next = l2;
            l2 = l2.next;
        }
        curr = curr.next;
    }
    curr.next = l1 || l2;
    return dummy.next;
}

// 8. Merge K Sorted Lists
function mergeKLists(lists) {
    while (lists.length > 1) {
        let a = lists.shift();
        let b = lists.shift();
        lists.push(mergeTwoLists(a, b));
    }
    return lists[0];
}

// 9. Palindrome List
function isPalindrome(head) {
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    let second = reverseList(slow);
    let first = head;

    while (second) {
        if (first.val !== second.val) return false;
        first = first.next;
        second = second.next;
    }
    return true;
}

// 10. Intersection of Two Lists
function getIntersectionNode(headA, headB) {
    let a = headA, b = headB;
    while (a !== b) {
        a = a ? a.next : headB;
        b = b ? b.next : headA;
    }
    return a;
}

// 11. Add Two Numbers
function addTwoNumbers(l1, l2) {
    let dummy = new ListNode(0);
    let curr = dummy, carry = 0;

    while (l1 || l2 || carry) {
        let sum = carry;
        if (l1) { sum += l1.val; l1 = l1.next; }
        if (l2) { sum += l2.val; l2 = l2.next; }

        carry = Math.floor(sum / 10);
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
    }
    return dummy.next;
}

// ================= MAIN =================

console.log("Original Linked List:");
let ll = new LinkedList();
ll.insert(1);
ll.insert(2);
ll.insert(3);
ll.insert(4);
ll.insert(5);
ll.print();

console.log("\nReverse:");
ll.head = reverseList(ll.head);
ll.print();

console.log("\nDelete value 3:");
ll.head = deleteNode(ll.head, 3);
ll.print();

console.log("\nMiddle Node:");
console.log(middleNode(ll.head).val);

console.log("\nRemove 2nd from end:");
ll.head = removeNthFromEnd(ll.head, 2);
ll.print();

console.log("\nRotate by 2:");
ll.head = rotateRight(ll.head, 2);
ll.print();

console.log("\nPalindrome Check:");
console.log(isPalindrome(ll.head));

// Merge Two Sorted Lists
let a = new LinkedList();
a.insert(1); a.insert(3); a.insert(5);

let b = new LinkedList();
b.insert(2); b.insert(4); b.insert(6);

console.log("\nMerge Two Sorted Lists:");
let merged = mergeTwoLists(a.head, b.head);
ll.print(merged);

// Add Two Numbers
let n1 = new LinkedList();
n1.insert(2); n1.insert(4); n1.insert(3);

let n2 = new LinkedList();
n2.insert(5); n2.insert(6); n2.insert(4);

console.log("\nAdd Two Numbers:");
let sum = addTwoNumbers(n1.head, n2.head);
ll.print(sum);
