
#include "GameStartTest.hpp"

#include <memory>

#include "../src/controller/CardController.hpp"

#include "../app/MyApiTestClient.hpp"
#include "../app/TestComponent.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"

#include <iostream>

void GameStartTest::onRun() {
    /* Register test components */
    TestComponent component;

    /* Create client-server tests runner */
    oatpp::test::web::ClientServerTestRunner runner;

    /* Get object mapper component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
    objectMapper);

    /* Add CardController endpoints to the router of the test server */
    runner.addController(std::make_shared<CardController>());

    /* Run Test */
    runner.run(
    [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
        std::shared_ptr<oatpp::network::ClientConnectionProvider>,
        clientConnectionProvider);

        /* Get Object mapper component*/
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
        objectMapper);
        /* Create http request executor for Api Client */
        auto requestExecutor =
        oatpp::web::client::HttpRequestExecutor::createShared(
        clientConnectionProvider);
        /* Create Test API client */
        auto client =
        MyApiTestClient::createShared(requestExecutor, objectMapper);

        /* Call server API */
        auto response = client->gameStart();
        /* Assert that server response with 200 */
        OATPP_ASSERT(response->getStatusCode() == 200);

        /* Get game state response */
        response = client->gameState();
        OATPP_ASSERT(response->getStatusCode() == 200);

        /* Read response body as MessageDto */
        auto message =
        response->readBodyToDto<oatpp::Object<pListDto>>(objectMapper.get());
        // Assert that response exists
        OATPP_ASSERT(message);
        // Assert that there are two players
        OATPP_ASSERT(message->players->size() == 2);
        // Assert that each player has 2 cards
        for (auto player : *message->players)
        OATPP_ASSERT(player->hand->size() == 2);
    },
    std::chrono::minutes(10));

    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void StandActionTest::onRun() {
    /* Register test components */
    TestComponent component;
    /* Create client-server test runner */
    oatpp::test::web::ClientServerTestRunner runner;
    /* Add CardController endpoints to the router of the test server */
    runner.addController(std::make_shared<CardController>());
    /* Run test */
    runner.run(
    [this, &runner] {
        /* Get client connection provider for Api Client */
        OATPP_COMPONENT(
        std::shared_ptr<oatpp::network::ClientConnectionProvider>,
        clientConnectionProvider);
        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
        objectMapper);
        /* Create http request executor for Api Client */
        auto requestExecutor =
        oatpp::web::client::HttpRequestExecutor::createShared(
        clientConnectionProvider);
        /* Create Test API client */
        auto client =
        MyApiTestClient::createShared(requestExecutor, objectMapper);
        oatpp::String playerName = "Player 1";
        auto standResponse = client->standAction("playerName=" + playerName);
        OATPP_ASSERT(standResponse->getStatusCode() == 200);
        auto standResponseDto = standResponse->readBodyToDto<oatpp::Object<StandResponseDto>>(objectMapper.get());
        OATPP_ASSERT(standResponseDto);
        OATPP_ASSERT(standResponseDto->message == "Player 1 decided to stand");
        OATPP_ASSERT(standResponseDto->player->name == playerName);
    },
    std::chrono::minutes(10) /* test timeout */);
    /* Wait for all server threads to finish */
    std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void HitActionTest::onRun() {
        /* Register test components */
        TestComponent component;
      
        /* Create client-server test runner */
        oatpp::test::web::ClientServerTestRunner runner;
      
        /* Add CardController endpoints to the router of the test server */
        runner.addController(std::make_shared<CardController>());
      
        /* Run test */
        runner.run(
            [this, &runner] {
              /* Get client connection provider for Api Client */
              OATPP_COMPONENT(
                  std::shared_ptr<oatpp::network::ClientConnectionProvider>,
                  clientConnectionProvider);
      
              /* Get object mapper component */
              OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                              objectMapper);
      
              /* Create http request executor for Api Client */
              auto requestExecutor =
                  oatpp::web::client::HttpRequestExecutor::createShared(
                      clientConnectionProvider);
      
              /* Create Test API client */
              auto client =
                  MyApiTestClient::createShared(requestExecutor, objectMapper);
      
              oatpp::String playerName = "Player 1";
              auto standResponse = client->hitAction("playerName=" + playerName);
              OATPP_ASSERT(standResponse->getStatusCode() == 200);
             
              auto standResponseDto = standResponse->readBodyToDto<oatpp::Object<StandResponseDto>>(objectMapper.get());
              OATPP_ASSERT(standResponseDto);
              OATPP_ASSERT(standResponseDto->message == "Player 1 decided to hit");
              OATPP_ASSERT(standResponseDto->player->name == playerName);
      
            },
            std::chrono::minutes(10) /* test timeout */);
      
        /* Wait for all server threads to finish */
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

      void GameWinnersTest::onRun() {
        /* Register test components */
        TestComponent component;
    
        /* Create client-server tests runner */
        oatpp::test::web::ClientServerTestRunner runner;
    
        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
        objectMapper);
    
        /* Add CardController endpoints to the router of the test server */
        runner.addController(std::make_shared<CardController>());
    
        /* Run Test */
        runner.run(
        [this, &runner] {
            /* Get client connection provider for Api Client */
            OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);
    
            /* Get Object mapper component*/
            OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
            objectMapper);
            /* Create http request executor for Api Client */
            auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
            clientConnectionProvider);
            /* Create Test API client */
            auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);
    
            //myGame->testGameSetup();
            /* Get a test game state response */
            auto gameState = client->gameState();
            OATPP_ASSERT(gameState->getStatusCode() == 200);
    
            /* Call server API */
            auto response = client->getWinners();
    
            /* Assert that server response with 200 */
            OATPP_ASSERT(response->getStatusCode() == 200);
    
            /* Read response body as MessageDto */
            auto winnerList = response->readBodyToDto<oatpp::Object<winnerListDto>>(objectMapper.get());
            // Assert that response exists
            OATPP_ASSERT(winnerList);
            // Assert that there is one winner
            OATPP_ASSERT(winnerList->winners->size() == 1);
            // Assert that the winning player has a name "Player 1"
            OATPP_ASSERT(winnerList->winners[0]->name == "Player 1");
    
            // Assert that the winning player has a score of 21
            OATPP_ASSERT(winnerList->winners[0]->score == 21);
        },
        std::chrono::minutes(10));
    
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void DealerDecision::onRun() {
        /* Register test components */
        TestComponent component;
    
        /* Create client-server tests runner */
        oatpp::test::web::ClientServerTestRunner runner;
    
        /* Get object mapper component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
        objectMapper);
    
        /* Add CardController endpoints to the router of the test server */
        runner.addController(std::make_shared<CardController>());
    
        /* Run Test */
        runner.run(
        [this, &runner] {
            /* Get client connection provider for Api Client */
            OATPP_COMPONENT(
            std::shared_ptr<oatpp::network::ClientConnectionProvider>,
            clientConnectionProvider);
    
            /* Get Object mapper component*/
            OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
            objectMapper);
            /* Create http request executor for Api Client */
            auto requestExecutor =
            oatpp::web::client::HttpRequestExecutor::createShared(
            clientConnectionProvider);
            /* Create Test API client */
            auto client =
            MyApiTestClient::createShared(requestExecutor, objectMapper);
            
            /* Create new game */
            auto start = client->gameStart();
            OATPP_ASSERT(start->getStatusCode() == 200);

            /* Call dealer */
            auto dealerTurn = client->doDealer();
            OATPP_ASSERT(dealerTurn->getStatusCode() == 200);

            /* Get dealer score*/
            auto state = client->gameState();
            OATPP_ASSERT(state->getStatusCode() == 200);
            auto pList = state->readBodyToDto<oatpp::Object<pListDto>>(objectMapper.get());
            OATPP_ASSERT(pList);
            unsigned score = 0;
            for (auto pDto : *pList->players) {
                if (pDto->name == "Dealer")
                    score = pDto->score;
            }
            OATPP_ASSERT(score != 0);

            /* Dealer should have no less than 17 points */
            OATPP_ASSERT(score > 16);

            /* Dealer should have no more than 27 points (16 + 11) */
            OATPP_ASSERT(score < 27);
        },
        std::chrono::minutes(10));
    
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }