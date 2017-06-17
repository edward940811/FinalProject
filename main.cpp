#include<iostream>
#include<string>
#include "final.h"
using namespace std;
int main()
{
  BikeOPs a;
  /////for newbike
  BikePtr newbike1 =  a.NewBike("NTHU0",59,Lady,Xinpu);
  BikePtr newbike2 =  a.NewBike("NTHU1",3,Lady,Danshui);
  BikePtr newbike3 =  a.NewBike("NTHU2",0,Lady,Danshui);
  BikePtr newbike4 =  a.NewBike("NTHU3",1,Lady,Danshui);
  BikePtr newbike5 =  a.NewBike("NTHU4",15,Lady,Danshui);
  BikePtr newbike6 =  a.NewBike("NTHU5",20,Lady,Jingmei);
  BikePtr newbike7 =  a.NewBike("NTHU6",3,Lady,Jingmei);
  a.TransBikePtr(Ximen,newbike4);
  a.RentBikePtr(Ximen,newbike4);
  a.RentBikePtr(Ximen,newbike4);
  // a.Inquire("NTHU6");
  // a.Inquire("NTHU3");
  // a.Inquire("01023");

  // string s = "00000";
  // char test[5];
  // strcpy(test, s.c_str());
  // BikePtr testbike = a.SearchBike(test);
  // cout<<a.AllStations[0].HElectric->Elem[1]->License<<endl;
  // cout<<a.AllStations[0].HElectric->Elem[3]->License<<endl;
  // a.JunkBikePtr(testbike);
   cout<<a.AllStations[6].HLady->Elem[1]->License<<endl;
  // cout<<"AllBikes third element :"<<a.AllBikes->Elem[1]->License<<a.AllBikes->Elem[3]->License<<a.AllBikes->Elem[7]->License<<endl;
  // cout<<"AllStations first element :"<<a.AllStations[0].HLady->Elem[1]->License<<endl;

}
