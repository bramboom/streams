#include "FirstStream.h"
#include "SecondStream.h"
#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include "SynchStream.h"

void SynchStream::FirstrStreamRunning()
{
	{
		std::lock_guard<std::mutex> ug(m);
		FirstStream stream1;
		stream1.Interface();
		IsReady = true;
		bell.notify_one();
	}
}

void SynchStream::SecondStreamRunning()
{
	std::unique_lock<std::mutex> ul(m);
	bell.wait(ul, [=]() {return IsReady == true; });
	bell.notify_one();
	SecondStream stream2;
	stream2.Interface();
	IsReady = false;
}


void SynchStream::SynchInterface()
{
	
}

