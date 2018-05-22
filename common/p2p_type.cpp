#include "p2p_type.h"

TC_Endpoint & peer_info_st::getendpoint(string & key)
{

         peer_info_map::iterator iter=endpoints.begin();
		 for(;iter!=endpoints.end();iter++)
		 {
		      if(key==*iter){
			  	 return iter->second;
			  }
		 }
         
}

void peer_info_st::setendpoint(string key,TC_Endpoint & endpoint)
{
        peer_info_map.insert(pair<string,TC_Endpoint &>(key,endpoints));
}


peer_info_map &peer_info_st::getpeer()
{
      return endpoints;
}

bool  peer_info_st::isempty()const
{
          return endpoints.size()==0?true:false;
}


uint16_t peer_info_st::getsize(){

      return endpoints.size();
}



