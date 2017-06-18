#include<iostream>
#include "final.h"
#include <cstring>
#include <climits>

using namespace std;
BikePtr BikeOPs::NewBike ( LicenseType License, int Mile, ClassType Class, StationType Station)
{
  BikePtr newbike = new BikeType(License,Mile,Class,Station);
  InsertHeap(newbike , AllBikes);
  //fuck this
    cout<<" New bike is received by Station ";
    cout<<ReturnStationName(Station)<<endl;

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
  while( AllBikes->Elem[i] != NULL )
  {
	//cout <<AllBikes->Elem[i]->License << " "<< License << endl;
    if(strcmp(AllBikes->Elem[i]->License,License)==0)
		return AllBikes->Elem[i];
    else if(compare(AllBikes->Elem[i]->License,License))
		i *= 2;
    else if(!compare(AllBikes->Elem[i]->License,License))
		i = i*2 +1;
	//cout <<"   "<< i << endl;
	//if( i > 255 ) return NULL;
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
  if(Bike->IscalledbyTrans == false)
  {
    if(Bike->Status == 1)
    {
      cout<<"Bike "<< Bike->License <<" is now being rented."<< endl;
      return -1;
    }
    AllBikes->Elem[i] = NULL;
    AllBikes->currentbikes-=1;
    Resort(AllBikes,i);
    cout<<"Bike "<< Bike->License <<" is deleted from "<< ReturnStationName(Bike->Station)<< endl;
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
  if(SearchBike(Bike->License) == NULL)
  {
    cout<<"Bike "<< Bike->License <<" does not belong to our company."<<endl;
    return ;
  }
  int Class = Bike->Class;
  Bike->IscalledbyTrans == true;
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
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HElectric,i,largestBike);
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
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HLady,i,largestBike);
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
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HRoad,i,largestBike);
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
      largestBike = FindLargestMileageBikeInHeap(AllStations[Station].HHybrid,i,largestBike);
      Bike = AllStations[Station].HHybrid->Elem[largestBike];
    }
  }
    Bike->IscalledbyTrans = true;
    JunkBikePtr(Bike);
    Bike->Status = Rented;
    HeapType* stationheap = AllStations[Station].HRent;
    InsertHeap(Bike,stationheap);
    cout<<"A bike is rented from "<<ReturnStationName(Station)<<"."<<endl;
}
int BikeOPs::FindLargestMileageBikeInHeap(HeapType *heap, int i, int largestBike)
{
  if(heap->Elem[2*i] != NULL) //left
  {
    if(heap->Elem[i]->Mileage < heap->Elem[2*i]->Mileage)
    {
        largestBike = 2*i;
    }
    i = i*2;
    FindLargestMileageBikeInHeap(heap,i,largestBike);
  }
  if(heap->Elem[2*i+1] != NULL) //right
  {
    if(heap->Elem[i]->Mileage < heap->Elem[2*i+1]->Mileage)
    {
        largestBike = 2*i+1;
    }
    i = i*2+1;
    FindLargestMileageBikeInHeap(heap,i,largestBike);
  }
  return largestBike;
}

// ------------------------------------------------------------------
/*
void BikeOPs::BReport( void ){
	HeapType* temp = AllBikes;
	BikePtr data[256];

	for( int i = 0; i < 256; ++i ){
		data[i] = temp -> Elem[i];
	}

	int visited = 0;
	int size = temp -> currentbikes;

	// inorder traverse
	int stack[size] = {1};
	int stack_point = 1;

	cout << "preorder traverse" << endl;
	while ( visited != size ){
		int traverse_point = stack[--stack_point];
		cout << temp -> Elem[ traverse_point ] -> License << " ";
		if( data[ traverse_point * 2 + 1 ] != NULL ){
			stack[++stack_point] = traverse_point * 2 + 1;
		}
		if( data[ traverse_point * 2 ] != NULL ){
			stack[++stack_point] = traverse_point * 2;
		}
	}

	for( int i = 0; i < 256; ++i ){
		data[i] = temp -> Elem[i];
	}
	stack[0] = 1;
	stack_point = 0;

	cout << "inorder traverse" << endl;
	while ( visited != size ){
		int traverse_point = stack[stack_point];
		// if left node exists, push node into stack and go to the left node
		// assumption here : uninserted nodes are pointer that points to NULL ^^
		if( data[ traverse_point * 2 ] != NULL ){
			stack[++stack_point] = traverse_point * 2;
		}
		else{
			if ( data[ traverse_point * 2 + 1 ] == NULL ){
				// pop out the leaf node ( and print it )
				cout << temp -> Elem[ traverse_point ] -> License << " ";
				data[ traverse_point ] = NULL;
				stack_point--;
				visited++;
			}
			else{
				cout << temp -> Elem[ traverse_point ] -> License << " ";
				data[ traverse_point ] = NULL;
				stack_point--;
				visited++;
				stack[++stack_point] = traverse_point * 2 + 1;
			}
		}
	}
}
*/
int BikeOPs::shortest( StationType Station1, StationType Station2 ){
	int temp[12];
	bool finish[12];
	int count = 1;
	for( int i = 0; i < 12; i++ ){
		finish[i] = ( i == Station1 )? false : true;
		temp[i] = map[Station1][i];
	}
	do{
		for( int i = 0; i < 12; i++ ){
			if( finish[i] && temp[i] < INT_MAX ){
				for( int j = 0; j < 12; j++ ){
					if( ( map[i][j] + temp[i] ) < temp[j] )
						temp[j] = map[i][j] + temp[i];
				}
				count++;
			}
		}
	}while( count != 12 );

	return temp[Station2];
}

