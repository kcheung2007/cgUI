//+------------------------------------------------------------------
//
// 	Project:	TimeMachine (occasionally abbreviated TM)
//
//  Copyright (C) Play Incorporated, 1996
//
//  File:       tsslist.h
//
//  Contents:   generic doubly linked list class.  written after
//              I began to have problems with STL (the least of which
//              was debugging them to see what I was doing wrong)
//
//  Author:     Michael Wang-Helmke
//
//  Change History: 7/6/96   initial creation
//
//-------------------------------------------------------------------

#ifndef __TSSLIST_H__
#define __TSSLIST_H__

template <class T>
struct tssnode {
    tssnode *next;
    tssnode *prev;
    T data;
};

template <class T >
class tsslist {
private:
    tssnode<T> *node;
    long length;

public:
    tsslist(void) : length(0) {
        node = new tssnode<T>;
        if(NULL != node)
        {
            node->next = node;
            node->prev = node;
        }
    };
    ~tsslist();

    long size(void) {return length;}
    tsslist<T>& operator=(tsslist<T> &other);
    tssnode<T> *begin(void) {return node->next;}
    tssnode<T> *end(void) {return node;}

    tssnode<T>* insert_after(tssnode<T> *pos, const T &x);
    tssnode<T>* insert_before(tssnode<T> *pos, const T &x);
    tssnode<T>* insert_ordered(const T &x,
         int (*cmp)(T e1, T e2));
    void push_front(const T &x) {insert_before(begin(),x);}
    void push_back(const T &x) {insert_before(end(),x);}

    void clear_list(void); // erase everything
    void clear_ptr_list(void); // erase everything and assume that
                               // T must be deallocated as well
    void erase(tssnode<T> *pos);
    void pop_front(void) {erase(begin());}
    void pop_back(void) {erase((end())->prev);}
};

template <class T>
tsslist<T>::~tsslist() {
    clear_list();
    if(node)
        delete node;
}

template <class T>
tsslist<T>&
 tsslist<T>::operator=(tsslist<T> &other) {
    tssnode<T> *tmp, *next;

    if (this != &other) {
            // first erase what this list holds
        clear_list();
            // now assign other to this list
        tmp = other.begin();
        while(tmp != other.end()) {
            next = tmp->next;
            push_back(tmp->data);
            tmp = next;
        }
    }
    return *this;
}

template <class T>
tssnode<T>* tsslist<T>::insert_after(tssnode<T> *pos, const T &x)
{
    tssnode<T> *tmp = new tssnode<T>;
    if(NULL == tmp)
        return NULL;
    tmp->data = x;
    if(length == 0) {
        node->next = tmp;
        node->prev = tmp;
        tmp->next = node;
        tmp->prev = node;
    } else {
        tmp->next = pos->next;
        tmp->prev = pos;
        pos->next->prev = tmp;
        pos->next = tmp;
    }
    length++;
    return tmp;
}

template <class T>
tssnode<T>* tsslist<T>::insert_before(tssnode<T> *pos, const T &x)
{
    tssnode<T> *tmp = new tssnode<T>;
    if(NULL == tmp)
        return NULL;
    tmp->data = x;
    if(length == 0) {
        node->next = tmp;
        node->prev = tmp;
        tmp->next = node;
        tmp->prev = node;
    } else {
        tmp->next = pos;
        tmp->prev = pos->prev;
        pos->prev->next = tmp;
        pos->prev = tmp;
    }
    length++;
    return tmp;
}

template <class T>
tssnode<T>* tsslist<T>::insert_ordered(const T &x,
         int (*cmp)(T e1, T e2))
{
    tssnode<T> *tmp = new tssnode<T>;
    if(NULL == tmp)
        return NULL;
    tssnode<T> *cur = begin();
//    tssnode<T> *prev = cur;
    tmp->data = x;
    while(cur != end() &&
        (cmp)(cur->data,tmp->data)) {
//        prev = cur;
        cur = cur->next;
    }
    if(length == 0) {
        node->next = tmp;
        node->prev = tmp;
        tmp->next = node;
        tmp->prev = node;
    } else {
        tmp->next = cur;
        tmp->prev = cur->prev;
        cur->prev->next = tmp;
        cur->prev = tmp;
    }
    length++;
    return tmp;
}

template <class T>
void tsslist<T>::clear_list(void)
{
    tssnode<T> *tmp, *next;

    tmp = begin();
    while(tmp != end()) {
        next = tmp->next;
        erase(tmp);
        tmp = next;
    }
    length = 0;
}

template <class T>
void tsslist<T>::clear_ptr_list(void)
{
    tssnode<T> *tmp, *next;

    tmp = begin();
    while(tmp != end()) {
        next = tmp->next;
        delete tmp->data;
        erase(tmp);
        tmp = next;
    }
    length = 0;
}

template <class T>
void tsslist<T>::erase(tssnode<T> *pos)
{
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    length--;
    delete pos;
}

#endif
// end tsslist.h
