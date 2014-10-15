#include "SharedObject.h"
#include "Semaphore.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

struct thread_data{
	int thread_id;
	int delayTime;
    int reportCounter;
};

int main(void)
{
    cout << "I am a Reader!" <<endl;

    Shared<thread_data>sharedPoint("thing");
    thread_data temp;
    while (true){
        //thread_data *temp = sharedPoint.get();
       
        if((temp.thread_id != sharedPoint->thread_id) ||(temp.reportCounter!=sharedPoint->reportCounter)||(temp.delayTime!=sharedPoint->delayTime)){
            std::cout<<sharedPoint->thread_id<<"  "<<sharedPoint->reportCounter<<"  "<<sharedPoint->delayTime<<std::endl;
            
            temp.thread_id = sharedPoint->thread_id;
            temp.reportCounter=sharedPoint->reportCounter;
            temp.delayTime=sharedPoint->delayTime;

        }
        
        //std::cout<<temp->thread_id<<"  "<<temp->reportCounter<<"  "<<temp->delayTime<<std::endl;
    	//std::cout<<sharedPoint->thread_id<<"  "<<sharedPoint->reportCounter<<"  "<<sharedPoint->delayTime<<std::endl;
    	usleep(1000000);
    }
    return 0;
    
}
