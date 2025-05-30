# ctemplate

A revived fork of the one and only [ctemplate](https://libctemplate.sourceforge.net) with extra functionalities.

# Installation:

```bash
git clone https://github.com/mbaraa/ctemplate
cd ctemplate
make
sudo make install
```

# Usage:

1. Include the header

```c
#include<ctemplate/ctemplate.h>
```

2. Go nuts.

# Available functions:

- Old

  - `TMPL_write()` expands and outputs a template.
  - `TMPL_add_var()` adds simple variables to a variable list.
  - `TMPL_add_varlist()` adds a variable list to a loop variable.
  - `TMPL_add_loop()` adds a loop variable to a variable list.
  - `TMPL_add_fmt()` adds a function to a format function list.
  - `TMPL_free_varlist()` frees memory used by a variable list.
  - `TMPL_free_fmtlist()` frees memory used by a format function list.

- New
  - `TMPL_make_var_list()` returns a TMPL_varlist from the given char\* arguments.
  - `TMPL_write_to_buffer()` same as `TMPL_write` but using a bytes buffer instead of a file.
