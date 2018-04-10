#ifndef MATERIAL_FILTERING_H
#define MATERIAL_FILTERING_H

#include <QList>
#include "src/material.h"
#include "src/searchsettings.h"

namespace materialfiltering {
	QList<Material> filterMaterials(const SearchSettings &searchSettings);
}

#endif // !MATERIAL_FILTERING_H
