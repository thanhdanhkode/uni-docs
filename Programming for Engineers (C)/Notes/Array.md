<!-- markdownlint-disable MD041 -->

## Program for Engineers (C) Note -- Array

### Declare a array

Format `type array_name[array_size] = {...value};`

```c
int array[5]= { 0 , 1 , 2 , 3, 4 };
```

### Read the values in array

```c
#define SIZE 5

int array[SIZE] = { 0, 1, 2, 3, 4 }

for (int i = 0; i < SIZE; i++) {
  printf("%d ", array[i])
}
```

### Assign a value into a element of array

Format `array_name[index_of_element] = value`

```c
int new_value = 3;

array[0] = 0;
array[1] = new_value;
```

### Get dynamic size of array

```c
int size = sizeof(array) / sizeof(array[0]);
```
