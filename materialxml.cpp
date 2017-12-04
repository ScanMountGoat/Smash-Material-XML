#include "materialxml.h"
#include <QXmlStreamReader>
#include <QFile>
#include<QDebug>


MaterialXml::MaterialXml(QString fileName)
{



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

                            while(reader.readNextStartElement())
                            {
                                if(reader.name() == "material")
                                {
                                    qInfo() << reader.name();

                                    while(reader.readNextStartElement())
                                    {
                                        if(reader.name() == "param")
                                        {
                                            qInfo() << reader.name();

                                            QString s = reader.readElementText();
                                            qInfo() << s;

                                        }
                                        else
                                            reader.skipCurrentElement();
                                    }

                                }
                                else
                                    reader.skipCurrentElement();
                            }
                        }
                        else
                            reader.skipCurrentElement();
                    }
                }
                else
                    reader.skipCurrentElement();
            }
        }
        else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
}
