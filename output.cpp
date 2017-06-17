#include<iostream>
#include "final.h"
using namespace std;
void BikeOPs::Inquire (LicenseType License)
{
  BikePtr Bike = SearchBike(License);
  cout<<Bike->License<<endl;
  if(!Bike)
  {
    cout<<License<<"does not belong to our company"<<endl;
  }
  else
  {
    cout<<Bike->License<<endl;
    cout<<Bike->Mileage<<endl;
    cout<<Bike->Class<<endl;
    cout<<Bike->Station<<endl;
  }
}
void BikeOPs::UbikeReport()
{
  cout<<AllBikes->Elem[3]->License<<endl;
}
