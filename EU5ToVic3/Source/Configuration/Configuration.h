#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "ConverterVersion.h"
#include "Parser.h"
#include <string>

class Configuration: commonItems::parser
{
  public:
	Configuration() = default;
	explicit Configuration(const commonItems::ConverterVersion& converterVersion);
	explicit Configuration(std::istream& theStream, const commonItems::ConverterVersion& converterVersion);

	enum class STARTDATE
	{
		Vanilla = 1,
		Dynamic = 2
	};

	struct ConfigBlock
	{
		STARTDATE startDate = STARTDATE::Vanilla;
	} configBlock;

	void setOutputName(const std::string& name) { outputName = name; }
	void setVanillaStartDate() { configBlock.startDate = STARTDATE::Vanilla; }

	[[nodiscard]] const auto& getEU5SaveGamePath() const { return EU5SaveGamePath; }
	[[nodiscard]] const auto& getEU5Path() const { return EU5Path; }
	[[nodiscard]] const auto& getEU5DocumentsPath() const { return EU5DocumentsPath; }
	[[nodiscard]] const auto& getVic3Path() const { return Vic3Path; }
	[[nodiscard]] const auto& getOutputName() const { return outputName; }

  private:
	void registerKeys();
	void verifyEU5Path() const;
	void verifyVic3Path();
	void setOutputName();
	void verifyVic3Version(const commonItems::ConverterVersion& converterVersion) const;
	void verifyEU5Version(const commonItems::ConverterVersion& converterVersion) const;

	// options from configuration.txt
	std::string EU5SaveGamePath;
	std::string EU5Path;
	std::string EU5DocumentsPath;
	std::string Vic3Path;
	std::string outputName;
};

#endif // CONFIGURATION_H
