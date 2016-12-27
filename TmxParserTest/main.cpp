#include "handler.h"

int main(int argc, char *argv[])
{

    QXmlSimpleReader* parser 		= new QXmlSimpleReader();
    MyXmlContentHandler* handler 	= new MyXmlContentHandler();


    parser->setContentHandler(handler);

    std::cout<<	"Starting parsing"<< std::endl;

    if(parser->parse(new QXmlInputSource(new QFile(":/xml/test.xml"))))
    {
    std::cout<<"Parsed Successfully!"<< std::endl;
    }
    else
    {
    std::cout<<"Parsing Failed..."<< std::endl;
    }
}
