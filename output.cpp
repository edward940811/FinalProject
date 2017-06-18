#include<iostream>
#include "final.h"
#include<iomanip> //using setw()
using namespace std;
void BikeOPs::Inorder(HeapType* currentheap, int callingfunction) //看哪一個叫的 ＵＢＩＫＥＲＥＰＯＲＴ還是ＳＴＡＴＩＯＮＲＥＰＯＲＴ
{
  BikePtr data[1000000];
	 for( int i = 0; i < 1000000; ++i )
	 	data[i] = currentheap -> Elem[i];

  int size = currentheap->currentbikes;
  int stack[size];
  // if (size ==1)
  // size = 2;
  stack[1] = 1;
  int visited = 0;
  int stack_point = 1;
  int traverse_point = 1;
  while ( visited != size )
  {
		int traverse_point = stack[stack_point];
		if( data[ traverse_point * 2 ] != NULL )
    {
			stack[++stack_point] = traverse_point * 2;
		}
		else
    {
			if ( data[ traverse_point * 2 + 1 ] == NULL )//don't have right child
      {
        if(callingfunction == 1)
        cout << setw(12) << data[ traverse_point ] ->License << setw(12) << data[ traverse_point ] ->Mileage<< setw(12) << ReturnClassName(data[ traverse_point ] ->Class )<<setw(12)<<ReturnStationName(data[ traverse_point ] ->Station)<<endl;
        else
				cout << setw(15)<< data[ traverse_point ] -> License << setw(15)<< data[traverse_point] -> Mileage << setw(15) <<ReturnClassName(data[traverse_point]->Class) <<endl;

        data[ traverse_point ] = NULL;
				stack_point--;
				visited++;
			}
			else
      {
        if(callingfunction == 1)
        cout << setw(12) << data[ traverse_point ] ->License << setw(12) << data[ traverse_point ] ->Mileage<< setw(12) << ReturnClassName(data[ traverse_point ] ->Class) <<setw(12)<<ReturnStationName(data[ traverse_point ] ->Station)<<endl;
        else
        cout << setw(15)<< data[ traverse_point ] -> License << setw(15)<< data[traverse_point] -> Mileage << setw(15) <<ReturnClassName(data[traverse_point]->Class) <<endl;

        data[ traverse_point ] = NULL;
				stack_point--;
				visited++;
				stack[++stack_point] = traverse_point * 2 + 1;
			}
	  }
  }
}
void BikeOPs::Inquire (LicenseType License)
{
  BikePtr Bike = SearchBike(License);
  if(Bike == NULL)
  {
    cout<<"Bike "<< License <<" does not belong to our company."<<endl;
    return;
  }
  else
  {
    cout << setw(15) << "License" << setw(15) << "Mileage"<< setw(15) << "Class" <<setw(15)<<"Station"<<endl;
    for(int i=0;i<60;i++)
    cout<<"=";
    cout<<endl;
    cout << setw(15) << Bike->License << setw(15) << Bike->Mileage << setw(15) << ReturnClassName(Bike->Class) <<setw(15)<<ReturnStationName(Bike->Station)<<endl;
    cout<<endl;
  }
}
void BikeOPs::StationReport(StationType Stationnum)
{
  Station currentStation = AllStations[Stationnum];
  PrintStationName(Stationnum);
  cout<<setw(30)<<"Free Bikes"<<endl;
  cout << setw(15) << "License" << setw(15) << "Mileage"<< setw(15) << "Class"<<setw(15) << "Subtotal" <<endl;
  for(int i=0;i<60;i++)
  cout<<"=";
  cout<<endl;
  int total = 0;
  HeapType *currentheap;
  currentheap = currentStation.HElectric;
  total += currentheap->currentbikes;
  Inorder(currentheap,0);
  currentheap = currentStation.HLady;
  total += currentheap->currentbikes;
  Inorder(currentheap,0);
  currentheap = currentStation.HRoad;
  total += currentheap->currentbikes;
  Inorder(currentheap,0);
  currentheap = currentStation.HHybrid;
  total += currentheap->currentbikes;
  Inorder(currentheap,0);

  for(int i=0;i<60;i++)
  cout<<"=";
  cout<<endl;
  cout<< setw(60) << total <<endl;
  cout<<setw(30)<<"Rented Bikes"<<endl;
  cout << setw(15) << "License" << setw(15) << "Mileage"<< setw(15) << "Class" <<setw(15) << "Subtotal" <<endl;
  for(int i=0;i<60;i++)
  cout<<"=";
  cout<<endl;
  currentheap = currentStation.HRent;
  total = currentheap->currentbikes;
  Inorder(currentheap,0);
  for(int i=0;i<60;i++)
  cout<<"=";
  cout<<endl;
  cout<<setw(60)<<total<<endl;

}

