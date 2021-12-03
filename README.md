# InkPython

Python bindings for [InkCpp](https://github.com/brwarner/inkcpp)  
Allows you to run [Inkle's ink](https://www.inklestudios.com/ink/) narrative scripting language for games from python script.  
This is alpha software. DO NOT USE IT IT PRODUCTION.

## Usage

```python
import inkpython
story = inkpython.Story('ink/sample.bin')

while(1):
	while(story.can_continue()):
		print(story.getline())

	if(story.has_choices()):
		for c in story.choices():
			print("%s> %s" % (c.index(), c.text()))
		i = input("?>")
		story.choose(int(i))
		continue;
	else:
		break

```

The input must be in binary format.  
Use `inkcpp_cl`

```bash
inkcpp_cl you_ink_file.ink
# OR
inkcpp_cl you_ink_file.json

```

A sample player can be found in the `python` folder with a sample game file (`sample.bin`) in the `ink` folder.

```
$ python python/player.py ink/sample.bin

Once upon a time... #LOCATION: MagicKingdom

1> There were two choices.
2> There were four lines of content.
?>

```

## Build

### Dependancies
* `python3` 
* `pybind11` (use `pip install pybind11` or your preferred installer)
* [InkCpp](https://github.com/brwarner/inkcpp) (git clone it in a sister repository)


### Pre Installation

```

mkdir build
cd build
cmake ..

```

#### Options
If `cmake` does not find your `pybind11` package you can specify the `PYTHON_SITE_PACKAGES` env variable.  
(For example if you are using `pyenv`, `cmake` won't find the current python install.)

```
PYTHON_SITE_PACKAGES=~/.pyenv/versions/3.9.6/lib/python3.9/site-packages cmake ..

```

By default, `cmake` will try to find InkCpp sources in a `inkcpp` directory next to this one, you can override with the `INKCCPP_SOURCE_DIR` var

```
INKCPP_SOURCE_DIR="/somewhere/else" cmake ..

```

### Build

```
cd build
make
make install

```

## Test

_TBD_
