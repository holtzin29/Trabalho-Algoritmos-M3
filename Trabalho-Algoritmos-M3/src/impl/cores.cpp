#include "../header/cores.h"
#include "raylib.h"

Color obterCorBloco(int vida) {
    Color coresVida1[] = {
        (Color){255, 100, 100, 255},
        (Color){100, 255, 100, 255},
        (Color){100, 100, 255, 255},
        (Color){255, 255, 100, 255},
        (Color){255, 100, 255, 255},
        (Color){100, 255, 255, 255},
        (Color){255, 150, 50, 255},
        (Color){150, 255, 50, 255},
        (Color){50, 150, 255, 255},
        (Color){255, 50, 150, 255},
        (Color){150, 50, 255, 255},
        (Color){50, 255, 150, 255}
    };
    
    Color coresVida2[] = {
        (Color){200, 50, 50, 255},
        (Color){50, 200, 50, 255},
        (Color){50, 50, 200, 255},
        (Color){200, 200, 50, 255},
        (Color){200, 50, 200, 255},
        (Color){50, 200, 200, 255},
        (Color){200, 100, 25, 255},
        (Color){100, 200, 25, 255},
        (Color){25, 100, 200, 255},
        (Color){200, 25, 100, 255},
        (Color){100, 25, 200, 255},
        (Color){25, 200, 100, 255}
    };
    
    Color coresVida3[] = {
        (Color){150, 0, 0, 255},
        (Color){0, 150, 0, 255},
        (Color){0, 0, 150, 255},
        (Color){150, 150, 0, 255},
        (Color){150, 0, 150, 255},
        (Color){0, 150, 150, 255},
        (Color){150, 75, 0, 255},
        (Color){75, 150, 0, 255},
        (Color){0, 75, 150, 255},
        (Color){150, 0, 75, 255},
        (Color){75, 0, 150, 255},
        (Color){0, 150, 75, 255}
    };
    
    int seed = (int)(GetTime() * 1000) % 12;
    
    if (vida >= 3) {
        return coresVida3[seed];
    } else if (vida == 2) {
        return coresVida2[seed];
    } else if (vida == 1) {
        return coresVida1[seed];
    }
    return GRAY;
}

Color obterCorItem(int tipo) {
    switch (tipo) {
        case 0:
            return GREEN;
        case 1:
            return SKYBLUE;
        case 2:
            return PURPLE;
        case 3:
            return GOLD;
        case 4:
            return PINK;
        case 5:
            return DARKGRAY;
        default:
            return WHITE;
    }
}
