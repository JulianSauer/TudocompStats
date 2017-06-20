#include "../include/malloc.hpp"
#include "../include/StatPhase.hpp"

#ifndef STATS_DISABLED

using tdc::StatPhase;

StatPhase* StatPhase::s_current = nullptr;

void malloc_callback::on_alloc(size_t bytes) {
    StatPhase::track_alloc(bytes);
}

void malloc_callback::on_free(size_t bytes) {
    StatPhase::track_free(bytes);
}

#endif

