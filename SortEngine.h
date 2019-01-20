#pragma once

#include "pch.h"
#include "IEngine.h"

#include "PacketType.h"
#include "PacketList.h"

class SortEngine
{
	PacketList * pktList;
	public:
		SortEngine();
		SortEngine(PacketList * pktList);
		~SortEngine();
		
		void pushPkt(RawData * rawPkt);
		void pushPkt(WlanPacket * pkt);
		void pushPkt(BeaconPacket * pkt);
		
};
