/*************************************************************************
	> File Name: linklist.h
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 07 Nov 2020 06:54:16 PM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) (long long)(&((T*)(NULL))->name)
#define Head(p, T, name) (T*)((char* )(p) - offset(T, name))

struct LinkNode {
   struct LinkNode* next;
};

#endif
