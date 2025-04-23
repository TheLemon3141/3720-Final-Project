#ifndef CARD_DTO_hpp
#define CARD_DTO_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class CardDto : public oatpp::DTO {
    DTO_INIT(CardDto, DTO)
    DTO_FIELD(String, rank);
    DTO_FIELD(String, suit);
};

#include OATPP_CODEGEN_END(DTO)

#endif // CARD_DTO_hpp
