#include<iostream>
using namespace std;

enum StatusType {Free, Rented};
enum ClassType { Electric, Lady, Road, Hybrid};
enum StationType {
Danshui, Hongshulin, Beitou, Shilin, Zhongshan, Xinpu,
Ximen, Liuzhangli, Muzha, Guting, Gongguan, Jingmei };
typedef char LicenseType[5];
struct BikeType
{
  LicenseType License;
  StatusType Status;
  int Mileage; /* most recently rented mileage */
  int Cursor; /* cursor to the entry in heap where there is a pointer to this node */
  StationType Station;
  ClassType Class;
  bool IscalledbyTrans = false;
  bool IscalledbyRent = false;
  bool IscalledbyReturn = false;
  int currentStation;
  BikeType():Mileage(0),Cursor(0){}
   BikeType(LicenseType license, int Mile, ClassType aclass, StationType station)
   {
    for(int i=0; i<5 ;i++)
    License[i] = license[i];
     Mileage = Mile;
     Class = aclass;
     Station = station;
   }
};
typedef struct BikeType *BikePtr;
struct HeapType
{
  BikePtr Elem[10000000]; /*use array to implement heap, and each node in the heap is a pointer*/
  int Number;
  int currentbikes;
  int numberfortracing;
  HeapType():Number(0),currentbikes(0),numberfortracing(1){}
};
struct Station
{
  int Net; /* total income of station */
  int NetElectric;
  int NetLady;
  int NetRoad;
  int NetHybrid;
  int NumElectric; /* number of electric bikes */
  int NumLady; /* number of lady bikes */
  int NumRoad; /* number of road bikes */
  int NumHybrid; /* number of hybrid bikes */
  HeapType *HRent;
  HeapType *HElectric;
  HeapType *HLady;
  HeapType *HRoad;
  HeapType *HHybrid;
  Station():Net(0)
  {
    HRent = new HeapType;
    HElectric = new HeapType;
    HLady = new HeapType;
    HRoad = new HeapType;
    HHybrid = new HeapType;
  }
};
class BikeOPs
{
  public:
    BikePtr NewBike ( LicenseType License, int Mile, ClassType Class, StationType Station);
    BikePtr SearchBike ( LicenseType License);
    int JunkBikePtr (BikePtr Bike);
    void TransBikePtr (StationType Station, BikePtr Bike);
    void RentBikePtr (StationType Station, ClassType Class);
    int Returns (StationType Station, BikePtr Bike, int ReturnMile);
    void Inquire (LicenseType License);
    void StationReport (StationType Station);
    void UbikeReport();
    void NetSearch (StationType Station);
    void BReport ( void );
    void Main ();
    //////Heap
    void InsertHeap(BikePtr NewBike , HeapType* currentheap);
    bool compare(LicenseType a, LicenseType b);
    int FindBikeInHeap(HeapType* heap,BikePtr bike);
    int FindLargestMileageBikeInHeap(HeapType *heap, int i , int largestBike);
    void Resort(HeapType* heap,int deletednumber);
    void ResortR(HeapType* heap,int number);
    void PrintStationName(int number);
    void Inorder(HeapType *currentheap, int callingfunction);
    string ReturnStationName(int Station);
    HeapType* AllBikes = new HeapType;
    Station* AllStations = new Station [12]; //用數字代替站名
    string ReturnClassName(int Class);

	// -------------------------------------------------------------------------------------------
	int station_to_int( string Station );
	int bike_to_int( string Bike );
	int shortest( StationType Station1, StationType Station2 );  //find shortest path
	// -------------------------------------------------------------------------------------------

	// -------------------------------------------------------------------------------------------
	//distance map
	int** map = new int* [12];
    // -------------------------------------------------------------------------------------------

	void NetSearch( string Station );
};
