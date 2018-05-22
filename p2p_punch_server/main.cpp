#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "p2p_type.h"
#include "tc_shared_ptr.h"
#include "tc_enable_shared_from_this.h"
#include "tc_socket.h"
#include "tc_clientsocket.h"
#include "tc_thread_pool.h"



using namespace std;
using namespace tars;


typedef int int32_t ;
#define NDEBUG


#if 0
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


template <class T>
struct type_2_type{
      typedef   T  type_original_t;
};




template<int v>
struct int2type{

    enum{value=v};

};


/*
template <class  U,bool isbool>
class animal{
 public:
 	void todo(const U *	u,int2type<true>)
 	{
 	   std::cout<<"int2type[true]"<<std::endl;
 	}

	void todo(const U * u,int2type<false>)
 	{
 	  std::cout<<"int2type[false]"<<std::endl;
 	}

 public:
   void todo(const U *u)
   { 
          todo(u,int2type<isbool>);
       
   }

};
*/
#endif 




peer_info_st  g_peer_map;

TC_ThreadPool g_pool;


void getip(string &data,int i)
{
    std::cout<<data<<i<<std::endl;
	std::cout<<pthread_self()<<std::endl;
	return;
}



//typedef  map<uint16_t ,string &> 

int main(int argc, char * argv [ ])
{ 

      //std::cout<<"p2p punch hole "<<std::endl;
      //std::cout<<now2str()<<std::endl;

	  std::cout<<"p2p_punch_server starting......."<<std::endl;

	  
      #if 0
	  TC_TCPClient tc;
	  tc.init("172.16.103.125", 1234, 10);

	  tc.send("jackwu",10);
	  #endif 
    
	 TC_Socket sr;
     TC_Socket client_sr;//tc_socket
	 
	 //client_sr.init(0,true);
	 struct sockaddr_un stSockAddr;
     socklen_t iSockAddrSize = sizeof(sockaddr_un);
	 int clientfd;
	 uint16_t port;
	 string socketname;
	 g_pool.init(10);
	 g_pool.start();

	 //! map<uint16_t,string>t_user_info;
	 //! t_user_info.insert(map<uint16_t,string>::value_type(12,"dfdf"));
	 
	 
	 sr.createSocket();//sr server 
	 sr.bind("172.16.103.125", 12344);
	 
	 sr.listen(10);
	 sr.getSockName(socketname,port);
     std::cout<<"\n sockername:"<<socketname<<"port:"<<port<<std::endl;
	 
	 
	 do{ 
            
	        std::cout<<client_sr.getfd()<<std::endl;
            clientfd=sr.accept(client_sr,(struct sockaddr *)&stSockAddr,iSockAddrSize);
	        //std::cout<<clientfd<<std::endl;
	        
			if(clientfd<0)
			{
        	  goto ERR;
			}
            TC_Endpoint endpoint;
			string remotehost;
			uint16_t nport;
				
			client_sr.getPeerName(remotehost,nport);
			
			endpoint.setHost(remotehost);
			endpoint.setPort(nport);

			TC_Functor<void ,TL::TLMaker<string &,int>::Result>cmd(getip);
			TC_Functor<void,TL::TLMaker<string &,int>::Result>::wrapper_type wrap(cmd,"123",1);
			g_pool.exec(wrap);
			
            //g_peer_map.setendpoint(string key,endpoint);
			//std::cout<<endpoint.toString()<<std::endl;
           
			
			string strtime=now2str();       
			client_sr.send(strtime.c_str(), strlen(strtime.c_str()));
			
			
			client_sr.close();

	 }while(1);
	 
      sr.close();
	  
     std::cout<<"ok"<<endl;
     return 0;


	ERR:
		return -1;

}
