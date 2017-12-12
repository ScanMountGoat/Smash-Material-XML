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
    static void materialDataFromXML(QString fileName);
    static void readMesh(QXmlStreamReader &reader);
    static void readPolygon(QXmlStreamReader &reader);
    static void readMaterial(QXmlStreamReader &reader);
    static void readParam(QXmlStreamReader &reader, Material material);
};

#endif // MATERIALXML_H
