#include "materialxml.h"
#include "materialcontainer.h"

#include <QFile>
#include <QDebug>

QList<Material> materialList;


void MaterialXml::materialDataFromXML(QString fileName)
{
    QXmlStreamReader reader;

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Cannot read file" << file.errorString();
    }
    reader.setDevice(&file);

    if (reader.readNextStartElement()) {
        if (reader.name() == "NUDMATERIAL") {
            qInfo() << reader.name();
            readMesh(reader);
        } else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
}

void MaterialXml::readMesh(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement()) {
        if(reader.name() == "mesh") {
            QString name = "";
            if (reader.attributes().hasAttribute(("name")))
                name = reader.attributes().value("name").toString();

            qInfo() << "\t" << name;

            readPolygon(reader);
        } else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readPolygon(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement()) {
        if(reader.name() == "polygon") {
            qInfo() << "\t\t" << reader.name();

            readMaterial(reader);
        } else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readMaterial(QXmlStreamReader &reader)
{
    while(reader.readNextStartElement()) {
        if(reader.name() == "material") {
            qInfo() << "\t\t\t"<< reader.name();
            Material material;

            // read and set flags
            uint flags = 0;
            if (reader.attributes().hasAttribute(("flags"))) {
                bool ok;
                flags = reader.attributes().value("flags").toUInt(&ok, 16);
            }
            material.setFlags(flags);

            qInfo() << "\t\t\t"<< reader.attributes().value(("flags"));

            readParam(reader, material);

            // add the material to the global material list
            materialList.append(material);
        } else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readParam(QXmlStreamReader &reader, Material material)
{
    while(reader.readNextStartElement()) {
        if(reader.name() == "param") {
            QString name = "";
            if (reader.attributes().hasAttribute(("name")))
                name = reader.attributes().value("name").toString();

            QString valuesString = reader.readElementText();
            QStringList values = valuesString.split(" ");
            QList<float> paramValues;

            for (int i = 0; i < 4; i++) {
                paramValues.append(values.at(i).toFloat());
            }

            material.properties.insert(name, paramValues);

            qInfo() << "\t\t\t\t" << name << " " << paramValues.at(0) << "," << paramValues.at(1) << "," << paramValues.at(2) << "," << paramValues.at(3);
        } else
            reader.skipCurrentElement();
    }
}
