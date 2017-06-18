#include<iostream>
#include<string>
#include "final.h"
using namespace std;
int main()
{
  BikeOPs a;
  /////for newbike
  BikePtr newbike1 =  a.NewBike("NTHU0",59,Lady,Xinpu);
  BikePtr newbike2 =  a.NewBike("NTHU1",3,Lady,Jingmei);
  BikePtr newbike3 =  a.NewBike("NTHU2",0,Lady,Jingmei);
  BikePtr newbike4 =  a.NewBike("NTHU3",1,Lady,Jingmei);
  BikePtr newbike5 =  a.NewBike("NTHU4",15,Lady,Jingmei);
  BikePtr newbike6 =  a.NewBike("NTHU5",1,Lady,Danshui);
  BikePtr newbike7 =  a.NewBike("NTHU6",3,Lady,Liuzhangli);
  BikePtr newbike8 =  a.NewBike("CSDS3",27,Road,Danshui);
  BikePtr newbike9 =  a.NewBike("CSDS4",71,Road,Muzha);
  BikePtr newbike10 =  a.NewBike("CSDS5",49,Hybrid,Danshui);
  BikePtr newbike11 =  a.NewBike("CSDS6",78,Hybrid,Liuzhangli);
  //a.TransBikePtr(Ximen,newbike4);
  // a.RentBikePtr(Ximen,newbike4);
  // a.RentBikePtr(Ximen,newbike4);
  // a.Inquire("CCCC0");
  // a.Inquire("CCCC1");
  // a.Inquire("DDDDD");
  // a.Inquire("NTHU3");
  // a.Inquire("DDDD2");
  // a.Inquire("NTHU6");
  a.StationReport(Jingmei);
  a.RentBikePtr(Jingmei,Lady);
  a.StationReport(Jingmei);
  a.UbikeReport();
  // a.JunkBikePtr(newbike2);
  // a.JunkBikePtr(newbike8);
  // a.BReport();
  // a.JunkBikePtr(newbike9);
  // a.JunkBikePtr(newbike10);
  // a.JunkBikePtr(newbike11);
  // a.JunkBikePtr(newbike11);
  // a.BReport();
  // a.JunkBikePtr(newbike1);
  // a.JunkBikePtr(newbike2);
  // a.BReport();
  // a.StationReport(Danshui);
  // //cout<<a.AllStations[0].*HLady->
  // a.TransBikePtr(Danshui,newbike1);
  // a.StationReport(Xinpu);
  // a.StationReport(Danshui);
  // a.Inquire("01023");


}
