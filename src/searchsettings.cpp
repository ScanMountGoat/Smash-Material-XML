#include "searchsettings.h"


bool SearchSettings::matchesSearch(ComparisonOperation operation, int value, int compareValue) {
    if (operation == SearchSettings::ComparisonOperation::Equals)
        return value == compareValue;
    else if (operation == SearchSettings::ComparisonOperation::Greater)
        return value > compareValue;
    else if (operation == SearchSettings::ComparisonOperation::GreaterOrEqual)
        return value >= compareValue;
    else if (operation == SearchSettings::ComparisonOperation::Less)
        return value < compareValue;
    else if (operation == SearchSettings::ComparisonOperation::LessOrEqual)
        return value <= compareValue;

    return false;
}

bool SearchSettings::matchesSearch(ComparisonOperation operation, uint value, uint compareValue) {
	if (operation == SearchSettings::ComparisonOperation::Equals)
        return value == compareValue;
	else if (operation == SearchSettings::ComparisonOperation::Greater)
        return value > compareValue;
	else if (operation == SearchSettings::ComparisonOperation::GreaterOrEqual)
        return value >= compareValue;
	else if (operation == SearchSettings::ComparisonOperation::Less)
        return value < compareValue;
	else if (operation == SearchSettings::ComparisonOperation::LessOrEqual)
        return value <= compareValue;

	return false;
}

QList<Material> SearchSettings::filterMaterials() {
	QList<Material> filteredMaterialList;

	for (auto const &material : materialList) {
		bool validMaterial = true;

		// Check flags using the selected flags values and comparison operator.
		if (filterFlags) {
			uint value = material.flags & flags1;
            bool validFlags = SearchSettings::matchesSearch(flagsComparison, value, flags2);
			validMaterial = validMaterial && validFlags;
		}

		if (filterSrc) {
            bool validSrc = SearchSettings::matchesSearch(srcComparison, material.dstFactor,
                                                          dstFactor);
			validMaterial = validMaterial && validSrc;
		}

		if (filterDst) {
            bool validDst = SearchSettings::matchesSearch(dstComparison, material.dstFactor,
                                                          dstFactor);
			validMaterial = validMaterial && validDst;
		}

		if (filterPropertyName) {
			bool validMaterialProperty = material.properties.contains("NU_" + materialProperty);
			validMaterial = validMaterial && validMaterialProperty;
		}

        if (filterAlphaFunc) {
            bool validAlphaFunc = SearchSettings::matchesSearch(alphaFuncComparison,
                                                                material.alphaFunc, alphaFunc);
            validMaterial = validMaterial && validAlphaFunc;
        }

        if (filterAlphaTest) {
            bool validAlphaTest = SearchSettings::matchesSearch(alphaTestComparison,
                                                                material.alphaTest, alphaTest);
            validMaterial = validMaterial && validAlphaTest;
        }

        if (filterTextureCount) {
            bool validTexCount = SearchSettings::matchesSearch(textureComparison,
                                                               material.textureHashes.count(),
                                                               textureCount);
            validMaterial = validMaterial && validTexCount;
        }

        if (filterCullMode) {
            bool validCull = SearchSettings::matchesSearch(cullComparison, material.cullMode,
                                                           cullMode);
            validMaterial = validMaterial && validCull;
        }

		if (validMaterial) {
			filteredMaterialList.append(material);
		}
	}

	return filteredMaterialList;
}
