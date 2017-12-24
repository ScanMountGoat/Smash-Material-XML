#ifndef SEARCHSETTINGS_H
#define SEARCHSETTINGS_H

#include <QString>

class SearchSettings
{
public:
    SearchSettings();

    enum flagsComparison {
        equals = 0,
        greater = 1,
        gEqual = 2,
        less = 3,
        lEqual = 4
    };

    bool filterFlags = false;

    void setFlagsOperation(flagsComparison comparison);
    void setFlags1(uint flags1);
    void setFlags2(uint flags2);
    uint getFlags1();
    uint getFlags2();

private:
    // flags
    uint flags1 = 0xFFFFFFFF;
    uint flags2 = 0xFFFFFFFF;
    flagsComparison flagsOperation;
};

#endif // SEARCHSETTINGS_H
