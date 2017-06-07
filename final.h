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
  BikeType *left, *right;
  BikeType():Mileage(0),Cursor(0),left(NULL),right(NULL){}
   BikeType(LicenseType license, int Mile, ClassType aclass, StationType station)
   {
    for(int i=0; i<5 ;i++)
    License[i] = license[i];
     Mileage = Mile;
     Class = aclass;
     Station = station;
     left = NULL;
     right = NULL;
   }
  //                 License(License),Status(Free),Mileage(Mile),Cursor(0),Class(Class),Station(Station),left(NULL),right(NULL){}
};
typedef struct BikeType *BikePtr;
struct HeapType
{
  BikePtr Elem[256]; /*use array to implement heap, and each node in the heap is a pointer*/
  int Number;
  int currentbikes = 0;
  int numberfortracing = 1;
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
  HeapType HRent;
  HeapType HElectric;
  HeapType HLady;
  HeapType HRoad;
  HeapType HHybrid;
};
class BikeOPs
{
  public:
    BikePtr NewBike ( LicenseType License, int Mile, ClassType Class, StationType Station);
    BikePtr SearchBike ( LicenseType License);
    int JunkBikePtr (BikePtr Bike);
    void TransBikePtr (StationType Station, BikePtr Bike);
    void RentBikePtr (StationType Station, BikePtr Bike);
    int Returns (StationType Station, BikePtr Bike, int ReturnMile);
    void Inquire (LicenseType License);
    void StationReport (StationType Station);
    void UbikeReport();
    void NetSearch (StationType Station);
    void BReport ();
    void Main ();
    //////Heap
    void InsertHeap(BikePtr NewBike , HeapType currentheap);
    bool compare(LicenseType a, LicenseType b);
  private:
    HeapType AllBikes;
};
