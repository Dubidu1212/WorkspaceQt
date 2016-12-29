#include <QDebug>
#include "handler.h"

/*!
    Reset the state of the handler to ensure that new documents are
    read correctly.

    We return true to indicate that parsing should continue.
*/

bool Handler::startDocument()
{
    elementName.clear();
    elementAttributes.clear();
    elementIndentation.clear();
    elementAnzahl.clear();
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
    for(int index = 0; index < atts.length();index++){

        elementAttributes.append(atts.value(index));
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
