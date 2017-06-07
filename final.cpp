#include<iostream>
#include "final.h"
using namespace std;
BikePtr BikeOPs::NewBike ( LicenseType License, int Mile, ClassType Class, StationType Station)
{
  BikePtr newbike = new BikeType(License,Mile,Class,Station);
  return newbike;
  ///insertHeap
  //InsertHeap(newbike);
}
BikePtr BikeOPs::SearchBike(LicenseType License)
{
  ///SearchBike
}
