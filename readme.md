# Trilobite Data libraries - C

The Trilobite XData Library, a vital component within the Trilobite Standard Component Libraries (TSCL), stands as a comprehensive framework for data structures and algorithms in the C programming language. It caters to the dynamic needs of developers engaged in data-centric applications, offering a powerful toolkit to efficiently handle and manipulate diverse datasets.

One of the library's standout features is its versatile array of data structures, ranging from vectors and trees to doubly-linked lists. This diversity empowers developers to select the most suitable structure for their specific use cases, fostering adaptability and performance optimization.

Designed for efficiency, Trilobite XData incorporates meticulously crafted algorithms, addressing critical operations like searching, sorting, and reversing. The library's commitment to optimal performance ensures that developers can build responsive applications without compromising on computational speed.

Trilobite XData acknowledges the significance of data type specificity, supporting integers, doubles, strings, characters, booleans, and more. This flexibility allows developers to seamlessly work with a variety of data types, enhancing the library's applicability across a wide spectrum of projects.

In the realm of memory management, Trilobite XData prioritizes resource efficiency. The library provides robust functions for creating, manipulating, and deallocating data structures, allowing developers to navigate memory resources with confidence.

As part of the Trilobite Ecosystem, Trilobite XData seamlessly integrates with other TSCL components, fostering a cohesive development environment. This integration empowers developers with a comprehensive set of tools and libraries, streamlining the development process and promoting code reusability.

Emphasizing ease of use, Trilobite XData boasts an intuitive interface and well-documented functions. Whether catering to novice or experienced programmers, the library ensures accessibility and simplicity, accelerating the development cycle and promoting a positive developer experience.

In conclusion, the Trilobite XData Library emerges as a robust and adaptable solution for developers seeking a high-performance data structures and algorithms framework in C. With its rich feature set, seamless integration, and commitment to efficiency, Trilobite XData empowers developers to tackle complex data challenges with confidence and precision.

## Who is This For?

This guide is designed for developers of all skill levels who want to use the Meson build system for their projects. It assumes basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## Setting up, Compiling, Installing, and Running the Project

1. **Create a Wrap File**:

Create a directory named subprojects in the root directory, next create a file named `tscl-xdata-c.wrap` in the `subprojects` directory of your project with the following content:

   ```bash
   # ================ #
   #  TSCL Wrap File. #
   # ================ #
   [wrap-git]
   url = https://github.com/trilobite-stdlib/tscl-xdata-c.git
   revision = main
   
   [provide]
   tscl-xdata-c = tscl_xdata_c_dep
   ```

2. **Integrate Wrap File in Meson Build**:
   ```meson
   project('my_project', 'c',
       version : '0.1',
       default_options : ['warning_level=3'])

   exe = executable('my_project', 'my_project.c',
       dependencies : dependency('tscl-xdata-c'), # add this line
       install : true)

   test('basic', exe)
   ```

3. **Compile the Project**:
   ```bash
   meson setup builddir
   meson compile -C builddir
   ```

4. **Visit the reference guide to learn how to this**

Here is the link to the [Refrence Docs](https://trilobite.home.blog/reference-docs/)

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
