#include "pch.h"
#include "SortEngine.h"



SortEngine::SortEngine(){
	//printf("Make SortEngine\n");
}

SortEngine::SortEngine(PacketList * pktList){
	this->pktList = pktList;
	//printf("Make SortEngine\n");
}

SortEngine::~SortEngine(){
	
}

void SortEngine::pushPkt(RawData * pkt){
	
}

void SortEngine::pushPkt(WlanPacket * pkt){
	pktList->pktList.push_back(*pkt);
}

void SortEngine::pushPkt(BeaconPacket * pkt){
	/***segment fault**/

	if(pkt->beaconHdr->length == 0) return;
	std::list<BeaconPacket>::iterator iter;
 	int cmplen;
	//printf("현재 개수 : %lu\n",pktList->BeaconList.size());
	for (iter = pktList->BeaconList.begin(); iter != pktList->BeaconList.end(); ++iter){
		if(iter->beaconHdr->length == pkt->beaconHdr->length) if(!memcmp(iter->BSSID,pkt->BSSID,6))
		{
			//return;
			//printf("---------------------------------------same!!!!!!\n");
			pktList->BeaconList.erase(iter);
			break;
			
		}
			
			
    }
	//printf("현재 개수 : %lu\n",pktList->BeaconList.size());
	pktList->BeaconList.push_back(*pkt);
}