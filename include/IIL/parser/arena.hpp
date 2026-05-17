#pragma once
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"
#include <cstddef>
#include <memory>
#include <new>

struct ArenaChunk {
    // pointer to start of raw memory:
    char *buffer;
    std::size_t capacity;
    // how much is used:
    std::size_t offset;
    // link to next chunk:
    ArenaChunk *nextChunk;
};

class Arena {
    // First chunk:
    ArenaChunk *head_;
    ArenaChunk *current_Chunk_;

  public:
    ArenaChunk *create_chunk(size_t size) {
        ArenaChunk *chunk = new ArenaChunk;

        chunk->buffer = static_cast<char *>(::operator new(size));
        chunk->capacity = size;
        chunk->offset = 0;
        chunk->nextChunk = nullptr;

        return chunk;
    }
    Arena::Arena() {
        head_ = create_chunk(256 * 1024); // 1KB
        current_Chunk_ = head_;
    }

    ~Arena() {
        ArenaChunk *c = head_;
        // while (c != nullptr):
        while (c) {
            ::operator delete(c->buffer);
            ArenaChunk *next = c->nextChunk;
            delete c;
            c = next;
        }
    }

    template <typename T, typename... Args> T *make(Args &&...args) {
        // allocate raw memory in arena
        // construct object in that memory
        // return a pointer to that object.
        void *address = allocate(sizeof(T), alignof(T));
        // std::forward passes constructor arguments.
        return new (address) T(std::forward<Args>(args)...)
    }

    void *allocate(std::size_t size, std::size_t alignment);

    void reset();
    // Delete the the copy and move constructors:
    Arena(const Arena &) = delete;
    Arena(Arena &&) = delete;
};
