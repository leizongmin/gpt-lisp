# gpt-lisp

> This project is my first attempt at using a GPT language model for conversational interactions to assist with writing code. I hope this new method of software engineering can advance AI technologies into more humanizing and socializing ways, thereby accelerating the development process and broadening the impact of AI. By conversing and collaborating directly with AI systems, we can learn to better understand artificial intelligence and cultivate an intuitive sense that AI is accessible to all.

## About

GPT-Lisp is a simple Lisp interpreter implemented with the help of Claude, Anthropic's Constitutional AI assistant. Claude guided me through the process of designing, implementing, and testing the interpreter using C.

The interpreter supports basic Lisp expressions including:

- Atoms
- Lists
- Nested Lists
- Arithmetic operations
- Conditional expressions
- Lambda expressions
- Recursion
  GPT-Lisp demonstrates how AI assistants can be helpful partners in software design and development. With Claude's help, I was able to build an interpreter that I can continue improving to expand my knowledge of programming languages and interpreters.

## Setting Up Your Local Environment

To install the Check test suite library and dependencies, you'll need to manually compile and install the Check library. You can do so by running:

```bash
# Download Check library source
wget https://github.com/libcheck/check/releases/download/0.14.0/check-0.14.0.tar.gz

# Extract source
tar -xzf check-0.14.0.tar.gz

# Enter source directory
cd check-0.14.0

# Configure and compile
./configure
make

# Install (requires root)
sudo make install
```

This will install the Check library to your system paths, usually under `/usr/local`.

You'll then need to update your Makefile and environment to use the manually installed Check library:

1. Update `CHECK_INCLUDE` to point to `/usr/local/include`:

```makefile
CHECK_INCLUDE = /usr/local/include
```

2. Update `CHECK_LIB_DIR` to point to `/usr/local/lib`:

```makefile
CHECK_LIB_DIR = /usr/local/lib
```

3. Add `/usr/local/lib` to your `LD_LIBRARY_PATH`:

```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
```

4. Ensure the above paths have permission to run make test.

Manual installation of libraries is more complex but can be used when automatic methods fail. Let me know if you have any issues or need help with the installation process. I'm happy to provide compilation option or Makefile update suggestions.

## License

```
MIT License

Copyright (c) 2023 LEI Zongmin <leizongmin@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
