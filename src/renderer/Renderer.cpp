/* date = April 07, 2024 4:13 PM */

#include "Renderer.h"

namespace MiniMario {

    Renderer *Renderer::get() {
        if (Renderer::_inst == nullptr) {
            _inst = new Renderer();
        }

        return _inst;
    }

    Renderer* Renderer::_inst = nullptr;
}