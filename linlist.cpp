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
// linklist
template <class T>
class List
{
public:
    struct idxval
    {
        int index;
        T *p;
    };
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void clear() = 0;
    virtual bool insert(const T &, int) = 0;
    virtual bool insert(T &&, int) = 0;

    virtual bool removeIdx(int) = 0;
    virtual bool remove(const T &, function<bool(const T &, const T &)> eq = [](const T &key, const T &val) -> bool
                        { return key == val; }) = 0;
    virtual T &operator[](int) = 0;
    virtual T *getItem(int) = 0;

    virtual T *find(const T &, function<bool(const T &, const T &)> eq = [](const T &key, const T &val) -> bool
                    { return key == val; }) = 0;
    virtual int findIdx(const T &, function<bool(const T &, const T &)> eq = [](const T &key, const T &val) -> bool
                        { return key == val; }) = 0;
    virtual List<idxVal> *rangeSearch(const T &keyA, const T &keyB, function<bool(const T &, const T &)> less = [](const T &key, const T &keyRef) -> bool
                                      { return key < refKey; }) = 0;)
    virtual  List<T> * clone(int ,int )=0;
    virtual T *toArray(int, int) = 0;
    virtual void reverse() = 0;
    virtual List<T> *split(int) = 0;
    virtual void merge(List<T> *pL) = 0;

    virtual void traverse(function<void(T &)>) = 0;
};
template <class T>
ostream &operator<<(ostream &os, List<T> *pL)
{
    pL->traverse([&os](T &val)
                 { os << val << " "; })
            os
        << endl;
    return os;
}
// todo :array list

template <class T>
class ArrayList : public List<T>
{
protected:
    T *pD;
    int nE, cap;

public:
    ArrayList():ne(0),cap(0),pD(nullptr){}
    ~ArrayList(){
        if(pD)
        delete pD;
    }
    int getSize(){
        return nE;
    }
    bool isEmpty(){
        return !nE;
    }
    void clear(){
        if(pD){
            delete[]pD;
            pD=nullptr;
            nE=cap=0;
        }
    }
    bool insert(const T & val, int idx){
        return true;
    }  
    bool insert(T &&, int){
    return true;
    } 

    virtual bool removeIdx(int) = 0;
    virtual bool remove(const T &, function<bool(const T &, const T &)> eq = [](const T &key, const T &val) -> bool
                        { return key == val; }) = 0;
    virtual T &operator[](int) = 0;
    virtual T *getItem(int) = 0;

    virtual T *find(const T &, function<bool(const T &, const T &)> eq = [](const T &key, const T &val) -> bool
                    { return key == val; }) = 0;
    virtual int findIdx(const T &, function<bool(const T &, const T &)> eq = [](const T &key, const T &val) -> bool
                        { return key == val; }) = 0;
    virtual List<idxVal> *rangeSearch(const T &keyA, const T &keyB, function<bool(const T &, const T &)> less = [](const T &key, const T &keyRef) -> bool
                                      { return key < refKey; }) = 0;)
    virtual  List<T> * clone(int ,int )=0;
    virtual T *toArray(int, int) = 0;
    virtual void reverse() = 0;
    virtual List<T> *split(int) = 0;
    virtual void merge(List<T> *pL) = 0;

    virtual void traverse(function<void(T &)>) = 0;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}