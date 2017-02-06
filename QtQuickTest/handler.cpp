#include "handler.h"

/*!
    Reset the state of the handler to ensure that new documents are
    read correctly.

    We return true to indicate that parsing should continue.
*/
int dd = 0;
bool Handler::startDocument()
{
    elementName.clear();
    elementAttributes.clear();
    elementIndentation.clear();
    elementAnzahl.clear();
    elementAttributeName.clear();
    indentationLevel = 0;

    return true;
}

/*!
    Process each starting element in the XML document.

    Append the element name to the list of elements found; add its
    corresponding indentation level to the list of indentation levels.

    Increase the level of indentation by one column.

    We return true to indicate that parsing should continue.
*/

bool Handler::startElement(const QString &, const QString &,
    const QString & qName, const QXmlAttributes & atts)
{

    elementName.append(qName);
    int anzahl = 0;


    for(int index = 0; index < atts.length();index++){//index = 0
        int d = index;
        if(qName == "map"){//alle attribute von map    Kein fehler
            if(atts.qName(index) == "width"){
                mp.width = atts.value(index).toInt();
                index ++;
            }
            if(atts.qName(index)== "height"){
                mp.height = atts.value(index).toInt();
                index++;
            }
        }
        //std::cout << qName.toStdString() << "    " << atts.qName(index).toStdString() << std::endl;


        if(qName == "tileset"){


            bool ok;
            if(atts.qName(index)=="firstgid"){
                t.firstgid = atts.value(index).toInt(&ok,10);

                //index++;


            }
            if(atts.qName(index)=="name"){
                t.name = atts.value(index);
                //index ++;
            }
            if(atts.qName(index)=="tilewidth"){
                t.tilewidth = atts.value(index).toInt(&ok,10);
                //index++;

            }
            if(atts.qName(index)=="tileheight"){
                t.tileheight = atts.value(index).toInt(&ok,10);
                //index++;
            }
            if(atts.qName(index)=="tilecount"){
                t.tilecount = atts.value(index).toInt(&ok,10);
                //index++;
            }
            if(atts.qName(index)=="columns"){
                t.columns = atts.value(index).toInt(&ok,10);
                //index++;

            }


            index++;
        }
        if(qName == "image"){//geht

            if(atts.qName(index) == "source"){
                t.source = atts.value(index);
                mp.tilesets.append(t);
            }
        }
        if(qName =="layer"){

            if(atts.qName(index)=="name"){
                l.name = atts.value(index);

            }
            if(atts.qName(index)=="width"){
                l.width = atts.value(index).toInt();

            }
            if(atts.qName(index)=="height"){

                l.height = atts.value(index).toInt();

            }
            index++;
        }


        if(qName == "tile"){//!funktioniert noch nicht mit tiles mit mehreren attribute(animation usw.)

            std::cout << dd << std::endl;
            dd++;
            ti.gid = atts.value(index).toInt();
            dee++;
            l.tiles.append(ti);
            index++;

            if(dee == l.height*l.width){
               mp.layers.append(l);
               dee = 0;
            }




        }


        index = d;//für das auslesen und couten
        elementAttributes.append(atts.value(index));
        elementAttributeName.append(atts.qName(index));
        anzahl = index+1;
    }

    elementAnzahl.append(anzahl);

    elementIndentation.append(indentationLevel);
    indentationLevel += 1;

    return true;
}
//ich muss das selbe mit qxmlatributes machen
/*!
    Process each ending element in the XML document.

    Decrease the level of indentation by one column.

    We return true to indicate that parsing should continue.
*/

bool Handler::endElement(const QString &, const QString &,
    const QString &)
{
    indentationLevel -= 1;

    return true;
}

/*!
    Report a fatal parsing error, and return false to indicate to the reader
    that parsing should stop.
*/

bool Handler::fatalError (const QXmlParseException & exception)
{
    qWarning() << QString("Fatal error on line %1, column %2: %3").arg(
        exception.lineNumber()).arg(exception.columnNumber()).arg(
        exception.message());

    return false;
}

/*!
    Return the list of element names found.
*/

QStringList& Handler::names ()
{
    return elementName;
}

/*!
    Return the list of indentations used for each element found.
*/

QList<int>& Handler::indentations ()
{
    return elementIndentation;
}
QStringList& Handler::attributes ()
{
    return elementAttributes;
}
QList<int>& Handler::anzahl (){
    return elementAnzahl;
}
QStringList& Handler::attributeName (){
    return elementAttributeName;
}
