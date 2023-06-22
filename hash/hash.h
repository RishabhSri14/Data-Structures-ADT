
#ifndef _HASH_H

#define _HASH_H

typedef struct node Node;
typedef Node* PtrToNode;
typedef struct Ht Ht;
typedef Ht* PtrToHt;
typedef struct StrNode StrNode;
typedef StrNode* PtrToStrNode;
typedef struct StrHt StrHt;
typedef StrHt* PtrToStrHt;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    long int n;
    PtrToNode next;
};

struct Ht
{
    long long int table_size;
    PtrToNode* arr;
};



struct StrNode
{
    char* data;
    PtrToStrNode next;
};

struct StrHt
{
    long long int table_size;
    PtrToStrNode* arr;
};
//Q1
long long int gethash(long int x,long long int table_size);
PtrToNode InitNode(long int n);
PtrToHt InitHashing(long long int table_size);
void insertSepChain(long int x,PtrToHt ht);  
void insertQuadProb(long int x,PtrToHt ht);
void insertLinProb(long int x,PtrToHt ht);
int findSepChain(long int x,PtrToHt ht);  
int findQuadProb(long int x,PtrToHt ht);
int findLinProb(long int x,PtrToHt ht);


//Q2
PtrToStrNode InitStrNode(char*ch);
PtrToStrHt InitStrHashing(long long int table_size);
long int GetStrHash(char*ch,long long int table_size);
bool existSep(char*ch,PtrToStrHt dict);
void insertStr(char*ch,PtrToStrHt dict);

//Q3
long long int GetStringHash(char ch[],long long int table_size);
long long int getExtendedHash(char a[],int l,int index,long long int pind,long long int power);

#endif
