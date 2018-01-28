#ifndef SEARCHSETTINGS_H
#define SEARCHSETTINGS_H

#include "Headers/material.h"

#include <QString>
#include <QList>

class SearchSettings
{
public:
    SearchSettings();

    QList<Material> materialList;

    enum class ComparisonOp {
        equals = 0,
        greater = 1,
        gEqual = 2,
        less = 3,
        lEqual = 4
    };

    bool searchFlags = false;
    bool searchSrc = false;
    bool searchDst = false;
    bool searchMatProp = false;

    int dstFactor = 0;
    int srcFactor = 0;
    QString materialProperty = "";

    void setFlagsOperation(ComparisonOp comparison);
    void setFlags1(uint flags1);
    void setFlags2(uint flags2);
    uint getFlags1();
    uint getFlags2();

    static bool matchesSearch(ComparisonOp operation, int value, int comparisonValue);

private:
    // flags
    uint flags1 = 0xFFFFFFFF;
    uint flags2 = 0xFFFFFFFF;
    ComparisonOp flagsOperation;
};

#endif // SEARCHSETTINGS_H
