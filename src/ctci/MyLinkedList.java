package ctci;

/**
 * Practice writing a linked list data structure from scratch
 */
public class MyLinkedList {
    Node head = null;
    MyLinkedList(int val) {
        this.head = new Node(val);
    }
    MyLinkedList() {
        return;
    }

    protected class Node{
        int value;
        Node next;
        public Node(int val) {
            this.value = val;
            this.next = null;
        }

    }
    public void appendToTail(int val) {
        if (this.head == null) {
            this.head = new Node(val);
        } else {
            // find the tail then insert new node there
            Node iter = this.head;
            while (iter.next != null) {
                iter = iter.next;
            }
            iter.next = new Node(val);
        }
    }

    public void print() {
        Node iter = this.head;
        while (iter != null) {
            System.out.println(iter.value);
            iter = iter.next;
        }
    }
}
