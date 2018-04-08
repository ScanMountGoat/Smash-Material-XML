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
        LessOrEqual = 4
    };

	// Settings for filtering materials.
	uint flags1 = 0xFFFFFFFF;
	uint flags2 = 0xFFFFFFFF;
	ComparisonOperation flagsOperation;
    bool filterFlags = false;
    bool filterSrc = false;
    bool filterDst = false;
    bool filterPropertyName = false;

    int dstFactor = 0;
    int srcFactor = 0;
    QString materialProperty = "";

	// Settings for what properties to display.
	bool displaySrc = false;
	bool displayDst = false;
	bool displayFlags = false;
	bool displayFileName = true;
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
