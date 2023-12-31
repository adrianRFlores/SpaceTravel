#pragma once
#include <glm/glm.hpp>
#include <cstdint>
#include <vector>
#include "color.hpp"
#include "uniforms.hpp"

struct Vertex {
    glm::vec3 pos;
    glm::vec3 normal;
    glm::vec3 tex;
    glm::vec3 worldPos;
    glm::vec3 originalPos;
    glm::vec4 clipSpace;
};

struct Fragment {
    glm::ivec2 pos;
    glm::vec3 worldPos;
    glm::vec3 originalPos;
    double z;
    Color color;
    float light;
};

struct zFragment {
    Color color;
    double z;
};

struct OrbitPoint {
    glm::vec4 pos;
    Color color;
    float decayRate = 0.0075f;
    float intensity = 1.0f;

    glm::vec4 getScreenSpace(const Uniforms& uniforms) {
        glm::vec4 clipSpaceVertex = uniforms.projection * uniforms.view * pos;

        glm::vec3 ndcVertex = glm::vec3(clipSpaceVertex) / clipSpaceVertex.w;

        return uniforms.viewport * glm::vec4(ndcVertex, 1.0f);
    }

    float decayLight() {
        intensity -= decayRate;
        return intensity;
    }
};

std::vector<Fragment> fragmentLine(const glm::vec3& v1, const glm::vec3& v2) {
    glm::ivec2 p1(static_cast<int>(v1.x), static_cast<int>(v1.y));
    glm::ivec2 p2(static_cast<int>(v2.x), static_cast<int>(v2.y));

    std::vector<Fragment> fragments;

    int dx = std::abs(p2.x - p1.x);
    int dy = std::abs(p2.y - p1.y);
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;

    int err = dx - dy;

    glm::ivec2 current = p1;

    while (true) {
        Fragment fragment;
        fragment.pos = current;

        fragments.push_back(fragment);

        if (current == p2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            current.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            current.y += sy;
        }
    }

    return fragments;
}