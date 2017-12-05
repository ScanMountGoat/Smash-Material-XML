#include "materialxml.h"
#include <QFile>
#include<QDebug>


void MaterialXml::materialDataFromXML(QString fileName)
{
    QXmlStreamReader reader;

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Cannot read file" << file.errorString();
    }
    reader.setDevice(&file);

    if (reader.readNextStartElement()) {
        if (reader.name() == "NUDMATERIAL")
        {
            qInfo() << reader.name();
            readMesh(reader);
        }
        else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
}

void MaterialXml::readMesh(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement())
    {
        if(reader.name() == "mesh")
        {
            QString name = "";
            if (reader.attributes().hasAttribute(("name")))
                name = reader.attributes().value("name").toString();

            qInfo() << "\t" << name;

            readPolygon(reader);
        }
        else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readPolygon(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement())
    {
        if(reader.name() == "polygon")
        {
            qInfo() << "\t\t" << reader.name();

            readMaterial(reader);
        }
        else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readMaterial(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement())
    {
        if(reader.name() == "material")
        {
            qInfo() << "\t\t\t"<< reader.name();

            readParam(reader);
        }
        else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readParam(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement())
    {
        if(reader.name() == "param")
        {
            QString name = "";
            if (reader.attributes().hasAttribute(("name")))
                name = reader.attributes().value("name").toString();

            QString values = reader.readElementText();

            qInfo() << "\t\t\t\t" << name << " " << values;
        }
        else
            reader.skipCurrentElement();
    }
}
