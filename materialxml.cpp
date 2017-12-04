#include "materialxml.h"
#include <QFile>
#include<QDebug>


MaterialXml::MaterialXml(QString fileName)
{



}

void MaterialXml::readMaterial(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement())
    {
        if(reader.name() == "material")
        {
            qInfo() << reader.name();

            while(reader.readNextStartElement())
            {
                if(reader.name() == "param")
                {
                    QString name = "";
                    if (reader.attributes().hasAttribute(("name")))
                        name = reader.attributes().value("name").toString();

                    QString values = reader.readElementText();

                    qInfo() << name << " " << values;
                }
                else
                    reader.skipCurrentElement();
            }

            reader.skipCurrentElement();
        }
        else
            reader.skipCurrentElement();
    }
}

void MaterialXml::MaterialDataFromXML(QString fileName)
{
    QXmlStreamReader reader;

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file" << file.errorString();
    }
    reader.setDevice(&file);

    if (reader.readNextStartElement()) {
        if (reader.name().contains("NUDMATERIAL"))
        {
            qInfo() << reader.name();

            while(reader.readNextStartElement())
            {
                if(reader.name() == "mesh")
                {
                    qInfo() << reader.name();

                    while(reader.readNextStartElement())
                    {
                        if(reader.name() == "polygon")
                        {
                            qInfo() << reader.name();

                            readMaterial(reader);
                        }
                        else
                            reader.skipCurrentElement();
                    }

                    reader.skipCurrentElement();
                }
                else
                    reader.skipCurrentElement();
            }
        }
        else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
}
