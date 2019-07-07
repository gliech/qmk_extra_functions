#include "shiftlayer.h"
#include "action_layer.h"
#include "quantum.h"

void shiftlayer_on(uint8_t shiftlayer, uint8_t layermods) {
	layer_on(shiftlayer);
	register_mods(layermods);
};

void shiftlayer_off(uint8_t shiftlayer, uint8_t layermods) {
	unregister_mods(layermods);
	layer_off(shiftlayer);
};

void update_tri_shiftlayer(uint8_t shiftlayer, uint8_t nonshiftlayer, uint8_t twinlayer) {
	if (IS_LAYER_ON(shiftlayer) && IS_LAYER_ON(nonshiftlayer)) {
		unregister_mods(MOD_BIT(KC_LSFT));
		layer_on(twinlayer);
	} else {
		layer_off(twinlayer);
		if (IS_LAYER_ON(shiftlayer)) {
			register_mods(MOD_BIT(KC_LSFT));
		};
	};
};

void register_shiftlayer_code(uint8_t code, uint8_t layermods, uint8_t mods) {
	set_mods( ( get_mods() & ( ! layermods ) ) | mods );
	register_code(code);
};

void unregister_shiftlayer_code(uint8_t code, uint8_t shiftlayer, uint8_t layermods, uint8_t mods) {
	unregister_code(code);
	if (mods) {
		unregister_mods(mods);
	};
	if (IS_LAYER_ON(shiftlayer)) {
		register_mods(layermods);
	};
};

void modlayer_on(uint8_t modlayer, uint8_t modcode) {
	if (IS_LAYER_OFF(modlayer)) {
		layer_on(modlayer);
	};
	register_mods(modcode);
};

void modlayer_off(uint8_t modlayer, uint8_t modcode, uint8_t modmask) {
	unregister_mods(modcode);
	if ( !( get_mods() & modmask ) ) {
		layer_off(modlayer);
	};
};
