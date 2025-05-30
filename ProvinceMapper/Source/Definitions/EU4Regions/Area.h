#ifndef EU4_AREA_H
#define EU4_AREA_H
#include <Parser.h>
#include <set>

namespace EU4
{
class Area: commonItems::parser
{
  public:
	Area() = default;
	explicit Area(std::istream& theStream);

	[[nodiscard]] const auto& getProvinces() const { return provinces; }
	[[nodiscard]] bool areaContainsProvince(const std::string& province) const;

  private:
	void registerKeys();

	std::set<std::string> provinces;
};
} // namespace EU4

#endif // EU4_AREA_H