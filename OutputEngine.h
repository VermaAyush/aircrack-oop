#pragma once

#include "IEngine.h"
#include "PacketList.h"

class OutputEngine
{
	PacketList * pktList;
		//Output struct 필요할듯
	
	public:
		OutputEngine();
		OutputEngine(PacketList * pktList);
		~OutputEngine();
		//Output 함수
		void process();
		void printScreen();
		void printChannel();
};
