#include "searchsettings.h"

SearchSettings::SearchSettings()
{

}

void SearchSettings::setFlagsOperation(ComparisonOp comparison)
{
    this->flagsOperation = comparison;
}

void SearchSettings::setFlags1(uint flags1)
{
    this->flags1 = flags1;
}

void SearchSettings::setFlags2(uint flags2)
{
    this->flags2 = flags2;
}

uint SearchSettings::getFlags1()
{
    return flags1;
}

uint SearchSettings::getFlags2()
{
    return flags2;
}

bool SearchSettings::matchesSearch(ComparisonOp operation, int value, int comparisonValue)
{
    if (operation == SearchSettings::ComparisonOp::equals)
        return value == comparisonValue;
    else if (operation == SearchSettings::ComparisonOp::greater)
        return value > comparisonValue;
    else if (operation == SearchSettings::ComparisonOp::gEqual)
        return value >= comparisonValue;
    else if (operation == SearchSettings::ComparisonOp::less)
        return value < comparisonValue;
    else if (operation == SearchSettings::ComparisonOp::lEqual)
        return value <= comparisonValue;

    return false;
}
