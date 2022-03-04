// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *cur=head,*pre=NULL;
        while(cur!=NULL){
            Node *temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        cur=pre;
        cur->data=cur->data+1;
        
        int cy=0;
        while(cur->next!=NULL){
            int x=cur->data+cy;
            cur->data=(x)%10;
            cy=x/10;
            cur=cur->next;
        }
        int x=cur->data+cy;
            cur->data=(x)%10;
            cy=x/10;
        if(cy>0) cur->next=new Node(cy);
        cur=pre;
        Node *fut=NULL;
        while(cur!=NULL){
            Node *temp=cur->next;
            cur->next=fut;
            fut=cur;
            cur=temp;
        }
        head=fut;
        return head;
        // Your Code here
        // return head of list after adding one
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends