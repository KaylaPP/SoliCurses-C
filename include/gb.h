#pragma once

#include "array.h"
#include "board.h"
#include "card.h"
#include "color.h"
#include "cursor.h"

void doinput(Array * gb, int c);

void printGB(Array * gb, Cursor * c);

void refreshGB(Array * gb);
