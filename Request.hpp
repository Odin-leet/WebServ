#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

class Request
{

	public:

		Request();
		Request( Request const & src );
		~Request();

		Request &		operator=( Request const & rhs );
		void setmethod(std::string me);
		void sethost(std::string ho);
		void setconnection(std::string str);
		//void setuser_agent(std::string *us);
		void setaccept_enco(std::string *enc);
		bool settransferchunks(std::string ther);
		void setcontent_length(std::string len);
		void setcontent_type(std::string type);
		std::string get_method();
		std::string gethost();
		bool get_connection();
		//char *get_useragent();
		char *accept_encoding();

	private:
		std::string method;
		std::string host;
		bool Connection;
		bool transferchunks;
		std::string content_type;
		int content_lenght;
		//std::string *user_agent;
		//std::string *Accept_encoding;
		


}; 

std::ostream &			operator<<( std::ostream & o, Request const & i );

#endif /* ********************************************************* REQUEST_H */