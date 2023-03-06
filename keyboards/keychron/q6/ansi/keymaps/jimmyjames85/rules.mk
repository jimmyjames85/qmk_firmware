# VIA_ENABLE = yes

# https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-execution
DEFERRED_EXEC_ENABLE = yes

# https://github.com/qmk/qmk_firmware/blob/master/docs/faq_debug.md#debugging-faq
CONSOLE_ENABLE = yes

# # https://docs.qmk.fm/#/feature_tap_dance
TAP_DANCE_ENABLE = yes

# https://docs.qmk.fm/#/feature_dynamic_macros?id=dynamic-macros-record-and-replay-macros-in-runtime
# DOES NOT WORK don't include it
DYNAMIC_MACRO_ENABLE = no

# https://docs.qmk.fm/#/feature_leader_key
LEADER_ENABLE = yes

# disable rgb lighting effects and just rely on rgb_matrix calls
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

# used for preventing screen saver
MOUSEKEY_ENABLE = yes
