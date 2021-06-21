#pragma once

#include <gtest/gtest.h>
#include "Proto/Proto.h"

namespace test {

	class FileTest : public testing::Test {
	public:
		FileTest() = default;
		std::string GetClassLevelFileString() const;
		std::string GetCharacterFileString() const;
		std::string GetMonsterFileString() const;
	};

}