#include "pch.h"
#include "OutputEngine.h"



OutputEngine::OutputEngine(){
	
	//printf("Make OutputEngine\n");
}

OutputEngine::OutputEngine(PacketList * pktList){
	this->pktList = pktList;

}


OutputEngine::~OutputEngine(){
	
}
void OutputEngine::printScreen(){
	std::list<BeaconPacket>::iterator iter;
	system("clear");
	printf("Beacon \n");
	for (iter = pktList->BeaconList.begin(); iter != pktList->BeaconList.end(); ++iter){
		printf("%02X:%02X:%02X:%02X:%02X:%02X",iter->BSSID[0],iter->BSSID[1],iter->BSSID[2],iter->BSSID[3],iter->BSSID[4],iter->BSSID[5]);
    	printf("\t\t%s\n",iter->ESSID);
	}
	//if( pktList->BeaconList.size() > 0 )
	//pktList->BeaconList.back().printAttr();
}