#ifndef MATERIALXML_H
#define MATERIALXML_H

#include "material.h"
#include "searchsettings.h"

#include <QString>
#include <QList>
#include <QXmlStreamReader>


class MaterialXml
{
public:
    MaterialXml();
    static void addMaterialsFromXML(QString fileName, SearchSettings &settings);
    static void readMesh(QXmlStreamReader &reader, QString fileName, SearchSettings &settings);
    static void readPolygon(QXmlStreamReader &reader, QString fileName, SearchSettings &settings);
    static void readMaterial(QXmlStreamReader &reader, QString fileName, SearchSettings &settings);
    static void readParam(QXmlStreamReader &reader, Material &material);
};

#endif // MATERIALXML_H
