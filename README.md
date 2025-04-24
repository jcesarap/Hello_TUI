# Terminal-Based ASCII UI Library

## 🧩 Overview

This project is a **lightweight, C-based wrapper** around the `ncurses` library—designed to simplify the creation of **terminal-based user interfaces** (TUIs). It provides an accessible, minimal API that makes it easier to work with **positioned output**, **ASCII art**, and **box-drawing characters**, without needing to directly manage the more verbose and intricate parts of `ncurses`.

## 🌐 Broader Context: Why Build a TUI Library?

### 1. The Role of Terminal UIs

Before the GUI era, **text-based UIs were the standard**. From MS-DOS applications to early UNIX tools, interfaces were made from characters: boxes, lines, symbols. Even today, TUIs are relevant in:

| Domain             | Use Cases                                           |
|--------------------|-----------------------------------------------------|
| DevOps             | Monitoring dashboards (e.g., `htop`, `btop`, `ncdu`)|
| System Tools       | Menu-based UIs for config or recovery               |
| Game Development   | Roguelikes and puzzle games                         |
| Embedded Systems   | Interfaces on low-resource or screenless hardware  |
| Remote Workflows   | Tools accessed via SSH, where GUI isn't feasible    |

These UIs are **fast, scriptable, lightweight, and portable**—making them an enduring UI paradigm.

### 2. The Problem with `ncurses`

While **powerful**, `ncurses` has a steep learning curve:
- Boilerplate code for even simple layout
- Manual refresh logic
- Verbose API for things like cursor movement and printing
- Less intuitive support for modern characters or Unicode

This project wraps around `ncurses` to provide a **clean, minimal interface**—ideal for focused applications, rapid prototyping, and educational demos.

---

## 🧪 What This Library Offers

### Key Goals:
- Abstract away verbose terminal control logic
- Provide intuitive APIs for:
  - Cursor positioning
  - Text rendering at coordinates
  - Screen initialization and cleanup
- Full support for **box-drawing characters** and **Unicode glyphs**
- Clean, modular code ideal for learning or extension

---

## 📦 Project Structure

| File        | Description                                       |
|-------------|---------------------------------------------------|
| `bibtela.h` | Public header: function declarations and includes |
| `bibtela.c` | Implementation using `ncurses` and `locale`       |
| `main.c`    | Example usage showcasing the library’s functions  |

---

## 🧵 Code Overview

### `bibtela.h`
Defines a minimal API:
```c
void init_screen(int x, int y);         // Create screen of size x × y
void xyprint(int x, int y, char *str);  // Print string at coordinates
void xygoto(int x, int y);              // Move cursor
void clear_screen();                    // Clear content
void end_screen();                      // Exit and restore terminal
```

Relies on standard C headers plus:
- `<ncurses.h>` — terminal screen management
- `<locale.h>`, `<wchar.h>` — for Unicode box drawing

### `bibtela.c`
- Wraps `ncurses` primitives (e.g., `newwin`, `mvwprintw`, `refresh`)
- Uses `setlocale(LC_ALL, "")` for full character support
- Maintains a single `WINDOW *my_screen` object for screen operations

### `main.c`
Demonstrates how to:
1. Initialize a 25×80 screen
2. Print a `■` at position (0,0)
3. Move cursor to bottom-right
4. Wait for user input, then exit cleanly

## 🚀 Example Use Cases

| Scenario                  | How This Library Helps                         |
|---------------------------|------------------------------------------------|
| Retro Game UI             | Draw game grids, scoreboards, game status     |
| Terminal Menu Systems     | Navigate items using a basic cursor           |
| ASCII Animations          | Rapid redraws using positioned printing       |
| Terminal Prototypes       | Quick sketch of layout ideas                  |
| Education / Demos         | Teach how terminals work under the hood       |

## ⚙️ Compilation & Setup

### Linux/macOS

```sh
sudo apt install libncurses-dev     # Debian-based
brew install ncurses                # macOS

gcc main.c bibtela.c -lncurses -o ascii_ui
./ascii_ui
```

### Windows

- Use WSL2 (Ubuntu preferred) or
- Install Cygwin with `ncurses` support

## 🧰 Features

| Feature                    | Description                                     |
|----------------------------|-------------------------------------------------|
| Minimal API                | Easy to use in simple or educational projects   |
| Box Drawing Support        | Works with characters like `╔`, `║`, `═`, `█`   |
| Unicode Compatibility      | Prints wide characters and symbols correctly    |
| Lightweight & Fast         | No external dependencies beyond `ncurses`       |
| Clean Terminal Exit        | Automatically restores shell state             |

## ⚠️ Limitations

| Limitation           | Notes                                                  |
|----------------------|--------------------------------------------------------|
| No Color Support     | Requires adding `start_color()` and color pairs        |
| One Window Only      | No subwindow or panel layering yet                     |
| Basic Input          | Uses `scanf`, not real-time key handling (`getch`)     |

## 🔮 Roadmap / Ideas

| Feature                 | Status    |
|-------------------------|-----------|
| Color support           | Planned   |
| Non-blocking input      | Planned   |
| Multi-window support    | Planned   |
| Menu and HUD templates  | Possible  |
| Mouse support           | Maybe     |

## 📚 Resources & Further Reading

- [NCURSES Programming HOWTO](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
- [Extended ASCII Table](https://www.ascii-code.com/)
- [Box-Drawing Unicode](https://www.unicode.org/charts/PDF/U2500.pdf)
- TUIs in the wild: [`htop`](https://htop.dev), [`cmatrix`](https://github.com/abishekvashok/cmatrix), [`nmtui`](https://linux.die.net/man/1/nmtui)

## 🎯 Summary

This library is a **gateway into terminal UI development**, giving you just enough power to build useful interfaces without the complexity of full `ncurses` development. Whether you're creating a classic roguelike, a command-line dashboard, or a tool for fun or learning, this project offers a friendly starting point.

It’s small, readable, and built to be hacked on.

## 🤝 How to Contribute

- Found a bug? Open an issue.  
- Got a feature idea? Submit a PR!  
- Want to extend it into a full TUI framework? Fork and explore!  

**License**: MIT  
**Author**: [Your Name]  
**Version**: 1.0.0

Would you like this saved as a `.md`, `.pdf`, or `.html` file? I can also help you turn it into a GitHub `README` or generate diagrams for the architecture.
