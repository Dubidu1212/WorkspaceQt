#include "handler.h"
#include <vector>
int main(int argc, char *argv[])
{

    QXmlSimpleReader* parser 		= new QXmlSimpleReader();
    MyXmlContentHandler* handler 	= new MyXmlContentHandler();

    std::vector<std::string> attr;

    parser->setContentHandler(handler);

    std::cout<<	"Starting parsing"<< std::endl;

    if(parser->parse(new QXmlInputSource(new QFile(":/xml/example.tmx"))) != NULL)
    {
    std::cout<<"Parsed Successfully!"<< std::endl;
    std::cout<< parser->parse(new QXmlInputSource(new QFile(":/xml/example.tmx")));
    }
    else
    {
    std::cout<<"Parsing Failed..."<< std::endl;
    }
}
