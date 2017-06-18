#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<climits>

#include "final.h"

using namespace std;

ofstream fileOut;
ifstream testCaseIn;
ifstream mapIn;

int main(int argc, char * argv[]) {
	if(argc!=4) {
		cout << "arguments are incorrect" << endl;
		return 0;
	}
	//argv[1] is the name of the transaction file
	//argv[2] is the name of the map file
	//argv[3] is the name of the output file
	fileOut.open(argv[3],ifstream::out);
	mapIn.open(argv[2],ifstream::in);
	testCaseIn.open(argv[1],ifstream::in);

	// init functions
	BikeOPs a;
	for( int i = 0; i < 10000; ++i ){
		a.AllBikes -> Elem[i] = NULL;
	}

	cout << "start init" << endl;
	for( int i = 0; i < 12; ++i ){
		a.map[i] = new int [12];
		for( int j = 0; j < 12; ++j ){
			a.map[i][j] = INT_MAX;
		}
	}

	//cout << "inited" << endl;

	//read map
	string s, t, dist;
	while(mapIn >> s >> t >> dist){
		int station1 = a.station_to_int(s);
		int station2 = a.station_to_int(t);

		//cout << s << " " << t << endl;

		if( station1 < 0 || station2 < 0 ){
			cout << "input undefined map" << endl;
		}
		else{
			int dst = stoi( dist );
			a.map[station1][station2] = dst;
			a.map[station2][station1] = dst;
		}
	}

	//cout << "map read" << endl;
	for(int i = 0; i < 12; ++i )
		a.map[i][i] = 0;

	//your parser about testCase
	std::string cmd;
	int d;
	char l[6];
	while(testCaseIn>>cmd){
		if(cmd=="NewBike") {
			testCaseIn >> t >> l >> d >> s;
			ClassType type = (ClassType)a.bike_to_int(t);
			StationType station = (StationType)a.station_to_int(s);

			char temp[5];

			//cout << t << " " << s << endl;

			if( type < 0 || station < 0 )
				cout << "input undefined bike" << endl;

			for( int i = 0; i < 5 ; ++i ){
				temp[i] = l[i];
				//cout << lic[i] << endl;
			}
			temp[5]='\0';

			a.NewBike( temp, d, type, station );
		}
		else if(cmd == "Inquire"){
			string lic;
			testCaseIn >> lic;
			char temp[5];
			//cout << lic << endl;
			for( int i = 0; i < 5 ; ++i ){
				temp[i] = lic[i];
				//cout << lic[i] << endl;
			}
			temp[5]='\0';
			//cout << temp << endl;
			a.Inquire( temp );
		}
		else if(cmd == "JunkIt"){
			string lic;
			testCaseIn >> lic;
			char temp[5];
			for( int i = 0; i < 5 ; ++i ){
				temp[i] = lic[i];
				//cout << lic[i] << endl;
			}
			temp[5]='\0';
			BikePtr bike = a.SearchBike( temp );
			if( bike == NULL ){
				cout<<"Bike "<< temp <<" does not belong to our company."<<endl;
			}
			else
				a.JunkBikePtr(bike);
		}
		else if(cmd == "BReport" ){
			a.BReport();
		}
		else if(cmd == "StationReport" ){
			string s;
			testCaseIn >> s;
			StationType station = (StationType)a.station_to_int(s);
			a.StationReport(station);
		}
		//output something
		//fileOut << "your output" << endl;
	}
	return 0;
}
