#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "Definitions/DefinitionsInterface.h"
#include "LinkBase.h"

enum class Mapping
{
	MAPPED,
	UNMAPPED,
	FAIL
};
class Province;
class LinkMapping final: public LinkBase
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
	explicit LinkMapping(std::shared_ptr<DefinitionsInterface> theSourceDefs,
		 std::shared_ptr<DefinitionsInterface> theTargetDefs,
		 std::string theSourceToken,
		 std::string theTargetToken,
		 int theID,
		 bool autogenerated);

	void addSource(const std::string& sourceID);
	void addTarget(const std::string& targetID);
	[[nodiscard]] Mapping toggleSource(const std::string& sourceID);
	[[nodiscard]] Mapping toggleTarget(const std::string& targetID);

	[[nodiscard]] const auto& getSources() const { return sources; }
	[[nodiscard]] const auto& getTargets() const { return targets; }

	[[nodiscard]] const std::string toRowString() override;
	[[nodiscard]] const std::string toRowStringForSearchFrame() const;
	[[nodiscard]] const wxColour getBaseRowColour() override;
	[[nodiscard]] auto getActiveRowColour() -> const wxColour override;

	[[nodiscard]] bool isAutogenerated() const { return autogenerated; }

	friend std::ostream& operator<<(std::ostream& output, const LinkMapping& linkMapping);

  private:
	void registerKeys(commonItems::parser& parser);

	std::vector<std::shared_ptr<Province>> sources;
	std::vector<std::shared_ptr<Province>> targets;
	std::shared_ptr<DefinitionsInterface> sourceDefs;
	std::shared_ptr<DefinitionsInterface> targetDefs;
	std::string sourceToken;
	std::string targetToken;
	bool autogenerated = false;
};
std::ostream& operator<<(std::ostream& output, const LinkMapping& linkMapping);