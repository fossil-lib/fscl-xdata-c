# Trilobite Data libraries - C

The Trilobite XData library is a versatile and efficient collection of data structures and algorithms designed to handle a wide range of data types and operations. It provides a robust foundation for managing and manipulating data in various applications, with a focus on ease of use, reliability, and performance.

## Who is This For?

This guide is designed for developers of all skill levels who want to use the Meson build system for their projects. It assumes basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## Setting up, Compiling, Installing, and Running the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/trilobite-stdlib/trilo-xdata-c.git
   cd trilo-xdata-c
   ```

2. **Configure the Build**:
   ```bash
   meson setup builddir
   ```

3. **Compile the Project**:
   ```bash
   meson compile -C builddir
   ```

4. **Install the Project**:
   ```bash
   meson install -C builddir
   ```

## Including the Demo and Running Tests

To include the demo and run tests, you can use the following options when configuring the build:

- **Including the Demo**: Add `-Dwith_demo=enabled` when configuring the build.
- **Running Tests**: Add `-Dwith_test=enabled` when configuring the build.

Example:

```bash
meson setup builddir -Dwith_demo=enabled -Dwith_test=enabled
```

## Contributing

If you're interested in contributing to this project, please consider opening pull requests or creating issues on the [GitHub repository](https://github.com/trilobite-stdlib/trilo-xdata-c). Be sure to read the documentation on the [project website](https://trilobite.home.blog).

## Feedback and Support

If you encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue on the [GitHub repository](https://github.com/trilobite-stdlib/trilo-xdata-c/issues).

## License

This project is licensed under the [Apache License 2.0](LICENSE).

---

Thank you for choosing this project with the Meson build system. Happy coding and building amazing projects!

## Contact

If you have questions or want to get in touch regarding programming solutions, you can find a way to contact me on my [website](https://trilobite.home.blog/contact/).
