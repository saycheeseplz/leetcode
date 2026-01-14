
Node *balanceRight(Node *node, bool &shorter)
{
    Node *noderight = node->pRight;
    if (noderight->balance == RH)
    {
        // R-R case
        noderight->balance = EH;
        node->balance = EH;
        node = rotateLeft(node);
        shorter = true;
        return node;
    }
    else if (noderight->balance == EH)
    {
        // E-R case (Equal of Right)
        noderight->balance = LH;
        node->balance = RH;
        node = rotateLeft(node);
        shorter = false;
        return node;
    }
    else // noderight->balance == LH
    {
        // R-L case
        Node *nodeleft = noderight->pLeft;
        if (nodeleft->balance == RH)
        {
            node->balance = LH;
            noderight->balance = EH;
        }
        else if (nodeleft->balance == EH)
        {
            node->balance = EH;
            noderight->balance = EH;
        }
        else // nodeleft->balance == LH
        {
            node->balance = EH;
            noderight->balance = RH;
        }
        nodeleft->balance = EH;
        node->pRight = rotateRight(noderight);
        node = rotateLeft(node);
        shorter = true;
    }
    return node;
}

Node *balanceLeft(Node *node, bool &shorter)
{
    Node *nodeleft = node->pLeft;
    if (nodeleft->balance == LH)
    {
        // L-L case
        nodeleft->balance = EH;
        node->balance = EH;
        node = rotateRight(node);
        shorter = true;
        return node;
    }
    else if (nodeleft->balance == EH)
    {
        // E-L case (Equal of Left)
        nodeleft->balance = RH;
        node->balance = LH;
        node = rotateRight(node);
        shorter = false;
        return node;
    }
    else // nodeleft->balance == RH
    {
        // L-R case
        Node *noderight = nodeleft->pRight;
        if (noderight->balance == LH)
        {
            node->balance = RH;
            nodeleft->balance = EH;
        }
        else if (noderight->balance == EH)
        {
            node->balance = EH;
            nodeleft->balance = EH;
        }
        else // noderight->balance == RH
        {
            node->balance = EH;
            nodeleft->balance = LH;
        }
        noderight->balance = EH;
        node->pLeft = rotateLeft(nodeleft);
        node = rotateRight(node);
        shorter = true;
    }
    return node;
}

Node *removeNode(Node *node, const T &value, bool &shorter)
{
    if (!node)
    {
        shorter = false;
        return nullptr;
    }

    if (value < node->data)
    {
        node->pLeft = removeNode(node->pLeft, value, shorter);
        if (shorter)
        {
            if (node->balance == LH)
            {
                node->balance = EH;
            }
            else if (node->balance == EH)
            {
                node->balance = RH;
                shorter = false;
            }
            else // node->balance == RH
            {
                node = balanceRight(node, shorter);
            }
        }
    }
    else if (value > node->data)
    {
        node->pRight = removeNode(node->pRight, value, shorter);
        if (shorter)
        {
            if (node->balance == RH)
            {
                node->balance = EH;
            }
            else if (node->balance == EH)
            {
                node->balance = LH;
                shorter = false;
            }
            else // node->balance == LH
            {
                node = balanceLeft(node, shorter);
            }
        }
    }
    else // node->data == value - Found the node to delete
    {
        if (!node->pLeft && !node->pRight)
        {
            // Leaf node
            delete node;
            shorter = true;
            return nullptr;
        }
        else if (!node->pLeft)
        {
            // Only right child
            Node *temp = node->pRight;
            delete node;
            shorter = true;
            return temp;
        }
        else if (!node->pRight)
        {
            // Only left child
            Node *temp = node->pLeft;
            delete node;
            shorter = true;
            return temp;
        }
        else
        {
            // Both children exist - find max in left subtree
            Node *maxNode = node->pLeft;
            while (maxNode->pRight)
            {
                maxNode = maxNode->pRight;
            }
            node->data = maxNode->data;
            node->pLeft = removeNode(node->pLeft, maxNode->data, shorter);

            if (shorter)
            {
                if (node->balance == LH)
                {
                    node->balance = EH;
                }
                else if (node->balance == EH)
                {
                    node->balance = RH;
                    shorter = false;
                }
                else // node->balance == RH
                {
                    node = balanceRight(node, shorter);
                }
            }
        }
    }
    return node;
}

void remove(const T &value)
{
    bool shorter = false;
    root = removeNode(root, value, shorter);
}