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

    template <typename T> T *make(Expr *left, Token op, Expr *right) {}

    void *allocate(std::size_t size, std::size_t alignment);

    void reset();
    // Delete the the copy and move constructors:
    Arena(const Arena &) = delete;
    Arena(Arena &&) = delete;
};
