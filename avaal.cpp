void printInorderNode(Node *node)
{
    if (!node)
    {
        cout << "null" << " ";
    }
    printInorderNode(node->pLeft);
    cout << node->data << " ";
    printInorderNode(node->pRight);
}
void printInorder()
{
    printInorderNode(root);
}
bool searchNode(const T &value, Node *node)
{
    if (!node)
    {
        return 0;
    }
    if (node->data == value)
    {
        return 1;
    }
    else if (node->data > value)
    {
        return searchNode(value, node->pLeft);
    }
    else
    {
        return searchNode(value, node->pRight);
    }
}
bool search(const T &value)
{
    searchNode(value, root);
}