void BikeOPs::PrintStationName(int number)
{
  int Station = number;
  if(Station == 0)
  cout<<setw(30)<<"Danshui"<<endl;
  if(Station == 1)
  cout<<setw(30)<<"Hongshulin "<<endl;
  if(Station == 2)
  cout<<setw(30)<<"Shilin"<<endl;
  if(Station == 3)
  cout<<setw(30)<<"Beitou"<<endl;
  if(Station == 4)
  cout<<setw(30)<<"Zhongshan"<<endl;
  if(Station == 5)
  cout<<setw(30)<<"Xinpu"<<endl;
  if(Station == 6)
  cout<<setw(30)<<"Ximen"<<endl;
  if(Station == 7)
  cout<<setw(30)<<"Liuzhangli"<<endl;
  if(Station == 8)
  cout<<setw(30)<<"Muzha"<<endl;
  if(Station == 9)
  cout<<setw(30)<<"Guting"<<endl;
  if(Station == 10)
  cout<<setw(30)<<"Gongguan"<<endl;
  if(Station == 11)
  cout<<setw(30)<<"Jingmei"<<endl;
}

void BikeOPs::BReport( void )
{
	HeapType* temp = AllBikes;
	BikePtr data[100000];

	for( int i = 0; i < 100000; ++i ){
		data[i] = temp -> Elem[i];
	}

	int visited = 0;
	int size = temp -> currentbikes;
	// inorder traverse
	int stack[size];
  stack[1] = 1;
	int stack_point = 1;
  bool dontmindthis = false;
	cout << "Binary Search Tree" << endl;
	while (stack_point != 0)
  {
		int traverse_point = stack[stack_point--];
    if(!dontmindthis)
    {
      cout<<data[traverse_point]->License;
      dontmindthis = true;
    }
    else if(dontmindthis == true)
		{
      cout << "->" << data[ traverse_point ] -> License;
    }
		if( data[ traverse_point * 2 + 1 ] != NULL ) //have right child
    {
			stack[++stack_point] = traverse_point * 2 + 1;
		}
		if( data[ traverse_point * 2 ] != NULL ) // have left child
    {
			stack[++stack_point] = traverse_point * 2;
		}
	}
  cout<<endl;
	stack[1] = 1;
	stack_point = 1;
	//cout << "inorder traverse" << endl;
  bool dontmindthis2 =false;
	while ( visited != size )
  {
		int traverse_point = stack[stack_point];
		// if left node exists, push node into stack and go to the left node
		// assumption here : uninserted nodes are pointer that points to NULL ^^
		if( data[ traverse_point * 2 ] != NULL )
    {
			stack[++stack_point] = traverse_point * 2;
		}
		else
    {
			if ( data[ traverse_point * 2 + 1 ] == NULL )//don't have right child
      {
        if(dontmindthis2 == false)
        {
				 cout <<  data[ traverse_point ] -> License ;
         dontmindthis2 = true;
        }
        else
          cout << "->" << data[ traverse_point ] -> License ;
        data[ traverse_point ] = NULL;
				stack_point--;
				visited++;
			}
			else
      {
        if(dontmindthis2 == false)
        {
         cout <<  data[ traverse_point ] -> License ;
         dontmindthis2 = true;
        }
        else
          cout << "->" << data[ traverse_point ] -> License ;
				data[ traverse_point ] = NULL;
				stack_point--;
				visited++;
				stack[++stack_point] = traverse_point * 2 + 1;
			}
	  }
  }
  cout<<endl;
}
void BikeOPs::UbikeReport()
{
  cout << setw(12) << "License" << setw(12) << "Mileage"<< setw(12) << "Class" <<setw(12)<<"Station"<<setw(12)<<"Total"<<endl;
  for(int i=0;i<60;i++)
  cout<<"=";
  cout<<endl;
  Inorder(AllBikes,1);
  for(int i=0;i<60;i++)
  cout<<"=";
  cout<<endl;
}
string BikeOPs::ReturnStationName(int Station)
{
  string s;
    if(Station == 0)
    s = "Danshui";
    if(Station == 1)
    s = "Hongshulin ";
    if(Station == 2)
    s = "Shilin";
    if(Station == 3)
    s = "Beitou";
    if(Station == 4)
    s = "Zhongshan";
    if(Station == 5)
    s = "Xinpu";
    if(Station == 6)
    s = "Ximen";
    if(Station == 7)
    s = "Liuzhangli";
    if(Station == 8)
    s = "Muzha";
    if(Station == 9)
    s = "Guting";
    if(Station == 10)
    s = "Gongguan";
    if(Station == 11)
    s = "Jingmei";
    return s;
}
string BikeOPs::ReturnClassName(int Class)
{
  string s;
  if(Class == 0)
  s = "Electric";
  if(Class == 1)
  s = "Lady";
  if(Class == 2)
  s = "Road";
  if(Class == 3)
  s = "Hybrid";
  return s;
}

void BikeOPs::NetSearch( string Station ){
	int temp = station_to_int( Station );
	cout << Station << "\n===============" << endl;
	cout << "Electric " << AllStations[ temp ].NetElectric << endl;
	cout << "NetLady " << AllStations[ temp ].NetLady << endl;
	cout << "NetRoad " << AllStations[ temp ].NetRoad << endl;
	cout << "NetHybrid " << AllStations[ temp ].NetHybrid << endl;
	cout << "Total " << AllStations[ temp ].Net << endl;
}
