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
  BikePtr newbike =  a.NewBike(test,10000,Lady,Xinpu);
  BikePtr newbike2 =  a.NewBike("00011",99,Road,Ximen);
  a.UbikeReport();
  /////////
}
