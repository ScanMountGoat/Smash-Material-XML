#ifndef MATERIALXMLFILE_H
#define MATERIALXMLFILE_H

#include "material.h"

#include<QList>
#include<QString>

class MaterialXmlFile
{
public:
    MaterialXmlFile();

private:
    QString fileName = "";
    QList<Material> materialList;
};

#endif // MATERIALXMLFILE_H
