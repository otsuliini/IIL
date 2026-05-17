#include "parser/arena.hpp"
#include <cstddef>
#include <memory>
#include <new>

void *Arena::allocate(std::size_t size, std::size_t alignment) {
    while (true) {
        char *base = current_Chunk_->buffer + current_Chunk_->offset;
        size_t space = current_Chunk_->capacity - current_Chunk_->offset;

        void *aligned = base;

        if (std::align(alignment, size, aligned, space)) {
            current_Chunk_->offset = (char *)aligned - current_Chunk_->buffer + size;

            return aligned;
        }

        if (!current_Chunk_->nextChunk) {
            current_Chunk_->nextChunk = create_chunk(256 * 1024); // 1KB
        }

        current_Chunk_ = current_Chunk_->nextChunk;
    }
}
// reset the arena to reuse the memory block
void Arena::reset() {
    ArenaChunk *c = head_;
    while (c) {
        c->offset = 0;
        c = c->nextChunk;
    }
    current_Chunk_ = head_;
}
