template <class T>
int Heap<T>::getItem(T item)
{
    // TODO: return the index of item in heap
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == item)
        {
            return i;
        }
    }
    return -1;
}

template <class T>
void Heap<T>::remove(T item)
{
    // TODO: remove the element with value equal to item
    int flag = getItem(item);
    if (flag == -1)
    {
        return;
    }
    count--;
    elements[flag] = elements[count];
    reheapDown(flag);
    reheapUp(flag);
}

template <class T>
void Heap<T>::clear()
{
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    if (count == 0)
    {
        return;
    }
    delete[] elements;
    this->count = 0;
}