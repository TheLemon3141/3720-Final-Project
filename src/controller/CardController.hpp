#ifndef CardController_hpp
#define CardController_hpp

#include <memory>
#include <vector>
#include <string>

#include "../dto/CardDTOs.hpp"
#include "../dto/PlayerDTOs.hpp"
// include dtos here like the example above

#include "../../include/controller/Game.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/server/api/ApiController.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

UI* myUI = new UI();
Game* myGame = new Game(myUI); //Global game object.

/**
* Constructor with object mapper.
* @param objectMapper - default object mapper used to serialize/deserialize
* DTOs.
*/
class CardController : public oatpp::web::server::api::ApiController {
 public:
    CardController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

    ADD_CORS(startGame) // ADD_CORS is needed for each GET
    ENDPOINT("GET", "/start", startGame) {
      delete myGame;
      myUI = new UI();
      myGame = new Game(myUI);

      myGame->addPlayer(new Player("Player 1"));
      myGame->addPlayer(new Player("Dealer"));

      myGame->init();

      return createResponse(Status::CODE_200, "Game Created");
    } //To test: http://localhost:8100/start

    ADD_CORS(gameState);
    ENDPOINT("GET", "/game_state", gameState) {
      auto playerList = pListDto::createShared();

      std::vector<Player*> gamePlayers = myGame->getPlayers();

      playerList->players = {};
      for (auto player : gamePlayers) {
        auto playerDto = PlayerDto::createShared();
        playerDto->hand = {};
        playerDto->name = player->getName();
        playerDto->score = player->getHand().getTotal();
        Hand playerHand = player->getHand();
        std::vector<Card*> cards = playerHand.getCards();
        for (auto card : cards) {
          auto cardDto = CardDto::createShared();
          cardDto->rank = myUI->rank_name(card->getRank());
          cardDto->suit = myUI->suit_name(card->getSuit());
          playerDto->hand->push_back(cardDto);
        }
        playerList->players->push_back(playerDto);
      }

      return createDtoResponse(Status::CODE_200, playerList);
    } //To test: http://localhost:8100/game_state

    /**
    * @brief Returns a winnerListDTO.
    * @returns a list of winner DTOs with the names and scores of winners.
    */
    ADD_CORS(getWinners) // Needed to allow for cross domain access
    ENDPOINT("GET", "/getWinners", getWinners) {
      auto winningPlayers = winnerListDto::createShared();
      std::vector<Player*> winnerVector = myGame->getWinners();
      winningPlayers->winners = {};
      for (auto it : winnerVector) {
        auto tempWinnerDto = WinnerDto::createShared();
        tempWinnerDto->name = it->getName();
        tempWinnerDto->score = it->getHand().getTotal();
        winningPlayers->winners->push_back(tempWinnerDto);
      }
      return createDtoResponse(Status::CODE_200, winningPlayers);
    } // To test: http://localhost:8100/getWinners

    ADD_CORS(standAction)
    ENDPOINT("GET", "/stand", standAction,
    REQUEST(std::shared_ptr<IncomingRequest>, request)) {
      auto playerName = request->getQueryParameter("playerName", "Player 1");

      Player* player = nullptr;
      for (auto& p : myGame->getPlayers()) {
          if (oatpp::String(p->getName()) == playerName) {
              player = p;
              break;
          }
      }
      if (player == nullptr) {
        return createResponse(Status::CODE_404, "Player not found");
      }

      myGame->performAction(playerName, "stand");
      auto playerDto = PlayerDto::createShared();
      playerDto->name = playerName;
      playerDto->hand = List<Object<CardDto>>::createShared();
      for (Player* player : myGame->getPlayers()) {
        if (oatpp::String(player->getName()) == playerName) {
          Hand playerHand = player->getHand();
          std::vector<Card*> cards = playerHand.getCards();
          for (auto card : cards) {
            auto cardDto = CardDto::createShared();
            cardDto->rank = myUI->rank_name(card->getRank());
            cardDto->suit = myUI->suit_name(card->getSuit());
            playerDto->hand->push_back(cardDto);
          }
          break;
        }
      }
      auto standResponse = StandResponseDto::createShared();
      standResponse->message = "Player 1 decided to stand";
      standResponse->player = playerDto;

      return createDtoResponse(Status::CODE_200, standResponse);
  }

  ADD_CORS(hitAction)
  ENDPOINT("GET", "/hit", hitAction,
           REQUEST(std::shared_ptr<IncomingRequest>, request)) {
    auto playerName = request->getQueryParameter("playerName", "Player 1");

    Player* player = nullptr;
    for (auto& p : myGame->getPlayers()) {
        if (oatpp::String(p->getName()) == playerName) {
            player = p;
            break;
        }
    }
    if (player == nullptr) {
      return createResponse(Status::CODE_404, "Player not found");
    }

    if (player) {
      if (player->getHand().getTotal() > 21) {
        return createResponse(Status::CODE_400, "You have busted.");
      }
    }
    myGame->performAction(playerName, "hit");

    auto playerDto = PlayerDto::createShared();
    playerDto->name = playerName;
    playerDto->hand = List<Object<CardDto>>::createShared();
    for (Player* player : myGame->getPlayers()) {
      if (oatpp::String(player->getName()) == playerName) {
        Hand playerHand = player->getHand();
        std::vector<Card*> cards = playerHand.getCards();
        for (auto card : cards) {
          auto cardDto = CardDto::createShared();
          cardDto->rank = myUI->rank_name(card->getRank());
          cardDto->suit = myUI->suit_name(card->getSuit());
          playerDto->hand->push_back(cardDto);
        }
        break;
      }
    }

    auto standResponse = StandResponseDto::createShared();
    standResponse->message = "Player 1 decided to hit";
    standResponse->player = playerDto;

    return createDtoResponse(Status::CODE_200, standResponse);
  }

  ADD_CORS(dealer)
  ENDPOINT("GET", "/dealer", dealer) {
    std::vector<Player*> players = myGame->getPlayers();
    Player* dealer = nullptr;

    for (auto player : players) {
      if (player->getName() == "Dealer")
        dealer = player;
    }
    if (dealer == nullptr)
      return createResponse(Status::CODE_404, "Dealer not found");

    while (true) {
      std::string decision = myGame->dealerDecision(&dealer->getHand());

      myGame->performAction(dealer->getName(), decision);

      if (decision == "stand")
        return createResponse(Status::CODE_200, "Dealer turn over");

      if (dealer->getHand().getCards().size() > 6)
        return createResponse(Status::CODE_500, "Dealer failed to stand");
    }
  }
};  // End of CardController

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif /* Card_Controller_hpp */
