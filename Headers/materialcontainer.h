#ifndef MATERIALCONTAINER_H
#define MATERIALCONTAINER_H

#include "material.h"
#include <QList>
#include <QHash>

extern QList<Material> materialList;
extern QHash<QString, QList<Material>> xmlFiles;

class MaterialContainer
{
public:
    MaterialContainer();
};

#endif // MATERIALCONTAINER_H
