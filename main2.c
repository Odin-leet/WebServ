#include <string>
#include<iostream>
#include <vector>

#include <unistd.h>
#include <sstream>

int main()
{
    int chunksize = -1;
    std::string str;
    str.append("AAFFF0");
    std::istringstream iss(str);
		//std::string lop = data.substr(0,found);
		std::cout<<"backup line :"<<str<<std::endl;
    	iss >> std::hex >> chunksize;
        std::cout<<chunksize<<std::endl;
}