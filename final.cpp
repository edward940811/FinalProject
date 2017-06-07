#include<iostream>
#include "final.h"
using namespace std;
BikePtr BikeOPs::NewBike ( LicenseType License, int Mile, ClassType Class, StationType Station)
{
  BikePtr newbike = new BikeType(License,Mile,Class,Station);
  InsertHeap(newbike , AllBikes);
  return newbike;
  ///insertHeap
  //InsertHeap(newbike);
}
BikePtr BikeOPs::SearchBike(LicenseType License)
{
  ///SearchBike
}
bool BikeOPs::compare(LicenseType a, LicenseType b)
{
  for(int i=0;i<5;i++)
  {
    if(a[i]>b[i])
    return true;
    if(a[i]<b[i])
    return false;
  }
}
void BikeOPs::InsertHeap(BikePtr newbike, HeapType currentheap)
{
  if(currentheap.currentbikes == 0)
  {
    currentheap.Elem[1] = newbike;
    currentheap.currentbikes++;
    return;
  }
  if(currentheap.currentbikes < currentheap.numberfortracing)
  {
    currentheap.Elem[currentheap.numberfortracing] = newbike;
    currentheap.numberfortracing = 0;
    return;
  }
  if(compare(currentheap.Elem[currentheap.numberfortracing]->License,newbike->License)) //smaller
  {
    currentheap.numberfortracing *= 2;
    InsertHeap(newbike,currentheap);
  }
  if(!compare(currentheap.Elem[currentheap.numberfortracing]->License,newbike->License)) // larger
  {
    currentheap.numberfortracing = 2 * currentheap.numberfortracing + 1;
    InsertHeap(newbike,currentheap);
  }
}
