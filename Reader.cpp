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
    string oldMsg = " ";
    string newMsg = " ";

    while (true){
        thread_data *temp = sharedPoint.get();
        newMsg = tostring(temp->thread_id)+"  "+tostring(temp->reportCounter)+"  "+tostring(temp->delayTime);
        if(oldMsg!=newMsg){
            cout<<newMsg<<endl;
            oldMsg = newMsg;
        }
        
        //std::cout<<temp->thread_id<<"  "<<temp->reportCounter<<"  "<<temp->delayTime<<std::endl;
    	//std::cout<<sharedPoint->thread_id<<"  "<<sharedPoint->reportCounter<<"  "<<sharedPoint->delayTime<<std::endl;
    	usleep(500000);
    }
    return 0;
    
}
