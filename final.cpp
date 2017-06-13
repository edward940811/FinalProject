#include<iostream>
#include "final.h"
using namespace std;
BikePtr BikeOPs::NewBike ( LicenseType License, int Mile, ClassType Class, StationType Station)
{
  BikePtr newbike = new BikeType(License,Mile,Class,Station);
  InsertHeap(newbike , AllBikes);
  //Danshui, Hongshulin, Beitou, Shilin, Zhongshan, Xinpu, Ximen, Liuzhangli, Muzha, Guting, Gongguan, Jingmei
  if(Class == 0)
  {
    HeapType* stationheap = AllStations[Station].HElectric;
    InsertHeap(newbike,stationheap);
    AllStations[Station].NumElectric++;
  }
  if(Class == 1)
  {
    HeapType* stationheap = AllStations[Station].HLady;
    InsertHeap(newbike,stationheap);
    AllStations[Station].NumLady++;
  }
  if(Class == 2)
  {
    HeapType* stationheap = AllStations[Station].HRoad;
    InsertHeap(newbike,stationheap);
    AllStations[Station].NumRoad++;
  }
  if(Class == 3)
  {
    HeapType* stationheap = AllStations[Station].HHybrid;
    InsertHeap(newbike,stationheap);
    AllStations[Station].NumHybrid++;
  }
  return newbike;
}
BikePtr BikeOPs::SearchBike(LicenseType License)
{
  int i=1;
  while(i <= AllBikes->currentbikes)
  {
    if(strcmp(AllBikes->Elem[i]->License,License)==0)
    return AllBikes->Elem[i];
    if(compare(AllBikes->Elem[i]->License,License))
    i *= 2;
    if(!compare(AllBikes->Elem[i]->License,License))
    i = i*2 +1;
  }
  return NULL;
}
bool BikeOPs::compare(LicenseType a, LicenseType b) //前面大傳真 後面大傳假
{
  for(int i=0;i<5;i++)
  {
    if(a[i]>b[i])
    return true;
    if(a[i]<b[i])
    return false;
  }
}
void BikeOPs::InsertHeap(BikePtr newbike, HeapType* currentheap)
{
  if(currentheap->currentbikes == 0)
  {
    currentheap->Elem[1] = newbike;
    currentheap->currentbikes++;
    return;
  }
  if(currentheap->Elem[currentheap->numberfortracing] == NULL)
  {
    currentheap->Elem[currentheap->numberfortracing] = newbike;
    currentheap->numberfortracing = 1;
    return;
  }
  if(compare(currentheap->Elem[currentheap->numberfortracing]->License,newbike->License)) //smaller
  {
    currentheap->numberfortracing *= 2;
    InsertHeap(newbike,currentheap);
  }
  if(!compare(currentheap->Elem[currentheap->numberfortracing]->License,newbike->License)) // larger
  {
    currentheap->numberfortracing = 2 * currentheap->numberfortracing + 1;
    InsertHeap(newbike,currentheap);
  }
}
void BikeOPs::UbikeReport()
{
  cout<<AllBikes->Elem[3]->License<<endl;
}
int BikeOPs::JunkBikePtr(BikePtr Bike)
{
  int i = FindBikeInHeap(AllBikes,Bike); //return the array number storing the elem
  if(i <= 0)
  return -1;

  AllBikes->Elem[i] = NULL;
  AllBikes->currentbikes-=1;
  Resort(AllBikes,i);
  int Station = Bike->Station;
  if(Bike->Class == 0)
  {
    int j = FindBikeInHeap(AllStations[Station].HElectric,Bike);
    cout<<j<<endl;
    AllStations[Station].HElectric->Elem[j] = NULL;
    AllStations[Station].HElectric->currentbikes -= 1;
    Resort(AllStations[Station].HElectric,j);
    return 0;
  }
  if(Bike->Class == 1)
  {
    int j = FindBikeInHeap(AllStations[Station].HLady,Bike);
    AllStations[Station].HLady->Elem[j] = NULL;
    AllStations[Station].HLady->currentbikes -= 1;
    Resort(AllStations[Station].HLady,j);
    return 0;
  }
  if(Bike->Class == 2)
  {
    int j = FindBikeInHeap(AllStations[Station].HRoad,Bike);
    AllStations[Station].HRoad->Elem[j] = NULL;
    AllStations[Station].HRoad->currentbikes -= 1;
    Resort(AllStations[Station].HRoad,j);
    return 0;
  }
  if(Bike->Class == 3)
  {
    int j = FindBikeInHeap(AllStations[Station].HHybrid,Bike);
    AllStations[Station].HHybrid->Elem[j] = NULL;
    AllStations[Station].HHybrid->currentbikes -= 1;
    Resort(AllStations[Station].HHybrid,j);
    return 0;
  }
  return 0;
}
void BikeOPs::Inquire (LicenseType License)
{
  BikePtr Bike = SearchBike(License);
  cout<<Bike->License<<endl;
  // if(!Bike)
  // {
  //   cout<<License<<"does not belong to our company"<<endl;
  // }
  // else
  // {
  //   cout<<Bike->License<<endl;
  //   cout<<Bike->Mileage<<endl;
  //   cout<<Bike->Class<<endl;
  //   cout<<Bike->Station<<endl;
  // }
}
