#pragma once
// This is just an helpfull header that include all the protos.

#include <fstream>
// This is there to avoid most of the warnings.
#if defined(_WIN32) || defined(_WIN64)
#pragma warning(push)
#pragma warning(disable: 4005)
#pragma warning(disable: 4244)
#pragma warning(disable: 4251)
#pragma warning(disable: 4275)
#pragma warning(disable: 4996)
#endif
#include "File.pb.h"
#include "GameplaySystem.pb.h"
// Include the json parser.
#include <google/protobuf/util/json_util.h>
#if defined(_WIN32) || defined(_WIN64)
#pragma warning(pop)
#endif

namespace proto {

	template <typename T>
	T LoadProtoFromJsonString(const std::string& content)
	{
		T proto{};
		google::protobuf::util::JsonParseOptions options{};
		options.ignore_unknown_fields = false;
		auto status = google::protobuf::util::JsonStringToMessage(
			content,
			&proto,
			options);
		if (!status.ok())
		{
			throw std::runtime_error(
				"Couldn't parse file status error: [" + 
				status.error_message().as_string() + "].");
		}
		return proto;
	}

	template <typename T>
	T LoadProtoFromJsonFile(const std::string& file_name)
	{
		// Empty case (no such file return an empty structure).
		if (file_name.empty()) 
		{
			throw std::runtime_error("No filename");
		}
		// Try to open it.
		std::ifstream ifs_level(file_name.c_str(), std::ios::in);
		if (!ifs_level.is_open())
			throw std::runtime_error("Couldn't open file: " + file_name);
		std::string content(std::istreambuf_iterator<char>(ifs_level), {});
		return LoadProtoFromJsonString<T>(content);
	}

} // End namespace gameplay_system.
