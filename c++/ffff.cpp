#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(nullptr) {}
};

// Trả về con trỏ head của danh sách 10 nút đã dựng thủ công
Node *buildManualList()
{
    // Tạo từng nút theo thứ tự đề bài
    Node *n1 = new Node(23);
    Node *n2 = new Node(-5);
    Node *n3 = new Node(17);
    Node *n4 = new Node(42);
    Node *n5 = new Node(0);
    Node *n6 = new Node(99);
    Node *n7 = new Node(-12);
    Node *n8 = new Node(8);
    Node *n9 = new Node(8);
    Node *n10 = new Node(3);

    // Nối lại thành list 10 nút
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10; // nút cuối

    return n1; // head
}

int findMin(Node *head)
{
    if (!head)
        throw runtime_error("List rỗng");
    int mn = head->val;
    for (Node *p = head->next; p != nullptr; p = p->next)
    {
        if (p->val < mn)
            mn = p->val;
    }
    return mn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *head = buildManualList();
    int mn = findMin(head);
    cout << "Min = " << mn << "\n";

    // (tuỳ chọn) giải phóng bộ nhớ
    Node *p = head;
    while (p)
    {
        Node *nxt = p->next;
        delete p;
        p = nxt;
    }
    return 0;
}
