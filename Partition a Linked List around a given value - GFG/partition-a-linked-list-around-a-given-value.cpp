// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    
    struct Node* zero=new Node(0);
    struct Node* ans=zero;
    struct Node* temp=head;
    while(temp!=NULL){
        if(temp->data<x){
            struct Node* node=new Node(temp->data);
            zero->next=node;
            zero=zero->next;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data==x){
            struct Node* node=new Node(temp->data);
            zero->next=node;
            zero=zero->next;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data>x){
            struct Node* node=new Node(temp->data);
            zero->next=node;
            zero=zero->next;
        }
        temp=temp->next;
    }
    return ans->next;
}