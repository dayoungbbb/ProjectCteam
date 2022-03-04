#pragma once
#define PhoneNumSize 3
#define NameSize 2
#define BirthdaySize 8

enum CmdType {
    NONE = 0,
    ADD,
    DEL,
    SCH,
    MOD,
    MAX_CMDTYPE
};

int cmdParameterSize[MAX_CMDTYPE] = {0, 10, 6, 6, 8};
