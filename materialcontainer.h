#ifndef MATERIALCONTAINER_H
#define MATERIALCONTAINER_H

#include "material.h"
#include <QList>

class MaterialContainer
{
public:
    MaterialContainer();
    static QList<Material> materialList;
};

#endif // MATERIALCONTAINER_H
