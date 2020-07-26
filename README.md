# Cpp codes

C++ code snippets for common tasks such as creating threads, using lamdas, etc.\
This repository is also used to store newly learnt concepts and techniques.\
Highly useful in realtime coding. Makes us faster and accurate in coding tasks.

## Tips

Use `clang-format` to format cpp code.

Below are the modified options for clang-format.

```text
# Generated from clang-format
# $ clang-format --version
#   clang-format version 10.0.0-4ubuntu1
# $ clang-format -style=llvm -dump-config > .clang-format

BasedOnStyle: LLVM
AccessModifierOffset: -4
BreakBeforeBraces: Stroustrup
IndentWidth: 4
Standard: c++17
TabWidth: 4
```

In vscode editor use `xaver.clang-format` instead of cpp-tools clang-format
binary as it uses the clang-format found on the system path. Als0 allows us
to use different versions of clang-format by specifying the path.
