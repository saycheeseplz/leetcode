

void rotateRight(Node *&node)
{
    Node *temp = node->pLeft;
    temp->parent = node->parent;
    node->pLeft = temp->pRight;
    if (temp->pRight)
    {
        temp->pRight->parent = node;
    }
    if (!node->parent)
    {
        root = temp;
    }
    else if (node->parent->pLeft == node)
    {
        node->parent->pLeft = temp;
    }
    else
    {
        node->parent->pRight = temp;
    }
    node->parent = temp;
}
void rotateLeft(Node *&node)
{
    Node *temp = node->pRight;
    temp->parent = node->parent;
    node->pRight = temp->pLeft;
    if (temp->pLeft)
    {
        temp->pLeft->parent = node;
    }
    if (!node->parent)
    {
        root = temp;
    }
    else if (node->parent->pLeft == node)
    {
        node->parent->pLeft = temp;
    }
    else
    {
        node->parent->pRight = temp;
    }
    node->parent = temp;
}
void splay(Node *p)
{
    if (!p->parent)
    {
        return;
    }
    Node* P=p->parent;
    Node* GP=p->parent; 
    if (!GP&& P->pLeft)
    {
        rotateRight(P);
        splay(P);
    }
    if(!GP&& P->pRight)
    {
        rotateLeft(P);
        splay(P);
    }else
    if(GP->pLeft==P&& P->pLeft==p)
    {
        rotateRight(P);
        splay(P);
    }else
    if(GP->pLeft==P&& P->pRight==p)
    {
        rotat
        rotateRight(g)
    }
    
}
Node *insertNode(Node *node, int val)
{
    if (!node)
    {
        Node *temp = new Node(val);
        return temp;
    }
    if (node->val > val)
    {
        node->pLeft = insertNode(node->pLeft, val);
        node->pLeft->parent = node;
    }
    else
    {
        node->pRight = insertNode(node->pRight, val);
        node->pRight->parent = node;
    }
}
void insert(int val)
{
    if (!root)
    {
        root = new Node(val);
        root->parent = nullptr;
    }
    root = insertNode(root, val);
    splay(root);
}
