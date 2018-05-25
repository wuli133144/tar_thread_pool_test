#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "tc_shared_ptr.h"
#include "tc_enable_shared_from_this.h"
#include "tc_clientsocket.h"
#include"tc_thread.h"
#include "tc_thread_mutex.h"
#include "tc_thread_cond.h"
#include "tc_thread_pool.h"


#include "tc_http.h"
#include "tc_common.h"
#include "tc_clientsocket.h"
#include "tc_timeprovider.h"
#include "tc_functor.h"





using namespace std;
using namespace tars;




//test httprequest



void handle(int timeouts){

         cout<<"threadid="<<pthread_self()<<endl;
		 TC_HttpRequest reqhttp;
		 TC_HttpResponse response;
		 
		 reqhttp.setGetRequest("http://172.16.103.125:80/");
         TC_URL url=reqhttp.getURL();
		 cout<<"http url="<<url.getDomain()<<" port="<<url.getPort()<<endl;
		 	
		 reqhttp.doRequest(response); 
		 cout<<"httpresponse headline:"<<response.getResponseHeaderLine()<<endl;
		 cout<<"httpresponse contents:"<<response.getContent()<<endl;
		 return;
		 
}


int main(int argc,char **argv){

//thread num , timeout
if(argc!=3){
	cout<<"usage:"<<argv[0]<<" argsment error"<<endl;
	return -1;
}

//get thread num

try{
int threadnum=TC_Common::strto<int>(string(argv[1]));
int timeouts=TC_Common::strto<int>(string(argv[2]));
cout<<"threadnum="<<threadnum<<" timeout="<<timeouts<<endl;

TC_ThreadPool thrpool;
thrpool.init(threadnum);
thrpool.start();



TC_Functor<void,TL::TLMaker<int>::Result>cmd(handle);
TC_Functor<void,TL::TLMaker<int>::Result>::wrapper_type fwrap(cmd,timeouts);
for(int i=0;i<threadnum;i++){
 	thrpool.exec(fwrap);
}

 
 thrpool.waitForAllDone(1000);
 
 }catch( exception &e){

         cout<<"error:"<<e.what()<<endl;
 
 }
catch(...){
	
}

 return 0;

}



#if 0

class mythread:public TC_Thread{
	protected:
		 void run()
		 {
		 	 std::cout<<"hello world"<<std::endl;
		 }
};



void TestFunction3(const string &str,int num){
	 std::cout<<"str="<<str<<" num="<<num<<std::endl;
}


int main(int argc, char * argv [ ])
{ 

      #if 0
	  TC_TCPClient tc;
	  tc.init("172.16.103.125", 1234, 10);
      string buffer;
	  tc.recvAll(buffer);
	  std::cout<<buffer<<std::endl;
      #endif

	// mythread trd;
	// trd.start();
	// TC_ThreadControl contrl=trd.getThreadControl();
	// contrl.join();
	// contrl.sleep(1000);
    TC_ThreadPool pool;
	pool.init(4);
	pool.start();
    int i=4;
	string s("wuyujie");
    TC_Functor<void, TL::TLMaker<const string&, int>::Result> cmd(TestFunction3);
    while(i)
    {
        TC_Functor<void, TL::TLMaker<const string&, int>::Result>::wrapper_type fw(cmd, s, i);
        pool.exec(fw);
        --i;
    } 
    std::cout<<"main thread"<<std::endl;

	pool.waitForAllDone(1000);
    return 0;

}
#endif 
