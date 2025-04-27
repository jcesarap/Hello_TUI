# Terminal-Based ASCII UI Library

## 🧩 Overview

- "Simplified" wrapper around `ncurses`.
- Meant for TUIs.
- Uses grid for output, ASCII art.

## ⏱️ Pending
- Before anything else: Use ncurses directly without wrappers.
- Personal: Study how to make libraries and how to setup their compilation with Cmake.
- Project:
    - Dynamic window positioning...
        - with `xprop`.
        - Easier window positioning and locks.
- Refactor: 
    - Use pointers to functions simplifying addition of screens.

## 📦 Project Structure

| File        | Description                                       |
|-------------|---------------------------------------------------|
| `bibtela.h` | Public header: function declarations and includes |
| `bibtela.c` | Implementation using `ncurses` and `locale`       |
| `main.c`    | Example usage showcasing the library’s functions  |

## ⚙️ Compilation & Setup

Compile: make
Run: ./tstbibtela

**License**: MIT  
**Author**: Eleudson, César
**Version**: 1.5.0
