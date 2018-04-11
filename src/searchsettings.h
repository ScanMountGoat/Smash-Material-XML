#ifndef SEARCHSETTINGS_H
#define SEARCHSETTINGS_H

#include "material.h"

#include <QString>
#include <QList>

class SearchSettings
{
public:
    QList<Material> materialList;

    enum class ComparisonOperation {
        Equals = 0,
        Greater = 1,
        GreaterOrEqual = 2,
        Less = 3,
        LessOrEqual = 4,
		NotEqual = 5
    };

	// Material Flags
	bool filterFlags = false;
	uint flags1 = 0xFFFFFFFF;
	uint flags2 = 0xFFFFFFFF;
	ComparisonOperation flagsOperation = ComparisonOperation::Equals;;

	// Dst Factor
	bool filterDst = false;
    int dstFactor = 0;
	ComparisonOperation dstOperation = ComparisonOperation::Equals;

	// Src Factor
	bool filterSrc = false;
    int srcFactor = 0;
	ComparisonOperation srcOperation = ComparisonOperation::Equals;

	// Cull Mode
	bool filterCullMode = false;
	int cullMode = 0;
	ComparisonOperation cullOperation = ComparisonOperation::Equals;

	// NU_ Material Property
	bool filterPropertyName = false;
    QString materialProperty = "";

	// Alpha Func
	bool filterAlphaFunc = false;
	int alphaFunc = 0;
	ComparisonOperation alphaFuncOperation = ComparisonOperation::Equals;

	// Alpha Test
	bool filterAlphaTest = false;
	int alphaTest = 0;
	ComparisonOperation alphaTestOperation = ComparisonOperation::Equals;

	// Texture Count
	bool filterTextureCount = false;
	int textureCount = 0;
	ComparisonOperation textureCountOperation = ComparisonOperation::Equals;

	// Settings for what properties to display.
	bool displaySrc = false;
	bool displayDst = false;
	bool displayFlags = false;
	bool displayFileName = false;
	bool displayTextureHashes = false;
	bool displayCullMode = false;

	enum class PropertDisplay {
		None = 0,
		Selected = 1,
		All = 2
	};
	PropertDisplay propertyDisplayMode = PropertDisplay::None;

    static bool matchesSearch(ComparisonOperation operation, int value, int comparisonValue);

	static bool matchesSearch(ComparisonOperation operaration, uint value, uint comparisonValue);

	QList<Material> filterMaterials();
};

#endif // SEARCHSETTINGS_H
