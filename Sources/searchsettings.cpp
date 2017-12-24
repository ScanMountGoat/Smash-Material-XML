#include "Headers/searchsettings.h"

SearchSettings::SearchSettings()
{

}

void SearchSettings::setFlagsOperation(flagsComparison comparison) {
    this->flagsOperation = comparison;
}

void SearchSettings::setFlags1(uint flags1) {
    this->flags1 = flags1;
}

void SearchSettings::setFlags2(uint flags2) {
    this->flags2 = flags2;
}

uint SearchSettings::getFlags1() {
    return flags1;
}

uint SearchSettings::getFlags2() {
    return flags2;
}
