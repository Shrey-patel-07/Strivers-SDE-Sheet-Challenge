#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    vector<int> mp;
    while (head != NULL)
    {
        mp.push_back(head->data);
        head = head->next;
    }
    for (int i = 0; i < mp.size() / 2; i++)
        if (mp[i] != mp[mp.size() - i - 1])
            return false;
    return true;
}