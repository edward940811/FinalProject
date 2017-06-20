#include<iostream>
#include<cstring>
#include "final.h"
using namespace std;
void BikeOPs::Resort(HeapType* heap ,int deletednumber)
{
  //leaf
  if(heap->Elem[2*deletednumber+1] == NULL && heap->Elem[2*deletednumber] == NULL)
  return;
  //nonleaf -- only rightchild
  if(heap->Elem[2*deletednumber+1] != NULL && heap->Elem[2*deletednumber] == NULL)
  {
    ResortR(heap,deletednumber);
  }
  //have leftchild
  else if(heap->Elem[2*deletednumber] != NULL)
  {
    int i = deletednumber;
    while(1)
    {
      if(heap->Elem[2*i+1] == NULL)
      break;
      if(heap->Elem[2*i+1] != NULL)
      i = 2*i +1;
    }
    heap->Elem[deletednumber] = heap->Elem[i];
  }
}
void BikeOPs::ResortR(HeapType* heap ,int deletednumber) //調整右子樹用 shift up
{
  heap->Elem[deletednumber] = heap->Elem[2*deletednumber+1];
  int k =2*deletednumber+1;
  if(heap->Elem[2*k+1] == NULL && heap->Elem[2*k] == NULL)
  {
    heap->Elem[k] = NULL;
    return;
  }
  //left
  if(heap->Elem[2*k] != NULL)
  {
    heap->Elem[2*deletednumber] = heap->Elem[2*k];
    //heap->Elem[2*k] = NULL;
    ResortR(heap,k-1);
  }
  //right
  if(heap->Elem[2*k+1] != NULL)
  {
    heap->Elem[2*deletednumber+1] = heap->Elem[2*k+1];
    //heap->Elem[2*k+1] = NULL;
    ResortR(heap,k);
  }
}
int BikeOPs::FindBikeInHeap(HeapType* heap,BikePtr Bike)
{
  int i=1;
  while(heap->Elem[i] != NULL)
  {
    if(strcmp(heap->Elem[i]->License,Bike->License)==0)
    return i;
    else if(compare(heap->Elem[i]->License,Bike->License))
    i *= 2;
    else if(!compare(heap->Elem[i]->License,Bike->License))
    i = i*2 +1;
  }
  return -1; // not located
}
