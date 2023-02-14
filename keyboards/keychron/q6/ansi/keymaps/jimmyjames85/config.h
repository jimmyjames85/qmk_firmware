// These must be defined in config.h
//
// I assume because other libraries rely on these constants, and make
// is specifically watching for changes in config.h

#undef LEADER_TIMEOUT    // https://www.reddit.com/r/olkb/comments/7u7362/leader_key_timing/
#define LEADER_TIMEOUT 750

#undef LEADER_PER_KEY_TIMING // https://docs.qmk.fm/#/feature_leader_key
#define LEADER_PER_KEY_TIMING // https://docs.qmk.fm/#/feature_leader_key


#define DYNAMIC_MACRO_NO_NESTING
