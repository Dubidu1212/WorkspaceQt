#ifndef HANDLER_H
#define HANDLER_H

#include <qstring.h>
#include <qxml.h>

class Handler : public QXmlDefaultHandler
{
public:
    bool startDocument();
    bool startElement(const QString &, const QString &, const QString &qName,
                       const QXmlAttributes &atts);
    bool endElement(const QString &, const QString &, const QString &);

    bool fatalError(const QXmlParseException &exception);
    QStringList& attributes();
    QStringList& names();
    QList<int>& indentations();

private:
    int indentationLevel;
    QStringList elementName;
    QStringList elementAttributes;
    QList<int> elementIndentation;
};

#endif
