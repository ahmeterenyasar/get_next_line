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

A **singly-linked list of buffer nodes** (the "stash") solves both problems:

| Concern | Solution |
|---|---|
| Unknown line length | Nodes are appended on demand; no pre-allocation needed |
| Data survival across calls | The `static t_stash *head` pointer persists between calls |
| Multiple buffer sizes | Each node holds exactly `BUFFER_SIZE` bytes; logic is size-agnostic |
| Minimal copying | Extraction traverses the list in place; trimming reuses the node already in memory |

### Step-by-step flow

```
get_next_line(fd)
│
├─ 1. fill_stash(fd, &head)
│       Read BUFFER_SIZE bytes at a time from fd, appending each
│       chunk as a new t_stash node to the linked list.
│       Stop as soon as a '\n' is found in the freshly-appended
│       node, or when read() returns 0 (EOF).
│
├─ 2. extract_line(&head)
│       Walk the list from the beginning, counting characters up
│       to and including the first '\n' (or until the list is
│       exhausted for the last line).
│       Allocate exactly that many bytes + 1, copy, and return.
│
└─ 3. trim_stash(&head)
        Find the '\n' that was just consumed, shift everything
        after it to the front of its node, and update
        number_of_used_bytes.  Nodes that become empty are freed.
        If no bytes remain, head is set to NULL.
```

## Reources
- 42 — get_next_line subject — official project specification.


## AI usage