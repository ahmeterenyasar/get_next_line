*This project has been created as part of the 42 curriculum by ayasar.*

---

# get_next_line

## Description

`get_next_line` is a C function that reads a single line at a time from a file descriptor, returning it as a null-terminated string (including the trailing `\n` if present). Each successive call picks up exactly where the previous one left off, making it possible to iterate over every line of a file — or standard input — using nothing but repeated calls to the function.

**Goal:** Implement `get_next_line(int fd)` so that it can be called in a loop to read an entire file line by line, handling any `BUFFER_SIZE` at compile time and working correctly across multiple file descriptors.

**Overview of behaviour:**
- Returns the next line (with `\n`) on success.
- Returns `NULL` on EOF or error.
- Preserves unread bytes between calls via a `static` linked-list stash, so no data is ever lost regardless of where a buffer boundary falls relative to a newline.

---

## Algorithm — Linked-List Stash

### Why a linked list?

The central challenge of `get_next_line` is that `read()` fills a fixed-size buffer that may end mid-line, mid-newline, or exactly on a newline. The unread tail must survive until the next call without performing an extra `read()` and without knowing in advance how long the eventual line will be.

### File structure

```
.
├── get_next_line.c          # Core logic (fill_stash, extract_line, trim_stash, get_next_line)
├── get_next_line_utils.c    # Helper functions (has_newline, etc.)
└── get_next_line.h          # t_stash struct definition and prototypes
```

---

## Reources
- 42 — get_next_line subject — official project specification.


## AI usage