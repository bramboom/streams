#pragma once
#include <mutex>
class SynchStream
{
public:
	std::mutex m;
	bool IsReady = false;
	std::condition_variable bell;
	void SynchInterface();
	void FirstrStreamRunning();
	void SecondStreamRunning();
};