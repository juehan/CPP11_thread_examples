#include <thread>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

void func(int i, std::vector<std::string>& v)
{
	for(int j = 0; j < i; j++)
	{
		std::cout<<"\n\n"<<j<<"th iteration ---"<<std::endl;
		std::for_each(v.begin(), v.end(), [](std::string& str){
			std::cout<<str<<",";
		});
	}	
}

int main(int argc, char**)
{
	std::vector<std::string> v;

	v.push_back("hello");
	v.push_back("C++");
	v.push_back("Thread world");
	//when create thread object, give thread function argument along with parameter
	std::thread t(func, 3, v); 
	//wait until thread function completed
	t.join();

	std::cout<<"\n\nWelcome to C++11 - Thread"<<std::endl;
	return 0;
}
