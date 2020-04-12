#pragma once

#include "array.h"
#include "board.h"
#include "card.h"
#include "color.h"
#include "cursor.h"

static void printBackground(void);

static void printCard(int y, int x, card * c);

static void printHiddenCard(int y, int x);

void printGB(Array * gb, Cursor * c);

void refreshGB(Array * gb);
