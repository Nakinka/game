#include "pch.h"
#include "Item.h"
#include "Armor.h"
#include "Character.h"
#include "Enemy.h"
#include "Environment.h"
#include "Game.h"
#include "Player.h"
#include "Level.h"
#include "NPC.h"
#include "Weapon.h"

using namespace testing::internal;
TEST(ConstructorAndGetters,Test1) {
    Item item("Sword", 10, 100);

    ASSERT_EQ(item.getName(), "Sword");
    ASSERT_EQ(item.getWeight(), 10);
    ASSERT_EQ(item.getCost(), 100);
}
TEST(ConstructorAndGetters, Test2) {
    Armor armor("Iron Armor", 15, 200, 50);

    ASSERT_EQ(armor.getName(), "Iron Armor");
    ASSERT_EQ(armor.getWeight(), 15);
    ASSERT_EQ(armor.getCost(), 200);
    ASSERT_EQ(armor.getDefense(), 50);
}

TEST(ConstructorAndGetters, Test3) {
    Character character("Alica", 100, 10, 20);

    ASSERT_EQ(character.getName(), "Alica");
    ASSERT_EQ(character.getHealth(), 100);
    ASSERT_EQ(character.getStrength(), 10);
    ASSERT_EQ(character.getAgility(), 20);
}

TEST(TakeDamage, Test4) {
    Character character("Alica", 100, 10, 20);

    character.takeDamage(30);

    ASSERT_EQ(character.getHealth(), 70);
}

TEST(Heal, Test5) {
    Character character("Alica", 100, 10, 20);

    character.heal(30);

    ASSERT_EQ(character.getHealth(), 130);
}

TEST(Attack, Test6) {
    Character attacker("Leonardo", 100, 10, 20);
    Character target("Enemy", 200, 5, 10);

    attacker.attack(&target);

    ASSERT_EQ(target.getHealth(), 190);
}

TEST(UseItem, Test7) {
    Character character("Alica", 100, 10, 20);
    Item item("Potion", 0, 30);

    character.useItem(&item);

    ASSERT_EQ(character.getHealth(), 70);
}

TEST(ConstructorAndGetters, Test8) {
    Enemy enemy("Hilichurl", 100, 10, 20, 50);

    ASSERT_EQ(enemy.getName(), "Hilichurl");
    ASSERT_EQ(enemy.getHealth(), 100);
    ASSERT_EQ(enemy.getStrength(), 10);
    ASSERT_EQ(enemy.getAgility(), 20);
    ASSERT_EQ(enemy.getExperience(), 50);
}

TEST(DropLoot, Test9) {
    CaptureStdout();

    Enemy enemy("Hilichurl", 100, 10, 20, 50);

    enemy.dropLoot();
    string output = GetCapturedStdout();

    string expectedOutput =
        "Enemy Hilichurl dropped some loot!\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST(ConstructorAndGetters, Test10) {
    Environment environment("Sunny", "Day");

    ASSERT_EQ(environment.getWeather(), "Sunny");
    ASSERT_EQ(environment.getTimeOfDay(), "Day");
}

TEST(ChangeWeatherAndTimeOfDay, Test11) {
    Environment environment("Sunny", "Day");

    environment.changeWeather("Cloudy");
    environment.changeTimeOfDay("Night");

    ASSERT_EQ(environment.getWeather(), "Cloudy");
    ASSERT_EQ(environment.getTimeOfDay(), "Night");
}

TEST(GetNameAndLevel, Test12) {
    Player player("Leonardo", 1);

    EXPECT_EQ(player.getName(), "Leonardo");
    EXPECT_EQ(player.getLevel(), 1);
}

TEST(LevelUp, Test13) {
    Player player("Anton", 1);

    player.levelUp();

    EXPECT_EQ(player.getLevel(), 2);
}

TEST(AddAndRemoveItem, Test14) {
    Player player("Leonardo", 1);
    Item* item = new Item("Mask", 10, 50);

    player.addItem(item);

    EXPECT_EQ(player.getInventory().size(), 1);

    player.removeItem(item);

    EXPECT_EQ(player.getInventory().size(), 0);
    delete item;
}

TEST(EquipAndUnequipItem, Test15) {
    Player player("Leonardo", 1);
    Item* item = new Item("Mask", 10, 50);

    player.equipItem(item);

    EXPECT_EQ(player.getEquippedItems().size(), 1);

    player.unequipItem(item);

    EXPECT_EQ(player.getEquippedItems().size(), 0);
    delete item;
}

TEST(Constructor, Test16) {
    Game game("Bunny", "Novel");

    EXPECT_EQ(game.getName(), "Bunny");
    EXPECT_EQ(game.getGenre(), "Novel");
    EXPECT_EQ(game.getPlayerCount(), 0);
}

TEST(AddPlayer, Test17) {
    Game game("Bunny", "Novel");
    Player* player = new Player("Anton", 1);

    game.addPlayer(player);

    EXPECT_EQ(game.getPlayerCount(), 1);
}

TEST(StartPauseResumeEnd, Test17) {
    Game game("Bunny", "Novel");

    CaptureStdout();
    game.start();
    string output1 = GetCapturedStdout();

    string expectedOutput1 =
        "Game started!\n";

    EXPECT_EQ(output1, expectedOutput1);
    
    CaptureStdout();
    game.pause();
    string output2 = GetCapturedStdout();

    string expectedOutput2 =
        "Paused\n";

    EXPECT_EQ(output2, expectedOutput2);

    CaptureStdout();
    game.resume();
    string output3 = GetCapturedStdout();

    string expectedOutput3 =
        "Game resumed!\n";

    EXPECT_EQ(output3, expectedOutput3);

    CaptureStdout();
    game.end();
    string output4 = GetCapturedStdout();

    string expectedOutput4 =
        "Game over!\n";

    EXPECT_EQ(output4, expectedOutput4);
}

TEST(AddAndRemoveCharacter, Test18) {
    Level level(10, 5);
    Character* character = new  Character("Mikky", 100, 10, 20);

    level.addCharacter(character);

    EXPECT_EQ(level.getCharacterCount(), 1);

    level.removeCharacter(character);

    EXPECT_EQ(level.getCharacterCount(), 0);
    delete character;
}

TEST(AddAndRemoveItem, Test19) {
    Level level(10, 5);
    Item* item = new Item("Sword", 10, 100);

    level.addItem(item);

    EXPECT_EQ(level.getItemCount(), 1);

    level.removeItem(item);

    EXPECT_EQ(level.getItemCount(), 0);
    delete item;
}

TEST(GetSizeAndDifficulty, Test20) {
    Level level(10, 5);

    EXPECT_EQ(level.getSize(), 10);
    EXPECT_EQ(level.getDifficulty(), 5);
}

TEST(TalkNPC, Test21) {
    NPC npc("Kitty", 100, 10, 5, "Hello!");

    CaptureStdout();
    npc.talk();
    string output = GetCapturedStdout();

    string expectedOutput =
        "NPC says: Hello!\n";

    EXPECT_EQ(output, expectedOutput);
}


TEST(TradeNPC, Test22) {
    NPC npc("Bella", 100, 10, 5, "Hello!");

    CaptureStdout();
    npc.trade();
    string output = GetCapturedStdout();

    string expectedOutput =
        "NPC Bella offers a trade!\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST(GetDamage, Test23) {
    Weapon weapon("TestWeapon", 10, 50, 100);

    EXPECT_EQ(weapon.getDamage(), 100);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
