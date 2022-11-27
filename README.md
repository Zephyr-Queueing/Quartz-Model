# Quartz-Model

Zephyr data model.

## Usage

Run `make` to build library archive. To use archive externally, install `lib/message.a` into `ext` directory of a separate project, and compile with:

`gcc src/main.o src/blah1.o src/blah2.o -L ext/message.a`