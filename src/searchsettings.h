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

	// Settings for filtering materials.
	bool filterFlags = false;
	uint flags1 = 0xFFFFFFFF;
	uint flags2 = 0xFFFFFFFF;
	ComparisonOperation flagsOperation = ComparisonOperation::Equals;;

	bool filterDst = false;
    int dstFactor = 0;
	ComparisonOperation dstOperation = ComparisonOperation::Equals;

	bool filterSrc = false;
    int srcFactor = 0;
	ComparisonOperation srcOperation = ComparisonOperation::Equals;

	bool filterCullMode = false;
	int cullMode = 0;
	ComparisonOperation cullOperation = ComparisonOperation::Equals;

	bool filterPropertyName = false;
    QString materialProperty = "";

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
};

#endif // SEARCHSETTINGS_H
