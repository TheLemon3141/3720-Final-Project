#ifndef GAME_START_hpp
#define GAME_START_hpp

#include "oatpp-test/UnitTest.hpp"

class GameStartTest : public oatpp::test::UnitTest {
  public:
    GameStartTest() : UnitTest("TEST[gameServer - Start]") {}
    void onRun() override;
};

class StandActionTest : public oatpp::test::UnitTest {
  public:
    StandActionTest() : UnitTest("TEST[CardServer - Stand]") {}
    void onRun() override;
};

class GameWinnersTest : public oatpp::test::UnitTest {
  public:
    GameWinnersTest() : UnitTest("TEST[CardServer - getWinners]") {}
    void onRun() override;
};

class HitActionTest : public oatpp::test::UnitTest {
  public:
   HitActionTest() : UnitTest("TEST[CardServer - Hit]") {}
   void onRun() override;
};

class DealerDecision : public oatpp::test::UnitTest {
  public:
   DealerDecision() : UnitTest("TEST[gameServer - dealerDecision]") {}
   void onRun() override;
};

#endif // GAME_START_hpp

