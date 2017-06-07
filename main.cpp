#include<iostream>
#include<string>
#include "final.h"
using namespace std;
int main()
{
  BikeOPs a;
  /////for newbike
  string s = "abcde";
  char test[5];
  strcpy(test, s.c_str());
  BikePtr newbike =  a.NewBike(test,10000,Lady,Xinpu);
  /////////

}
