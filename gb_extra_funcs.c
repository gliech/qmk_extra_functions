#include "gb_extra_funcs.h"
#include "action_layer.h"

void update_shift_tri_layer(uint8_t shiftlayer, uint8_t nonshiftlayer, uint8_t twinlayer){
  if (IS_LAYER_ON(shiftlayer) && IS_LAYER_ON(nonshiftlayer)) {
    unregister_mods(MOD_BIT(KC_LSFT));
    layer_on(twinlayer);
  } else {
    layer_off(twinlayer);
    if (IS_LAYER_ON(shiftlayer)) {
      register_mods(MOD_BIT(KC_LSFT));
    };
  }
};