int BikeOPs::Returns (StationType Station, BikePtr Bike, int ReturnMile){
	Bike -> Mileage = ReturnMile;
	Bike -> Status = Free;
	int deletednumber = FindBikeInHeap( AllStations[ Bike -> Station ].HRent , Bike );
	if( deletednumber > -1 ) Resort( AllStations[ Bike -> Station ].HRent , deletednumber);
	else { cout << "this bike have false identities !! " << endl; }
	ClassType Class = Bike -> Class;
	int Station_ = Bike -> Station;
	int length = shortest( Bike -> Station, Station );

	if(Class == 0)
	{
		HeapType* stationheap = AllStations[Station_].HElectric;
		InsertHeap(Bike,stationheap);
		AllStations[Station_].NumElectric++;
		if( ReturnMile > length ){
			AllStations[ Bike->Station].Net += 40*ReturnMile;
			AllStations[ Bike->Station].NetElectric += 40*ReturnMile;
			cout << "Rental charge for this bike is " << 40*ReturnMile << endl;
		}
		else {
			AllStations[ Bike->Station].Net += 30*ReturnMile;
			AllStations[ Bike->Station].NetElectric += 30*ReturnMile;
			cout << "Rental charge for this bike is " << 30*ReturnMile << endl;
		}
	}
	if(Class == 1)
	{
		HeapType* stationheap = AllStations[Station_].HLady;
		InsertHeap(Bike,stationheap);
		AllStations[Station_].NumLady++;
		if( ReturnMile > length ){
			AllStations[ Bike->Station].Net += 30*ReturnMile;
			AllStations[ Bike->Station].NetLady += 30*ReturnMile;
			cout << "Rental charge for this bike is " << 30*ReturnMile << endl;
		}
		else {
			AllStations[ Bike->Station].Net += 25*ReturnMile;
			AllStations[ Bike->Station].NetLady += 25*ReturnMile;
			cout << "Rental charge for this bike is " << 25*ReturnMile << endl;
		}
	}
	if(Class == 2)
	{
		HeapType* stationheap = AllStations[Station_].HRoad;
		InsertHeap(Bike,stationheap);
		AllStations[Station_].NumRoad++;
		if( ReturnMile > length ){
			AllStations[ Bike->Station].Net += 20*ReturnMile;
			AllStations[ Bike->Station].NetRoad += 20*ReturnMile;
			cout << "Rental charge for this bike is " << 20*ReturnMile << endl;
		}
		else {
			AllStations[ Bike->Station].Net += 15*ReturnMile;
			AllStations[ Bike->Station].NetRoad += 15*ReturnMile;
			cout << "Rental charge for this bike is " << 15*ReturnMile << endl;
		}
	}
	if(Class == 3)
	{
		HeapType* stationheap = AllStations[Station_].HHybrid;
		InsertHeap(Bike,stationheap);
		AllStations[Station_].NumHybrid++;
		if( ReturnMile > length ){
			AllStations[ Bike->Station].Net += 25*ReturnMile;
			AllStations[ Bike->Station].NetHybrid += 25*ReturnMile;
			cout << "Rental charge for this bike is " << 25*ReturnMile << endl;
		}
		else {
			AllStations[ Bike->Station].Net += 20*ReturnMile;
			AllStations[ Bike->Station].NetHybrid += 20*ReturnMile;
			cout << "Rental charge for this bike is " << 20*ReturnMile << endl;
		}
	}
}

int BikeOPs::station_to_int( string Station ){
	if ( !Station.compare("Danshui" ) ){
		return 0;
	}
	else if ( !Station.compare("Hongshulin" ) ){
		return 1;
	}

	else if ( !Station.compare("Beitou" ) ){
		return 2;
	}
	else if ( !Station.compare("Shilin" ) ){
		return 3;
	}
	else if ( !Station.compare("Zhongshan" ) ){
		return 4;
	}
	else if ( !Station.compare("Xinpu" ) ){
		return 5;
	}
	else if ( !Station.compare("Ximen" ) ){
		return 6;
	}
	else if ( !Station.compare("Liuzhangli" ) ){
		return 7;
	}
	else if ( !Station.compare("Muzha" ) ){
		return 8;
	}
	else if ( !Station.compare("Guting" ) ){
		return 9;
	}
	else if ( !Station.compare("Gongguan" ) ){
		return 10;
	}
	else if ( !Station.compare("Jingmei" ) ){
		return 11;
	}
	else{
		return -1;
	}
};

int BikeOPs::bike_to_int( string Bike ){
	if ( !Bike.compare("Electric" ) ){
		return 0;
	}
	else if ( !Bike.compare("Lady" ) ){
		return 1;
	}
	else if ( !Bike.compare("Road" ) ){
		return 2;
	}
	else if ( !Bike.compare("Hybrid" ) ){
		return 3;
	}
	else{
		return -1;
	}
}
