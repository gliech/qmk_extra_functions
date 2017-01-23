#include <stdint.h>

#define IS_LAYER_ON(layer) (layer_state & (1UL << (layer)))

void update_shift_tri_layer(uint8_t shiftlayer, uint8_t nonshiftlayer, uint8_t twinlayer);
