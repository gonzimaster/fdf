<h1 align="center">
	FDF
</h1>

<p align="center">
	<b><i>A simplified 3D graphic representation of a relief landscape.</i></b><br>
</p>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/gonzimaster/fdf?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/gonzimaster/fdf?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/gonzimaster/fdf?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/gonzimaster/fdf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/gonzimaster/fdf?color=green" />
</p>

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#features">Features</a>
	<span> · </span>
	<a href="#usage">Usage</a>
</h3>

---

## About

This project is about creating a simplified graphic "wireframe"
representation of a relief landscape linking various points (x, y, z) via
segments. The coordinates of this landscape are stored in a file passed as
a parameter to the program.

Each number corresponds to a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

<p align="center">
	<img src="https://github.com/ogonzi/fdf/blob/master/fdf_img.jpg" />
</p>
## Features
### Mandatory

- Shows map using isometric projection.
- Quits the program by pressing 'esc'.
- Colors map as a function of altitude.

### Bonus

- Translate, rotate, and change viewing angle.
- Modify the scale of the z coordinate.
- Zoom in and out.
- Change to side view projection.

## Usage

To use the program with basic functionality, compile:

```shell
$ make
```

and run:

```shell
$ ./fdf <map_name>
```
To use the program with bonus functionality, compile:

```shell
$ make bonus
```

and run:

```shell
$ ./fdf_bonus <map_name>
```
## Authors

- [@ogonzi](https://www.github.com/ogonzi)

