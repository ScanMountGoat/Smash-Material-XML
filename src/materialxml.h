#ifndef MATERIALXML_H
#define MATERIALXML_H

#include "material.h"
#include "searchsettings.h"

#include <QString>
#include <QList>
#include <QXmlStreamReader>


namespace MaterialXml
{
    void addMaterialsFromXML(QString fileName, SearchSettings &settings);

    void readMesh(QXmlStreamReader &reader, QString fileName, SearchSettings &settings);

    void readPolygon(QXmlStreamReader &reader, QString fileName, SearchSettings &settings);

    void readMaterial(QXmlStreamReader &reader, QString fileName, SearchSettings &settings);

	int readIntAttribute(QXmlStreamReader & reader, QString name, bool useHex);

	uint readUintAttribute(QXmlStreamReader & reader, QString name, bool useHex);

    void readParam(QXmlStreamReader &reader, Material &material);
}

#endif // MATERIALXML_H
