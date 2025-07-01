// Copyright (c) Eric Jeker. All Rights Reserved.

#include "Managers/FileManager.h"

#include <fstream>

#include "nlohmann/json.hpp"

json FileManager::LoadJSON(const std::string& filePath)
{
	std::ifstream f(filePath);
	return json::parse(f);
}
