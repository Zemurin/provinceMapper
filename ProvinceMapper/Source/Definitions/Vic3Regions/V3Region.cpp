#include "V3Region.h"
#include <CommonRegexes.h>
#include <ParserHelpers.h>

void V3::Region::initializeRegion(std::istream& theStream)
{
	registerKeys();
	parseStream(theStream);
	clearRegisteredKeywords();
}

void V3::Region::registerKeys()
{
	registerKeyword("states", [this](std::istream& theStream) {
		for (const auto& stateName: commonItems::getStrings(theStream))
			states.emplace(stateName);
	});
	registerRegex(commonItems::catchallRegex, commonItems::ignoreItem);
}
