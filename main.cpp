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
  BikePtr newbike2 =  a.NewBike("00011",99,Road,Ximen);
  BikePtr testbike = a.SearchBike(test);
  cout<<a.AllStations[0].HElectric->Elem[1]->License<<endl;
  /////////
}
