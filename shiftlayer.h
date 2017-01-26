#include <stdint.h>

void shiftlayer_on(uint8_t shiftlayer, uint8_t layermods);
void shiftlayer_off(uint8_t shiftlayer, uint8_t layermods);
void update_tri_shiftlayer(uint8_t shiftlayer, uint8_t nonshiftlayer, uint8_t twinlayer);

void register_shiftlayer_code(uint8_t code, uint8_t layermods, uint8_t mods);
void unregister_shiftlayer_code(uint8_t code, uint8_t shiftlayer, uint8_t layermods, uint8_t mods);

void modlayer_on(uint8_t modlayer, uint8_t modcode);
void modlayer_off(uint8_t modlayer, uint8_t modcode, uint8_t modmask);

