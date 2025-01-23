---
icon: house-chimney-heart
layout:
  title:
    visible: true
  description:
    visible: false
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: true
---

# Blossom

Blossom is a modern, functional programming language that emphasizes code clarity, safety, and maintainability. Built on the robust Erlang VM, it combines the reliability of battle-tested infrastructure with an elegant, developer-friendly syntax.

## Do we need *really* another programming language?

It's a fair question - one I've asked myself countless times during Blossom's development. The truth is, there is no perfect programming language, at least not for every need. Blossom was born from a specific vision: to create a language where codebases can grow as beautifully and naturally as a flower does - hence the name.

### Key Features

- **Immutable by default**: All variables are immutable, ensuring predictable state management and eliminating common concurrency issues.
- **Strong type system**: Comprehensive static typing with powerful type inference helps catch errors at compile time.
- **Explicit error handling**: Function signatures declare potential errors that must be explicitly handled by callers, while unexpected errors follow Erlang's "let it crash" philosophy for fault tolerance.
- **Pattern matching**: Elegant pattern matching syntax for complex data structures and control flow.
- **Concurrency made simple**: Built on the Erlang VM's actor model for reliable, scalable concurrent systems.
- **Zero runtime surprises**: What you see is what you get - no implicit conversions or hidden behaviors.

## Quick Start

### Installation

**macOS**
```bash
brew install blossom
```

**Linux**
```bash
curl -fsSL https://blossom-lang.org/install.sh | sh
```

### Hello, World!

1. Initialize a new project using the Blossom CLI.

```bash
blossom create .
```

2. Modify the `main.blsm` file.

```blossom
%module HelloWorld
%import IO

Main -> IO.Log("Hello, World!")
```

3. Build the program.
```bash
blossom build
```

4. Start the program.
```bash
blossom start
```

5. 🎆
```
Blossom (HelloWorld.Main) > Hello, World!
```

## Why Blossom?

Modern software development often involves managing complex systems with many moving parts. Blossom was created to help developers build maintainable, reliable applications by:

- Making state changes explicit and trackable;
- Enforcing compile-time safety without sacrificing productivity;
- Providing powerful abstractions for handling errors and concurrent operations;
- Offering a clean, consistent syntax that promotes readability.

## Learning Blossom

- 📚 [Documentation](documentation/types.md) - Comprehensive language guide
- 🎓 [Examples](examples/) - Real-world code examples
- 💬 [Discord](https://discord.gg/blossom) - Join our community
- 🐛 [Issue Tracker](https://github.com/fhamm/blossom/issues) - Report bugs or request features

## Contributing

We welcome contributions! Whether it's:

- Reporting bugs
- Improving documentation
- Suggesting new features
- Contributing code

Please read our [Contributing Guide](CONTRIBUTING.md) to get started.

## License

Blossom is released under the MIT License.

## Credits

Created and maintained by Felipe Hamm. Special thanks to all contributors who have helped shape Blossom into what it is today.
