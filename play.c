#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

EM_JS(void, show, (const char *s), {
    const el = document.getElementById("addr");
    if (el) el.textContent = UTF8ToString(s);
});
#endif

static char *mem;
static int step = 12345678;
static int n;
static int i = 0;

static void tick(void){
#ifdef __EMSCRIPTEN__
    char buf[32];
    snprintf(buf, sizeof buf, "%p", (void *)&mem[i * step]);
    show(buf);
#else
    printf("\r%p", (void *)&mem[i * step]);
    fflush(stdout);
#endif
    i = (i + 1) % n;
}

int main(){

    mem = malloc(500000000);
    n = 500000000 / step;

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(tick, 5, 1); // 5 fps = 200ms
#else
    for (;;){
        tick();
        usleep(200000);
    }
#endif
}
