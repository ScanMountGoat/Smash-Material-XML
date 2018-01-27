#ifndef MATERIALXML_H
#define MATERIALXML_H

#include "materialxml.h"
#include "material.h"

#include <QString>
#include <QList>
#include <QXmlStreamReader>


class MaterialXml
{
public:
    MaterialXml();
    static void addMaterialsFromXML(QString fileName);
    static void readMesh(QXmlStreamReader &reader, QString fileName);
    static void readPolygon(QXmlStreamReader &reader, QString fileName);
    static void readMaterial(QXmlStreamReader &reader, QString fileName);
    static void readParam(QXmlStreamReader &reader, Material material);
};

#endif // MATERIALXML_H
