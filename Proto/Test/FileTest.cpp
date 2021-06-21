#pragma once

#include "FileTest.h"

namespace test {

	std::string FileTest::GetClassLevelFileString() const
	{
		return R"json(
		{
			class_levels : [
				{
					name : "Warrior",
					level : "1",
					abilities : [
						{
							name : "Strike"
							spell_type : "ATTACK_SINGLE_TARGET";
							max_targets : "1",
							attribute_modifications : [
								{
									attribute_type : "LIFE",
									current : "10",
									max : "15
								}
							],
							cooldown_s : "2.0",
							range_m : "1.0"
						}
					]
				}
			]
		}
		)json";
	}

	std::string FileTest::GetCharacterFileString() const
	{
		return {};
	}

	std::string FileTest::GetMonsterFileString() const
	{
		return {};
	}

	TEST_F(FileTest, ClassLevelFileTest)
	{
		gameplay_system::ClassLevelFile class_level_file{};
		class_level_file = 
			proto::LoadProtoFromJsonString<gameplay_system::ClassLevelFile>(
				GetClassLevelFileString());
		EXPECT_FALSE(class_level_file.class_levels().empty());
	}

	TEST_F(FileTest, CharacterFileTest)
	{
		gameplay_system::CharacterFile character_file{};
		character_file = 
			proto::LoadProtoFromJsonString<gameplay_system::CharacterFile>(
				GetCharacterFileString());
		EXPECT_FALSE(character_file.characters().empty());
	}

	TEST_F(FileTest, MonsterFileTest)
	{
		gameplay_system::MonsterFile monster_file{};
		monster_file = 
			proto::LoadProtoFromJsonString<gameplay_system::MonsterFile>(
				GetMonsterFileString());
		EXPECT_FALSE(monster_file.monsters().empty());
	}

}