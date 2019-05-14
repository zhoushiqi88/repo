#ifndef _THREADBASE_H
#define _THREADBASE_H

#include<thread>

class Thread_Base {
public:
	Thread_Base();
	virtual ~Thread_Base();

	void Start();
	void Join();

private:
	virtual void Run() = 0;
};



#endif