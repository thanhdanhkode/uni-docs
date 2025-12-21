<!-- markdownlint-disable MD041 -->

## Program for Engineers (C) Note -- Advanced

### Function Docs

For function prototype

```c
/**
 * A function name with short desc
 * @param input the user input
 * @return simple_value
 */
int simple_function(int input);

// --- OR ---

/// @brief A function name with short desc
/// @param input the user input
/// @return simple_Value
int simple_function(int input);
```

For normal function

```c
/**
 * A function name with short desc
 * @param input the user input
 * @return simple_value
 */
int simple_function() {
  // Code here...
}

// --- OR ---

/// @brief A function name with short desc
/// @param input the user input
/// @return simple_Value
int simple_function(int input) {
  // Code here...
}
```

When hover to the function name, a simple hover container will show up to display the information about the function that written.

This is a feature that support by various of modern IDE or Text Editor such as VS Code, Jetbrains IDE, Eclipse. This feature is similar to JSDOcs in Javascript development.
