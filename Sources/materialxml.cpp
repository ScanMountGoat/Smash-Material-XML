#include "Headers/materialxml.h"
#include "Headers/materialcontainer.h"

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
            readMesh(reader, fileName);
        } else
            reader.raiseError(QObject::tr("Incorrect file"));
    }
}

void MaterialXml::readMesh(QXmlStreamReader &reader, QString fileName)
{
    while(reader.readNextStartElement()) {
        if(reader.name() == "mesh") {
            QString name = "";
            if (reader.attributes().hasAttribute(("name")))
                name = reader.attributes().value("name").toString();

            readPolygon(reader, fileName);
        } else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readPolygon(QXmlStreamReader &reader, QString fileName)
{
    while(reader.readNextStartElement()) {
        if(reader.name() == "polygon") {
            readMaterial(reader, fileName);
        } else
            reader.skipCurrentElement();
    }
}

void MaterialXml::readMaterial(QXmlStreamReader &reader, QString fileName)
{
    while(reader.readNextStartElement()) {
        if(reader.name() == "material") {
            Material material;

            // In case we need to display the file path later.
            material.fileName = fileName;

            // read and set flags
            uint flags = 0;
            if (reader.attributes().hasAttribute(("flags"))) {
                bool ok;
                flags = reader.attributes().value("flags").toUInt(&ok, 16);
            }
            material.setFlags(flags);

            // read and set srcFactor
            int src = 0;
            if (reader.attributes().hasAttribute(("srcFactor"))) {
                bool ok;
                src = reader.attributes().value("srcFactor").toInt(&ok, 16);
            }
            material.srcFactor = src;

            // read and set dstFactor
            int dst = 0;
            if (reader.attributes().hasAttribute(("dstFactor"))) {
                bool ok;
                dst = reader.attributes().value("dstFactor").toInt(&ok, 16);
            }
            material.dstFactor = dst;

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
        } else
            reader.skipCurrentElement();
    }
}
