class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    insert(val) {
        let node = new ListNode(val);
        if (!this.head) {
            this.head = node;
            return;
        }
        let temp = this.head;
        while (temp.next) temp = temp.next;
        temp.next = node;
    }

    print() {
        let res = [];
        let temp = this.head;
        while (temp) {
            res.push(temp.val);
            temp = temp.next;
        }
        console.log(res.join(" -> "));
    }
}

// ✅ FIXED PART
let ll = new LinkedList();

ll.insert(10);
ll.insert(20);
ll.insert(30);

ll.print();
