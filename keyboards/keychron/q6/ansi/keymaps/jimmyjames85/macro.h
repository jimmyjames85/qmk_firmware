#include <stdio.h>

#define MACRO_SIZE 180
enum {
    MS_STOPPED,
    MS_RECORDING,
};



typedef struct m_record_t {
    uint16_t keycode;
    bool pressed;
} m_record_t;


// TODO linked list?
typedef struct macro_t {
    m_record_t records[MACRO_SIZE+1];
    m_record_t *p;
    int state;
} macro_t;



int shouldIgnore(uint16_t keycode, uint16_t *ignore, int ignoreCount) {
    if (ignore  == NULL) {
        return 0;
    }

    // size_t size = sizeof(ignore) / sizeof(uint16_t);
    // for ( uint16_t* i=ignore; i<=&ignore[size-1]; i++) {
    //     if (*i==keycode){
    //         return 1;
    //     }
    // }

    for ( int i=0;i<ignoreCount; i++) {
        if (ignore[i]==keycode){
            return 1;
        }
    }

    return 0;
}

// button should be either 'P' or 'R' for play or record
void handle_macro(macro_t* m, uint16_t keycode, keyrecord_t *record, char button, uint16_t *ignore, int ignoreCount) {

    if ( (record->event.pressed) && (button=='R' || button == 'P') ) {
        return; //ignore key down
    }

    m_record_t* kc;

    switch(m->state){
    case MS_STOPPED:
        if (button=='R'){
            printf("record start\n");
            m->state = MS_RECORDING;
            m->p = m->records;
        } else if (button=='P'){
            printf("playing\n");
            for ( kc=m->records; kc != m->p; kc++ ){

                // if (kc->keycode >= 256) {
                //     // TODO
                //     printf("%04x is unsafe range\n", kc->keycode);
                //     continue;
                // }

                if (kc->pressed) {
                    register_code(kc->keycode);
                } else {
                    unregister_code(kc->keycode);
                }
                printf("playing: %04x\n", kc->keycode);
            }
            printf("end playing\n");
        }
        break;
    case MS_RECORDING:
        if (button=='R'){
            printf("record stop\n");
            m->state = MS_STOPPED;
            break;
        } else if (shouldIgnore(keycode, ignore, ignoreCount)) {
            break;
        } else {
            if (m->p == &m->records[MACRO_SIZE]){
                m->state = MS_STOPPED;
                // return false
                printf("full\n"); // TODO
                break;
            }

            printf("recorded: %04x\n", keycode);
            m->p->keycode = keycode;
            m->p->pressed = record->event.pressed;
            m->p++;
        }
        break;
    default:
        printf("record reset\n");
        // reset
        m->state = MS_STOPPED;
        m->p = m->records;
        printf("reset\n");
        break;
    }
}
