#include "pch.h"
#include "OutputEngine.h"

std::mutex mtx;

OutputEngine::OutputEngine(){
	
	//printf("Make OutputEngine\n");
}

OutputEngine::OutputEngine(PacketList * pktList){
	this->pktList = pktList;
	OutputEngine();
}


OutputEngine::~OutputEngine(){
	
}

void OutputEngine::printChannel(){
	while(1){
		mtx.lock();
		printf("%c[%d;%df",0x1b,0,0);
		printf("CH : %s",pktList->channel);
		mtx.unlock();
		usleep(1000);
	}
	;
}

void OutputEngine::printScreen(){
	std::list<BeaconPacket>::iterator iter;
	printf("%c[%d;%df",0x1b,2,0);
	printf("Beacon \n");
	printf("BSSID\t\t   PWR\tBeacons\t#Data\t  CH   MB  ENC   CIPHER  AUTH  ESSID\n");
	for (iter = pktList->BeaconList.begin(); iter != pktList->BeaconList.end(); ++iter){
		printf("%02X:%02X:%02X:%02X:%02X:%02X",iter->BSSID[0],iter->BSSID[1],iter->BSSID[2],iter->BSSID[3],iter->BSSID[4],iter->BSSID[5]);
    	printf("%5d", 0);
		printf("\t%7d", 0);
		printf("\t%5d", 0);
		printf("\t%4d",iter->radiotap.getchennel());
		printf("%5d",0);
		printf("  %-4s",iter->encrypt);
		printf("  %-4s",iter->CIPHER);
		printf("    %-4s",iter->AUTH);
		printf("  %s",iter->ESSID);
		printf("\n");	
	}
	//if( pktList->BeaconList.size() > 0 )
	//pktList->BeaconList.back().printAttr();
}

void OutputEngine::process(){
	while(1){
		usleep(1000);
		mtx.lock();
		system("clear");
		printScreen();
		mtx.unlock();
		
		
	}
	
}