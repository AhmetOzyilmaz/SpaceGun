#include "Helpers.h"

int Random(int min, int max) {
	return rand() % (max - min) + min;
}