
// Helping functions
Node *insertNode(Node *node, const T &value)
{
    if (!node)
    {
        Node *temp = new Node(value);
        return temp;
    }
    if (node->value >= value)
    {
        node->pRight = insertNode(node->pRight, value);
    }
    else
    {
        node->pLeft = insertNode(node->pLeft, value);
    }
}
void insert(const T &value)
{
    // TODO
    insertNode(root, value);
}
