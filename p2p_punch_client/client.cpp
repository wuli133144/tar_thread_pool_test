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


using namespace std;
using namespace tars;




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

