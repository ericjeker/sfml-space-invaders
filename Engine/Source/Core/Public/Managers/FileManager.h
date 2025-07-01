// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <nlohmann/json_fwd.hpp>
#include <string>

using json = nlohmann::json;

class FileManager
{
public:
	FileManager() = default;
	~FileManager() = default;

	static json LoadJSON(const std::string& filePath);
};


#endif // FILEMANAGER_H
