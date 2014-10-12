//#include "SharedObject.h"
//#include "Semaphore.h"
#include <stdlib.h>
#include <time.h>
#include <list>
#include <pthread.h>
#include <iostream>

#define NUM_THREADS 5

struct thread_data{
	int thread_id;
	int delayTime;
};

void *writingReport(void *threadarg){
	struct thread_data *my_data;
    time_t curTime;
    time_t preTime;
	my_data = (struct thread_data *) threadarg;
    std::cout<<"Thread ID : " <<my_data->thread_id;
    std::cout<<" Dealy Time : " <<my_data->delayTime<<std::endl;
    
    time(&preTime);
    time(&curTime);
    for(int i = 0; i<10; i++){
        int dif = difftime(curTime, preTime);
        std::cout<<"Thread ID: "<<my_data->thread_id<<" reports "<<i<< " Time Difference: "<<dif<<std::endl;
        preTime = curTime;
        sleep(my_data->delayTime);
        time(&curTime);
    }

	pthread_exit(NULL);

}

int main(void)
{
	std::cout << "I am a writer!" << std::endl;
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
    int threadCounter = 0; // thread counter
    int err; //a variable that indicates a thread is created successfully or not

    char choice; //a variable that for use continues creating a new thread

    std::cout <<"Would you like to create a writer thread?";
    std::cin >> choice;
    
    while (choice == 'y'){
    	int delayTime;
    	std::cout <<"What is the dalay time for the new thread?";
    	std::cin>>delayTime;
        
    	td[threadCounter].thread_id = threadCounter;
    	td[threadCounter].delayTime = delayTime;

    	err = pthread_create(&threads[threadCounter],NULL,writingReport, (void *)&td[threadCounter]);
    	if (err != 0) {
    		std::cout<<"can't create thread :" <<strerror(err);
    		exit(-1);
    	}
    	else {
    		std::cout<<"Thread " << threadCounter <<" created successfully" << std::endl;
    	}

    	threadCounter++;
    	std::cout <<"Would you like to create a writer thread?";
    	std::cin >> choice;
    }

    std::cout<<"Main thread goes to sleep"<<std::endl;
    for (int i =0; i < threadCounter; i++){
        pthread_join(threads[i],NULL);
    }
    std::cout<<"Main thread exits"<<std::endl;
    return 0;
}
