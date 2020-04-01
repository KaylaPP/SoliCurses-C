#pragma once

// Strings that represent difference UTF-8 characters for card suits

#ifndef _MSVC_TRADITIONAL

const char suit_ch[4][4] =
{
    {'\xE2', '\x99', '\xA0', '\0'}, // Spade
    {'\xE2', '\x99', '\xA6', '\0'}, // Diamond
    {'\xE2', '\x99', '\xA3', '\0'}, // Club
    {'\xE2', '\x99', '\xA5', '\0'}  // Heart
};

#else

#include <wchar.h>
const wchar_t suit_ch[4] =
{
    L'♠', // Spade
    L'♦', // Diamond
    L'♣', // Club
    L'♥'  // Heart
};

#endif
