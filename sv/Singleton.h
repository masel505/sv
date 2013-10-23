//
// Created by Denis on 22.10.13.
// Copyright (c) 2013 ___FULLUSERNAME___. All rights reserved.
//
#import <pthread.h>

#ifndef __Singleton_H_
#define __Singleton_H_

template <class T>
class Singleton
{
    static T* _self;
    static int _refcount;
protected:
    Singleton(){}
    virtual ~Singleton(){_self=NULL;}
public:
    static T* Instance();
    void FreeInst();
};

template <class T>
T*  Singleton<T>::_self = NULL;

template <class T>
int  Singleton<T>::_refcount=0;

template <class T>
T*  Singleton<T>::Instance()
{
    if(!_self)
        _self=new T;
    _refcount++;
    return _self;
}

template <class T>
void  Singleton<T>::FreeInst()
{
    if(--_refcount==0)
        delete this;
}

#endif //__Singleton_H_
