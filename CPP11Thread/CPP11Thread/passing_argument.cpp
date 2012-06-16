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

int main()
{
	std::vector<std::string> v;

	v.push_back("hello");
	v.push_back("C++");
	v.push_back("Thread world");

	std::thread t(func, 3, v);
	t.join();

	std::cout<<"\n\nWelcome to C++11 - Thread"<<std::endl;
	return 0;
}
