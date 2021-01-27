#pragma once

#include <string>

namespace Disco {
    struct RGBA {
        float r, g, b, a;
        RGBA(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) { }
    };
}