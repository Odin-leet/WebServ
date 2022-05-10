# include <iostream>
# include <string>


int main()
{
    std::string *string1;
    for (int i = 0; i < 5; i++)
        string1[i] = "Sadasdasdas";

    std::cout<<string1->length()<<std::endl;
}