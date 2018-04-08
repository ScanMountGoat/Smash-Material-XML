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
