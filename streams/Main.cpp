#include <thread>
#include "FirstStream.h"
#include "SecondStream.h"
#include "SynchStream.h"
#include <iostream>

int main()
{
	/*FirstStream firstStream;
	firstStream.Interface();
	SecondStream secondStream;
	secondStream.Interface();*/
	SynchStream stream;
	while (true)
	{
		std::cout << std::endl << "EXIT?(y/n)" << std::endl;
		std::string answer = "";
		std::cin >> answer;
		if (answer == "y")
		{
			break;
		}

		std::thread streamFirst(&SynchStream::FirstrStreamRunning, std::ref(stream));
		std::thread streamSecond(&SynchStream::SecondStreamRunning, std::ref(stream));
		//stream.m.unlock();
		streamFirst.join();
		streamSecond.join();
	}
	return 0;
}
//#include <iostream>
//#include <thread>
//#include <vector>
//#include <string>
//
//
//void newValue(int& value) {
//    value = 2;
//    std::string out = "[newValue] t0 new value: " + std::to_string(value) + " \n";
//    std::cout << out;
//}
//
//class workClass {
//public:
//    void operator() () {
//        std::string out = "[operator] t1 running\n";
//        std::cout << out;
//    };
//};
//int main() {
//    std::cout << "Main thread running" << std::endl;
//    std::vector<std::thread> detachPool;
//
//    int value = 5;
//    std::string value_out = "[main] \told value: " + std::to_string(value);
//    std::thread t0(newValue, std::ref(value));
//    //t0 must terminate before inspecting the new value
//    t0.join();
//    value_out += "\tnew value: " + std::to_string(value) + "\n";
//    std::cout << value_out;
//
//    std::thread t1{ workClass() };
//    detachPool.push_back(std::move(t1));
//
//    std::thread t2([]() {
//        std::string out = "[lambda] t2 running\n";
//        std::cout << out; });
//    detachPool.push_back(std::move(t2));
//
//    for (std::thread& t : detachPool) {
//        t.detach();
//    }
//    std::string out = "Main thread exits\n";
//    std::cout << out;
//    return 0;
//}