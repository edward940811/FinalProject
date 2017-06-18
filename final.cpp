#include<iostream>
#include<cstring>
#include <stdio.h>
#include <string.h>
#include "final.h"
using namespace std;
BikePtr BikeOPs::NewBike ( LicenseType License, int Mile, ClassType Class, StationType Station)
{
  BikePtr newbike = new BikeType(License,Mile,Class,Station);
  InsertHeap(newbike , AllBikes);
  //fuck this
    cout<<"New bike is received by Station";
    cout<<ReturnStationName(Station)<<"."<<endl;

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
  while(AllBikes->Elem[i] != NULL )
  {
    if(strcmp(AllBikes->Elem[i]->License,License)==0)
    return AllBikes->Elem[i];
    if(compare(AllBikes->Elem[i]->License,License))
    i *= 2;
    else if(!compare(AllBikes->Elem[i]->License,License))
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
    currentheap->currentbikes++;
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
int BikeOPs::JunkBikePtr(BikePtr Bike)
{
  int i = FindBikeInHeap(AllBikes,Bike); //return the array number storing the elem
  if(i <= 0)
  {
    cout<<"Bike "<< Bike->License <<" does not belong to our company."<<endl;
    return -1;
  }
  if(Bike->IscalledbyTrans == false)
  {
    if(Bike->Status == Rented)
    {
      cout<<"Bike "<< Bike->License <<" is now being rented."<< endl;
      return -1;
    }
    cout<<"Bike "<< Bike->License <<" is deleted from "<< ReturnStationName(Bike->Station)<< endl;
    AllBikes->Elem[i] = NULL;
    AllBikes->currentbikes-=1;
    Resort(AllBikes,i);
  }
  int Station = Bike->Station;
  if(Bike->Class == 0)
  {
    int j = FindBikeInHeap(AllStations[Station].HElectric,Bike);
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
void BikeOPs::TransBikePtr (StationType Station, BikePtr Bike)
{
  if(Bike->Status == 1)
  {
    cout<<"Bike "<< Bike->License <<" is now being rented."<< endl;
    return;
  }
  int Class = Bike->Class;
  Bike->IscalledbyTrans = true;
  JunkBikePtr(Bike);
  if(Class == 0)
  {
    HeapType* stationheap = AllStations[Station].HElectric;
    InsertHeap(Bike,stationheap);
    AllStations[Station].NumElectric++;
  }
  if(Class == 1)
  {
    HeapType* stationheap = AllStations[Station].HLady;
    InsertHeap(Bike,stationheap);
    AllStations[Station].NumLady++;
  }
  if(Class == 2)
  {
    HeapType* stationheap = AllStations[Station].HRoad;
    InsertHeap(Bike,stationheap);
    AllStations[Station].NumRoad++;
  }
  if(Class == 3)
  {
    HeapType* stationheap = AllStations[Station].HHybrid;
    InsertHeap(Bike,stationheap);
    AllStations[Station].NumHybrid++;
  }
  cout<<"Bike "<<Bike->License <<" is transferred to " << ReturnStationName(Station)<<endl;
  Bike->IscalledbyTrans == false;
}
void BikeOPs::RentBikePtr (StationType Station, ClassType Class)
{
  BikePtr Bike;
  int i=1;
  int largestBike = 1;
  if(Class == 0)
  {
    if(AllStations[Station].NumElectric ==0)
    {
      cout<<" No free bike is available."<<endl;
      return;
    }
    else
    {
      int Mileage = AllStations[Station].HElectric->Elem[i]->Mileage;
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HElectric,i);
      Bike = AllStations[Station].HElectric->Elem[largestBike];
    }
  }
  if(Class == 1)
  {
    if(AllStations[Station].NumLady ==0)
    {
      cout<<" No free bike is available."<<endl;
      return;
    }
    else
    {
      int Mileage = AllStations[Station].HLady->Elem[i]->Mileage;
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HLady,i);
      Bike = AllStations[Station].HLady->Elem[largestBike];
    }
  }
  if(Class == 2)
  {
    if(AllStations[Station].NumRoad ==0)
    {
      cout<<" No free bike is available."<<endl;
      return;
    }
    else
    {
      int Mileage = AllStations[Station].HRoad->Elem[i]->Mileage;
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HRoad,i);
      Bike = AllStations[Station].HRoad->Elem[largestBike];
    }
  }
  if(Class == 3)
  {
    if(AllStations[Station].NumHybrid ==0)
    {
      cout<<" No free bike is available."<<endl;
      return;
    }
    else
    {
      int Mileage = AllStations[Station].HHybrid->Elem[i]->Mileage;
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HHybrid,i);
      Bike = AllStations[Station].HHybrid->Elem[largestBike];
    }
  }
    Bike->IscalledbyTrans = true;
    JunkBikePtr(Bike);
    HeapType* stationheap = AllStations[Station].HRent;
    InsertHeap(Bike,stationheap);
    Bike->Status = Rented;
    //cout<<stationheap->Elem[1]->License<<endl;
    cout<<"A bike is rented from "<<ReturnStationName(Station)<<"."<<endl;
}
int BikeOPs::FindLargestMileageBikeInHeap(HeapType *heap, int i)
{
  if(heap->Elem[2*i] != NULL) //left
  {
    if(heap->Elem[i]->Mileage < heap->Elem[2*i]->Mileage)
    {
        heap->largestBike = 2*i;
    }
    FindLargestMileageBikeInHeap(heap,i*2);
  }
  if(heap->Elem[2*i+1] != NULL) //right
  {
    if(heap->Elem[i]->Mileage < heap->Elem[2*i+1]->Mileage)
    {
        heap->largestBike = 2*i+1;
    }
    FindLargestMileageBikeInHeap(heap,i*2+1);
  }
  return heap->largestBike;
}
