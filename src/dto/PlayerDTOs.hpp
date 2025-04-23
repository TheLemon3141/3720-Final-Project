#ifndef PLAYER_DTO_hpp
#define PLAYER_DTO_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "CardDTOs.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class PlayerDto : public oatpp::DTO {
    DTO_INIT(PlayerDto, DTO)
    DTO_FIELD(String, name);
    DTO_FIELD(List<Object<CardDto>>, hand);
    DTO_FIELD(Int32, score);
};

class pListDto : public oatpp::DTO {
    DTO_INIT(pListDto, DTO)
    DTO_FIELD(List<Object<PlayerDto>>, players);
};

class WinnerDto : public oatpp::DTO {
    DTO_INIT(WinnerDto, DTO)
    DTO_FIELD(String, name);
    DTO_FIELD(Int32, score);
};

class winnerListDto : public oatpp::DTO {
    DTO_INIT(winnerListDto, DTO)
    DTO_FIELD(List<Object<WinnerDto>>, winners);
};

class StandResponseDto : public oatpp::DTO {
    DTO_INIT(StandResponseDto, DTO);
    DTO_FIELD(String, message);
    DTO_FIELD(Object<PlayerDto>, player);
};

#include OATPP_CODEGEN_END(DTO)

#endif // PLAYER_DTO_hpp
