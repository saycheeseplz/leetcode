template <class T>
int Heap<T>::getItem(T item)
{
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
    int idx = getItem(item);
    if (idx == -1)
    {
        return;
    }
    elemnets[idx] = elements[count - 1];
    count--;
    reheapDown(idx);
}

template <class T>
void Heap<T>::clear()
{
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    this->count = 0 delete[] elements;
}