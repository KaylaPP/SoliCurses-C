#pragma once

#ifndef _MSVC_TRADITIONAL
// Strings that represent different UTF-8 characters for card suits
static const char suit_ch[4][4] =
{
    {'\xE2', '\x99', '\xA0', '\0'}, // Spade
    {'\xE2', '\x99', '\xA6', '\0'}, // Diamond
    {'\xE2', '\x99', '\xA3', '\0'}, // Club
    {'\xE2', '\x99', '\xA5', '\0'}  // Heart
};

#else

#include <wchar.h>
// Strings that represent different UTF-16 characters for card suits
static const wchar_t suit_ch[4][2] =
{
    L"♠", // Spade
    L"♦", // Diamond
    L"♣", // Club
    L"♥"  // Heart
};

#endif
