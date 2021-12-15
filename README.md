# Make
Makefiles in C.

```c
#include "make.h"

int main(int argc, char **argv)
{
    make_rebuild(argc, argv);
    make_cc("sample", "sample.c", "-std=c11");
    make_cmd("./sample");
    return 0;
}
```

See the [make.c](./make.c) file for a more complex example.

## API
### `make_rebuild(int argc, char argv)`
- `argc` The number of command line arguments
- `argv` The command line arguments

Rebuild the make program automatically when the source is modified. This way
you can modify the make program without worrying about recompiling it.

```c
int main(int argc, char **argv)
{
    make_rebuild(argc, argv);
}
```

### `make_cmd(char *...)`
- `...` The command composition

Execute a command, errors out if the process exits with a non-ZERO exit code.

```c
make_cmd("echo", "hello, world!");
```

### `make_cc(char *binary, char *source, char *...)`
- `binary` The binary produced by the compilation
- `source` The source file of the compilation
- `...` The rest of the arguments

Compile `source` to `binary` if the source was modified later than the binary.

```c
make_cc("sample", "sample.c");
make_cc("trie", "trie.c", "-Wall", "-Wextra");
```

### `make_modified(char *file_path)`
- `file_path` The path to the file

Return the last modified timestamp of `file_path`

```c
if (make_modified("trie.c") > make_modified("trie")) {
    make_echo("rebuilding the trie at %zu", time());
    make_cmd("cc", "-o", "trie", "trie.c");
}
```

### `make_echo(...)`
- `...` The format passed to `printf()`

Display a message.

```c
make_echo("foo bar baz");
```

### `make_error(...)`
- `...` The format passed to `printf()`

Display the error message and exit.

```c
if (argc < 2) {
    make_error("no subcommand provided");
}
```

### `make_assert(bool condition, ...)`
- `condition` The condition checked
- `...` The format passed to `printf()`

If the condition is false, display the error message and exit.

```c
make_assert(argc > 1, "no subcommand provided");
```
