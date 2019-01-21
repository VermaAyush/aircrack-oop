#include "pch.h"
#include "Radiotap.h"

struct radiotap_align_size Radiotap::rtap_namespace_sizes[23];

Radiotap::Radiotap(){
    rtap_namespace_sizes[IEEE80211_RADIOTAP_TSFT] = { .align = 8, .size = 8, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_FLAGS] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_RATE] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_CHANNEL] = { .align = 2, .size = 4, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_FHSS] = { .align = 2, .size = 2, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_DBM_ANTSIGNAL] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_DBM_ANTNOISE] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_LOCK_QUALITY] = { .align = 2, .size = 2, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_TX_ATTENUATION] = { .align = 2, .size = 2, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_DB_TX_ATTENUATION] = { .align = 2, .size = 2, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_DBM_TX_POWER] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_ANTENNA] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_DB_ANTSIGNAL] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_DB_ANTNOISE] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_RX_FLAGS] = { .align = 2, .size = 2, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_TX_FLAGS] = { .align = 2, .size = 2, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_RTS_RETRIES] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_DATA_RETRIES] = { .align = 1, .size = 1, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_MCS] = { .align = 1, .size = 3, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_AMPDU_STATUS] = { .align = 4, .size = 8, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_VHT] = { .align = 2, .size = 12, };
    rtap_namespace_sizes[IEEE80211_RADIOTAP_TIMESTAMP] = { .align = 8, .size = 12, };
}

Radiotap::~Radiotap(){
    //rintf("free - Radiotap\n");
    //free(hdr);
}

void Radiotap::printAttr(){
    printf("version : %02X\n",hdr->it_version);
    printf("len : %d\n",hdr->it_len);
    printf("field : %04X\n",hdr->it_present);

    /*
        u_int8_t        it_version;    
        u_int8_t        it_pad;
        u_int16_t       it_len;     
        u_int32_t       it_present;  
    */
}



int Radiotap::getchennel(){
    
    /*
    flag 1 u8
    Rate 2  u8
    channel 3 u16, u16
    */
   int offset = 0;
   
   if(!(hdr->it_present & 0x8)){
       return 0;
   }
   if(hdr->it_present & 0x1) 
   {
       offset += rtap_namespace_sizes[IEEE80211_RADIOTAP_TSFT].size;
   }

   if(hdr->it_present & 0x2) 
   {
       offset += rtap_namespace_sizes[IEEE80211_RADIOTAP_FLAGS].size;
   }
   if(hdr->it_present & 0x4) 
   {
       offset += rtap_namespace_sizes[IEEE80211_RADIOTAP_RATE].size;
   }
    //printAttr();
    //printf("offset : %d\n",offset);
    //printHex((u_int8_t *)hdr+12,hdr->it_len-12);
    u_int16_t frequency = *(u_int16_t * )((u_int8_t *)hdr+12+offset);
    //printf("frequency : %d \n", frequency);
    int result = (frequency-2407)/5;
    //printf("channel : %d\n", result);
    //printBins((u_int8_t *)hdr+4,32*4);
    //printf("----------------------------packet\n");
    return result;
}



