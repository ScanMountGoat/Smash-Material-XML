#ifndef MATERIALXML_H
#define MATERIALXML_H
#include <QString>

class MaterialXml
{
public:
    MaterialXml(QString fileName);
    static void MaterialDataFromXML(QString fileName);

};

#endif // MATERIALXML_H
