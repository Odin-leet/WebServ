#include "Request.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Request::Request()
{
}

Request::Request( const Request & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Request::~Request()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Request &				Request::operator=( Request const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Request const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void					Request::setmethod(std::string me)
{
	method = me;
}
void					Request::sethost(std::string ho)
{
	host = ho;
}
void					Request::setconnection(std::string str)
{
	if (str == "Keep-alive")
	Connection = true;
	if (str == "close")
	Connection = false;
}
//void					Request::setuser_agent(std::string *us)
//{
//	host = ho;
//}
void					Request::setcontent_length(std::string len)
{
	//char *Str = len;
	content_lenght = stoi(len);
}	
void					Request::setcontent_type(std::string type)
{
	content_type = type;
}
bool					Request::settransferchunks(std::string len)
{		
		if (len == "chunk")
		transferchunks = true;
		else 
		transferchunks = false;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */