#pragma once

#include "IEngine.h"
#include "SortEngine.h"
#include "WlanPacket.h"

class AnalyzeEngine
{
	public:
		AnalyzeEngine();
		~AnalyzeEngine();
		WlanPacket * analyze(RawData * packet, SortEngine * SE);

};
