#ifndef MATERIALXML_H
#define MATERIALXML_H

#include <QString>
#include <QXmlStreamReader>


class MaterialXml
{
public:
    MaterialXml(QString fileName);
    static void MaterialDataFromXML(QString fileName);
    static void readMaterial(QXmlStreamReader &reader);

};

#endif // MATERIALXML_H
