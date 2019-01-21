#include "BeaconPacket.h"



BeaconPacket::BeaconPacket(){

}

BeaconPacket::BeaconPacket(RawData * pkt){
    len = pkt->len;
    rawdata = pkt->rawdata;
    radiotap.hdr = (struct ieee80211_radiotap_header *)pkt->rawdata;
    dot11mac.hdr = (ieee80211_frame *)(pkt->rawdata+(radiotap.hdr->it_len));
    analyze();
}

BeaconPacket::~BeaconPacket(){

}

void BeaconPacket::analyze(){

    //printf("\n---------------analyze beacon frame\n");
    bodyLen = len;
    bodyPtr = rawdata;
    //printData();
    beaconHdr = (BEACON_FRAME *)((u_int8_t *)dot11mac.hdr + 0x18);
    /*get channel*/
    /*Get BSSID*/
    memcpy(BSSID,dot11mac.hdr->i_addr3,6);
    //printf("BSSID : %02X:%02X:%02X:%02X:%02X:%02X\n",BSSID[0],BSSID[1],BSSID[2],BSSID[3],BSSID[4],BSSID[5]);
    /*Get ESSID*/
    bodyPtr = (u_int8_t * )beaconHdr+12;
    bodyLen -= radiotap.hdr->it_len + 0x18 + 12;

    //printf("length of ESSID : %d\n", *(bodyPtr+1));
    memset(ESSID,0,33);
    memcpy(ESSID,bodyPtr+2,*(bodyPtr+1));
    //printf("ESSID : %s\n",ESSID);
    while(nextfield()){
        //printf("ID : %u , size : %u\n", fieldHdrPtr->ID, fieldHdrPtr->size);
        
        if(fieldHdrPtr->ID == 48){
            //printf("RSN\n");
            //printf("version : %d\n", *(u_int16_t *)(bodyPtr+2));
            //printf("Group cipher suit selector 4byte\n\t");
            //printHex(bodyPtr+4,4);
            //printf("cipher suit count 2byte\n\t");
            //printHex(bodyPtr+8,2);
            int i;
            u_int8_t * tmpPtr;
            for(i =0; i < *(u_int16_t *)(bodyPtr+8);i++){
                //printf("pairwise cipher suit selector 4byte\n\t");
                //printHex(bodyPtr+10+i*4,4);
                if(*(bodyPtr+10+i*4+3)==4){
                    memcpy(CIPHER,"CCMP",5);
                }
                else if(*(bodyPtr+10+i*4+3)==2){
                    memcpy(CIPHER,"TKIP",5);
                }
            }
            //printf("CIPHER %s\n",CIPHER);
            //printf("AKM Suit Count\n\t");
            tmpPtr = bodyPtr+10+*(u_int16_t *)(bodyPtr+8)*4;
            //printHex(tmpPtr,2);
            
            for(i =0; i < *(tmpPtr);i++){
                //printf("AKM cipher suit selector 4byte\n\t");
                //printHex(tmpPtr+2+i*4,4);
                if(*(tmpPtr+2+i*4+3)==2){
                    //printf("\t\tPSK\n");
                    memcpy(AUTH,"PSK",5);
                }
                else{
                    //printf("\t\tPSK\n");
                    memcpy(AUTH,"IDK",5);
                }    
            
            }
            //printf("AUTH %s\n",AUTH);
            //printf("----------------------------------packet\n");
        }
        
       /*
       if(fieldHdrPtr->ID == 221){
           printf("vendor specific \n");
       }
       */
        if(fieldHdrPtr->ID == 0) break;
    }
    /* etc */
    //printf("len : %04lX\n",bodyLen);
    //printHex((u_int8_t *)bodyPtr,bodyLen);
    //printData();


    /*
    u_int8_t * BSSID = dot11mac.hdr->i_addr3;
        int pwr; -> 32
        int Beacons;
        int data;
        int Channel;'
        int MB;
        char encrypt[5];
        char CIPHER[5];
        char AUTH[5];
        char ESSID[33];
    */
}

int BeaconPacket::nextfield(){
    
    /*
    헤더 가져오고
    body ptr 헤더 위치로 세팅
    //size ptr 에서 크기 만큼 뺌

    만약 현재 해더가 221이면 return 0;
    */
    fieldHdrPtr = (struct FIELD_HEADER *)bodyPtr;
    if(fieldHdrPtr->ID == 221) return 0;
    bodyPtr += fieldHdrPtr->size+2;
    fieldHdrPtr = (FIELD_HEADER *)(bodyPtr);
    return 1;

}