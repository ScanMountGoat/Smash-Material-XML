#ifndef SEARCHSETTINGS_H
#define SEARCHSETTINGS_H

#include "material.h"

#include <QString>
#include <QList>

class SearchSettings
{
public:
    SearchSettings();

    QList<Material> materialList;

    enum class ComparisonOperation {
        equals = 0,
        greater = 1,
        gEqual = 2,
        less = 3,
        lEqual = 4
    };

	uint flags1 = 0xFFFFFFFF;
	uint flags2 = 0xFFFFFFFF;
	ComparisonOperation flagsOperation;
    bool searchFlags = false;
    bool searchSrc = false;
    bool searchDst = false;
    bool searchMatProp = false;

    int dstFactor = 0;
    int srcFactor = 0;
    QString materialProperty = "";

    static bool matchesSearch(ComparisonOperation operation, int value, int comparisonValue);
};

#endif // SEARCHSETTINGS_H
