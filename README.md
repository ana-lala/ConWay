# Game of Life Simulator

This project simulates Conway's Game of Life using C++. The simulation initializes a grid based on user-defined dimensions, populates it with random live and dead cells, and then evolves the grid according to the rules of the Game of Life.

## Requirements

- C++ compiler (e.g., g++)
- Operating system supporting standard C++ libraries (e.g., Windows, Linux)

## Compilation and Execution

1. **Compile the project:**

    Navigate to the project directory and run:

    ```bash
    g++ -o bin/debug/GameOfLife main.cpp EstablecerConsola.cpp FuncionesAuxiliares.cpp
    ```

2. **Run the executable:**

    Navigate to the `bin/debug` directory and execute the binary:

    ```bash
    cd bin/debug
    ./GameOfLife
    ```

## How to Use

- Upon execution, the program prompts the user to enter the dimensions (rows and columns) of the game board.
- It validates the user input to ensure the dimensions are within the allowed range (`MAXREN` for rows and `MAXCOL` for columns).
- After setting up the initial board with random live and dead cells, press `ENTER` to start the simulation.
- Press `ESCAPE` to exit the simulation at any time.

## Functions

- **CapturarEntero:** Function to capture an integer input from the user, with error handling for invalid input.
- **Imprimir:** Function to print the current state of the grid, showing live cells as 'O' and dead cells as blank spaces.
- **GeneracionNueva:** Function to compute the next generation of cells based on the rules of the Game of Life.
- **PonerVecinos:** Function to calculate the number of live neighbors for each cell in the grid.
- **Crear & Destruir:** Functions for dynamic memory allocation and deallocation of the game board.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
