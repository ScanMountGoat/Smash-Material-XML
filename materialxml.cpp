#include "materialxml.h"
#include <QXmlStreamReader>
#include <QFile>

MaterialXml::MaterialXml(QString fileName)
{



}

void MaterialXml::MaterialDataFromXML(QString fileName)
{
    QXmlStreamReader reader;

    QFile file(fileName);

    reader.setDevice(&file);
    reader.readNext();

    while(!reader.atEnd())
    {
        if (reader.isStartElement())
        {
            float test = reader.readElementText().toFloat();
        }
    }
}
