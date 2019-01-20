#include "pch.h"
#include "AnalyzeEngine.h"



AnalyzeEngine::AnalyzeEngine(){
	
	//printf("Make AnalyzeEngine\n");
}


AnalyzeEngine::~AnalyzeEngine(){
	
}

WlanPacket * AnalyzeEngine::analyze(RawData * packet, SortEngine * SE){
    //radiotap과 dot11mac 분류
    //radiotap은 radiotap에서 분석
    //dot11은 타입 찾아서 지정해준 뒤 분석 맡기기 
    
    //WlanPacket * rst = new WlanPacket(packet);
    struct ieee80211_radiotap_header * radiotapHdr = (struct ieee80211_radiotap_header *)packet->rawdata;
    struct ieee80211_frame * dot11mac = (ieee80211_frame *)(packet->rawdata+(radiotapHdr->it_len));
    //TODO 타입 찾기(Beacon, data packet, prob packet)
    //packet->printData();
    switch(dot11mac->i_fc[0]&IEEE80211_FC0_TYPE_MASK)
    {
        case IEEE80211_FC0_TYPE_MGT:
        //printf("관리 프레임\n");
        switch(dot11mac->i_fc[0]&IEEE80211_FC0_SUBTYPE_MASK){
            case IEEE80211_FC0_SUBTYPE_BEACON:
            //printf("비콘 프레임\n");
            //printf("%p\n",packet->rawdata);
            SE->pushPkt(new BeaconPacket(packet));
            
            //SE->pushPkt(rst);
            break;
            case IEEE80211_FC0_SUBTYPE_PROBE_REQ:
            //printf("프루브 요청 프레임\n");
            new ProbePacket(packet);
            break;
            case IEEE80211_FC0_SUBTYPE_PROBE_RESP:
            //printf("프루브 응답 프레임\n");
            new ProbePacket(packet);
            break;
        }
        break;
        case IEEE80211_FC0_TYPE_DATA:
        //printf("데이터 프레임\n");
        new DataPacket(packet);
        break;
        case IEEE80211_FC0_TYPE_CTL:
        //printf("제어 프레임\n");
        break;
    }
    //TODO 
    
    return nullptr;
}