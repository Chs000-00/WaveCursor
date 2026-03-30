#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/GhostTrailEffect.hpp>
using namespace geode::prelude;

void fixedTrailSnapshot(GhostTrailEffect* effect, float p0);


class $modify(BetterGhostTrailEffect, GhostTrailEffect) {
    void fixedTrailSnapshot(float p0);
};