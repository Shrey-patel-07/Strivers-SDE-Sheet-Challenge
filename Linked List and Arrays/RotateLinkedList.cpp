/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    if (head == NULL || head->next == NULL || !k)
        return head;
    int len = 1;
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        len++;
        tmp = tmp->next;
    }
    tmp->next = head;
    k = k % len;
    k = len - k;
    while (k--)
    {
        tmp = tmp->next;
    }
    head = tmp->next;
    tmp->next = NULL;
    return head;
    // Write your code here.
}