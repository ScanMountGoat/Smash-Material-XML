#include "searchsettings.h"


bool SearchSettings::matchesSearch(ComparisonOperation operation, int value, int comparisonValue)
{
    if (operation == SearchSettings::ComparisonOperation::Equals)
        return value == comparisonValue;
    else if (operation == SearchSettings::ComparisonOperation::Greater)
        return value > comparisonValue;
    else if (operation == SearchSettings::ComparisonOperation::GreaterOrEqual)
        return value >= comparisonValue;
    else if (operation == SearchSettings::ComparisonOperation::Less)
        return value < comparisonValue;
    else if (operation == SearchSettings::ComparisonOperation::LessOrEqual)
        return value <= comparisonValue;

    return false;
}

bool SearchSettings::matchesSearch(ComparisonOperation operation, uint value, uint comparisonValue) 
{
	if (operation == SearchSettings::ComparisonOperation::Equals)
		return value == comparisonValue;
	else if (operation == SearchSettings::ComparisonOperation::Greater)
		return value > comparisonValue;
	else if (operation == SearchSettings::ComparisonOperation::GreaterOrEqual)
		return value >= comparisonValue;
	else if (operation == SearchSettings::ComparisonOperation::Less)
		return value < comparisonValue;
	else if (operation == SearchSettings::ComparisonOperation::LessOrEqual)
		return value <= comparisonValue;

	return false;
}

QList<Material> SearchSettings::filterMaterials() {
	QList<Material> filteredMaterialList;

	for (auto const &material : materialList) {
		bool validMaterial = true;

		// Check flags using the selected flags values and comparison operator.
		if (filterFlags) {
			uint value = material.flags & flags1;
			bool validFlags = SearchSettings::matchesSearch(flagsOperation, value, flags2);
			validMaterial = validMaterial && validFlags;
		}

		if (filterSrc) {
			bool validSrc = SearchSettings::matchesSearch(srcOperation, material.dstFactor, dstFactor);
			validMaterial = validMaterial && validSrc;
		}

		if (filterDst) {
			bool validDst = SearchSettings::matchesSearch(dstOperation, material.dstFactor, dstFactor);
			validMaterial = validMaterial && validDst;
		}

		if (filterPropertyName) {
			bool validMaterialProperty = material.properties.contains("NU_" + materialProperty);
			validMaterial = validMaterial && validMaterialProperty;
		}

		if (validMaterial) {
			filteredMaterialList.append(material);
		}
	}

	return filteredMaterialList;
}
