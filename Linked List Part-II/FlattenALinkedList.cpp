#include <bits/stdc++.h>

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *first, Node *second)
{
    Node *tmp = new Node(0);
    Node *start = tmp;

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            tmp->child = first;
            tmp = tmp->child;
            first = first->child;
        }
        else
        {
            tmp->child = second;
            tmp = tmp->child;
            second = second->child;
        }
    }
    if (first)
        tmp->child = first;
    else
        tmp->child = second;

    return start->child;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *down = head;
    Node *right = head->next;
    right = flattenLinkedList(right);
    down->next = NULL;
    Node *ans = merge(down, right);
    return ans;
    // Write your code here
}
