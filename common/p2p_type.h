#ifndef __P2P_TYPE__H
#define __P2P_TYPE__H
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "tc_clientsocket.h"
#include "tc_buffer.h"
using namespace std ;
using namespace tars;


typedef int int32_t ;
#define MAX_BUFFER   1024



string now2str(const string &sFormat = "%Y%m%d%H%M%S")
{
    time_t t = time(NULL);
    struct tm *pTm = localtime(&t);
    if(pTm == NULL)
    {
        return "";
    }

    char sTimeString[255] = "\0";

    strftime(sTimeString, sizeof(sTimeString), sFormat.c_str(), pTm);

    return string(sTimeString);
}



string int2string(int32_t user_id)
{
    stringstream ss;
    ss << user_id;
    return ss.str();
}

int32_t string2int(const string& value)
{
    return (int)atoi(value.c_str());
}

typedef  map<string ,TC_Endpoint &>peer_info_map;

enum CMD_T{
        LOGIN,
		LOGINOUT,
		SYS,
		ACK,
		PUNCH
};


struct package{
    uint16_t fd;
	int cmd;
	void *buffer;
}p2p_pack_t;



class peer_info_st{

    public:
           // get addr info by key
	       TC_Endpoint & getendpoint(string &key)const;
           // void set addr
            void setendpoint(string ,TC_Endpoint&);
		   peer_info_map &getpeer();
		   // isempty
		   
		   bool isempty()const;
		   uint16_t getsize();
		   
		  

    private:
	   //vector<TC_Endpoint> endpoints; 
	   peer_info_map endpoints;

	   

};






#endif 


