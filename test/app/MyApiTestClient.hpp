#ifndef MyApiTestClient_hpp
#define MyApiTestClient_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/client/ApiClient.hpp"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Test API client.
 * Use this client to call application APIs.
 */
 class MyApiTestClient : public oatpp::web::client::ApiClient {
    API_CLIENT_INIT(MyApiTestClient)

    API_CALL("GET", "/start", gameStart)
    API_CALL("GET", "/game_state", gameState)
    API_CALL("GET", "/stand", standAction, BODY_STRING(String, body))
    API_CALL("GET", "/testGameState", testGameState)
    API_CALL("GET", "/getWinners", getWinners)
    API_CALL("GET", "/hit", hitAction, BODY_STRING(String, body))
    API_CALL("GET", "/dealer", doDealer)
  };

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

#endif  // MyApiTestClient_hpp
