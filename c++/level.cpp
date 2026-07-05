/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *plug(Node *head)
    {

        if (!head || !head->next)
            return nullptr;
        Node *temp = head;
        while (temp->next)
        {
            if (temp->child)
            {
                Node *tail = temp->next;
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = nullptr;
                temp = temp->next;
                temp = plug(temp);

                temp->next = tail;
                temp->next->prev = temp;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return temp;
    }
    Node *flatten(Node *head)
    {
        Node *temp =
            plug(head);
        return head;
    }
};
void show(Node *temp)
{
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Node *n1 = new Node{1, nullptr, nullptr, nullptr};
    Node *n2 = new Node{2, nullptr, nullptr, nullptr};
    Node *n3 = new Node{3, nullptr, nullptr, nullptr};
    Node *n4 = new Node{4, nullptr, nullptr, nullptr};
    Node *n5 = new Node{5, nullptr, nullptr, nullptr};
    Node *n6 = new Node{6, nullptr, nullptr, nullptr};
    Node *n7 = new Node{7, nullptr, nullptr, nullptr};
    Node *n8 = new Node{8, nullptr, nullptr, nullptr};
    Node *n9 = new Node{9, nullptr, nullptr, nullptr};
    Node *n10 = new Node{10, nullptr, nullptr, nullptr};
    Node *n11 = new Node{11, nullptr, nullptr, nullptr};
    Node *n12 = new Node{12, nullptr, nullptr, nullptr};

    // Nối level 1
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    n5->next = n6;
    n6->prev = n5;

    // Nối level 2 (child của 3 là 7, của 8 là 11)
    n3->child = n7;

    n7->next = n8;
    n8->prev = n7;

    n8->next = n9;
    n9->prev = n8;

    n9->next = n10;
    n10->prev = n9;

    // Nối level 3 (child của 8 là 11)
    n8->child = n11;

    n11->next = n12;
    n12->prev = n11;

    Solution b;
    n1 = b.flatten(n1);
    show(n1);
    return 0;
}