
# FDF

This project is about creating a simplified graphic "wireframe"
representation of a relief landscape linking various points (x, y, z) via
segments. The coordinates of this landscape are stored in a file passed as
a parameter to the program.

Each number corresponds to a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

## Features

- Shows map using isometric projection.
- Quits the program by pressing 'esc'.

## To Do List

- Link two points in the map with a line.
- Color line as a function of altitude (https://harm-smits.github.io/42docs/libs/minilibx/colors.html).

## Known bugs

- Does not recompile for a change in a libft file.
- Opens window even if the input file has no valid info.?
- Does not work for some maps (ex. julia.fdf)?
- Opens files not ending with .fdf?
- Creates bands in the map due to int truncation

## Authors

- [@gonzimaster](https://www.github.com/gonzimaster)

