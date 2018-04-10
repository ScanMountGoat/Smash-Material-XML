#include "src/materialfiltering.h"

QList<Material> materialfiltering::filterMaterials(const SearchSettings &searchSettings) {
	QList<Material> filteredMaterialList;

	for (auto const &material : searchSettings.materialList) {
		bool validMaterial = true;

		// Check flags using the selected flags values and comparison operator.
		if (searchSettings.filterFlags) {
			uint value = material.flags & searchSettings.flags1;
			bool validFlags = SearchSettings::matchesSearch(searchSettings.flagsOperation, value, searchSettings.flags2);
			validMaterial = validMaterial && validFlags;
		}

		if (searchSettings.filterSrc) {
			bool validSrc = SearchSettings::matchesSearch(searchSettings.srcOperation, material.dstFactor, searchSettings.dstFactor);
			validMaterial = validMaterial && validSrc;
		}

		if (searchSettings.filterDst) {
			bool validDst = SearchSettings::matchesSearch(searchSettings.dstOperation, material.dstFactor, searchSettings.dstFactor);
			validMaterial = validMaterial && validDst;
		}

		if (searchSettings.filterPropertyName) {
			bool validMaterialProperty = material.properties.contains("NU_" + searchSettings.materialProperty);
			validMaterial = validMaterial && validMaterialProperty;
		}

		if (validMaterial) {
			filteredMaterialList.append(material);
		}
	}

	return filteredMaterialList;
}
