#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include <qxml.h>
#include "structs.h"
#include <qfile.h>
#include <QDebug>
#include <iostream>

class LevelHandler:public QXmlDefaultHandler
{
public:
    bool startDocument();
    bool startElement(const QString &, const QString &, const QString &qName,
                       const QXmlAttributes &atts);
    bool endElement(const QString &, const QString &, const QString &);

    bool fatalError(const QXmlParseException &exception);
    QStringList& attributes();
    QStringList& names();
    QStringList& attributeName();
    QList<int>& anzahl();
    QList<int>& indentations();




private:
    int indentationLevel;
    QStringList elementName;
    QStringList elementAttributes;
    QStringList elementAttributeName;
    QList<int> elementAnzahl;
    QList<int> elementIndentation;



};
#endif // LEVELHANDLER_H
