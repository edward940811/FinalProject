#include<iostream>
#include<string>
#include "final.h"
using namespace std;
int main()
{
  BikeOPs a;
  /////for newbike
  string s = "00000";
  char test[5];
  strcpy(test, s.c_str());
  BikePtr newbike =  a.NewBike(test,10000,Electric,Danshui);
  // s = "00012";
  // strcpy(test, s.c_str());
  // BikePtr newbike2 =  a.NewBike(test,10000,Electric,Danshui);
  BikePtr newbike3 =  a.NewBike("00011",99,Electric,Danshui);
  BikePtr testbike = a.SearchBike(test);
  cout<<a.AllStations[0].HElectric->Elem[1]->License<<endl;
  cout<<a.AllStations[0].HElectric->Elem[3]->License<<endl;
  cout<<testbike->License<<endl;
  a.JunkBikePtr(testbike);
  cout<<"after Junk: "<<endl;
  cout<<"AllBikes first element :"<<a.AllBikes->Elem[1]->License<<endl;
  cout<<"AllStations first element :"<<a.AllStations[0].HElectric->Elem[1]->License<<endl;
  /////////
}
