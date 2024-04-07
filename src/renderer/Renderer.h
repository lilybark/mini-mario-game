/* date = April 07, 2024 4:13 PM */

#ifndef MINI_MARIO_RENDERER_H
#define MINI_MARIO_RENDERER_H


namespace MiniMario {
    /**
     * Simple renderer class. Currently only supports rendering quads to the screen; this is a 2D Game at the moment.
     */
    class Renderer {
    private:
        Renderer() = default;
        static Renderer *_inst;
    public:
        static Renderer *get();
    };
}


#endif //MINI_MARIO_RENDERER_H
