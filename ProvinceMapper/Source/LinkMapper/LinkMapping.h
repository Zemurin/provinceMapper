#ifndef LINK_MAPPING_H
#define LINK_MAPPING_H
#include "Definitions/DefinitionsInterface.h"
#include "LinkBase.h"

enum class Mapping
{
	MAPPED,
	UNMAPPED,
	FAIL
};
struct Province;
class LinkMapping: public LinkBase
{
  public:
	LinkMapping() = default;
	explicit LinkMapping(std::istream& theStream,
		 std::shared_ptr<DefinitionsInterface> theSourceDefs,
		 std::shared_ptr<DefinitionsInterface> theTargetDefs,
		 std::string theSourceToken,
		 std::string theTargetToken,
		 int theID);
	explicit LinkMapping(std::shared_ptr<DefinitionsInterface> theSourceDefs,
		 std::shared_ptr<DefinitionsInterface> theTargetDefs,
		 std::string theSourceToken,
		 std::string theTargetToken,
		 int theID);

	bool operator==(const LinkMapping& rhs) const;

	[[nodiscard]] Mapping toggleSource(const std::string& sourceID);
	[[nodiscard]] Mapping toggleTarget(const std::string& targetID);

	[[nodiscard]] const auto& getSources() const { return sources; }
	[[nodiscard]] const auto& getTargets() const { return targets; }

	friend std::ostream& operator<<(std::ostream& output, const LinkMapping& linkMapping);

  private:
	void registerKeys(commonItems::parser parser);

	std::vector<std::shared_ptr<Province>> sources;
	std::vector<std::shared_ptr<Province>> targets;
	std::shared_ptr<DefinitionsInterface> sourceDefs;
	std::shared_ptr<DefinitionsInterface> targetDefs;
	std::string sourceToken;
	std::string targetToken;
};
std::ostream& operator<<(std::ostream& output, const LinkMapping& linkMapping);
#endif // LINK_MAPPING_H
