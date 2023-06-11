#include <bits/stdc++.h>
using namespace std;

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    unordered_set<Node *> mp;
    while (head != NULL)
    {
        if (mp.find(head) != mp.end())
            return head;
        mp.insert(head);
        head = head->next;
    }
    return NULL;
    //    Write your code here.
}