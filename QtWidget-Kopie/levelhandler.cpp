#include "levelhandler.h"


bool LevelHandler::startDocument()
{
    elementName.clear();
    elementAttributes.clear();
    elementIndentation.clear();
    elementAnzahl.clear();
    elementAttributeName.clear();
    indentationLevel = 0;

    return true;
}


bool LevelHandler::startElement(const QString &, const QString &,
    const QString & qName, const QXmlAttributes & atts){

    Action TempAction;
    if(qName == "Text"){
        TempAction.type = "Text";
        for(int x = 0;x < atts.length();x++){

            if(atts.qName(x) == "id" ){
                TempAction.id = atts.value(x);

            }
            if(atts.qName(x) == "text" ){

                InfoString TempInfS;
                TempInfS.text = atts.value(x);
                TempInfS.type = "Text";
                TempAction.Text.append(TempInfS);

            }
            if(atts.qName(x) == "character" ){
                InfoString TempInfS;
                TempInfS.text = atts.value(x);
                TempInfS.type = "character";
                TempAction.Text.append(TempInfS);
            }
        }
    }

    if(qName == "Eaction"){

        TempAction.type = "Eaction";
        for(int x = 0; x < atts.count();x++){

           if(atts.qName(x) == "id"){
               TempAction.id = atts.value(x);
           }
           if(atts.qName(x) == "character"){
               InfoString TempInfS;
               TempInfS.text = atts.value(x);
               TempInfS.type = "character";
               TempAction.Text = TempInfS;
           }

           if(atts.qName(x) == "EventType"){
               InfoString TempInfS;
               TempInfS.text = atts.value(x);
               TempInfS.type = "EventType";
               TempAction.Text = TempInfS;
           }

        }
    }



    return true;
}
//ich muss das selbe mit qxmlatributes machen
/*!
    Process each ending element in the XML document.

    Decrease the level of indentation by one column.

    We return true to indicate that parsing should continue.
*/

bool LevelHandler::endElement(const QString &, const QString &,
    const QString &){
    indentationLevel -= 1;

    return true;
}

/*!
    Report a fatal parsing error, and return false to indicate to the reader
    that parsing should stop.
*/

bool LevelHandler::fatalError (const QXmlParseException & exception)
{
    qWarning() << QString("Fatal error on line %1, column %2: %3").arg(
        exception.lineNumber()).arg(exception.columnNumber()).arg(
        exception.message());

    return false;
}

/*!
    Return the list of element names found.
*/

QStringList& LevelHandler::names ()
{
    return elementName;
}

/*!
    Return the list of indentations used for each element found.
*/

QList<int>& LevelHandler::indentations ()
{
    return elementIndentation;
}
QStringList& LevelHandler::attributes ()
{
    return elementAttributes;
}
QList<int>& LevelHandler::anzahl (){
    return elementAnzahl;
}
QStringList& LevelHandler::attributeName (){
    return elementAttributeName;
}
