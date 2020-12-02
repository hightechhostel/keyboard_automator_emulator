# Build Instructions

This document is intended to be used with the Setup instructions [here](https://github.com/ABCInc/Instructions/blog/master/software/setup.md).  If you do not follow those instructions, your build will likely fail.

## Common problems

Common problems are found [here](common-problems.md)

## Build your code

### First option for building

This block of instructions builds the first option of C++ binaries.
```
cd mycode
pushd software

pushd 1stOption
mkdir -p build
pushd build
cmake .. \
  -OPTION_BUILD_TYPE=1 \
  -OPTION_HANDLE=TRUE \
  -OPTION_LOCKED=TRUE \
  -OPTION_PYTHON=TRUE \
  -OPTION_INSTALL_FOLDER=.

make -j$(nproc)
make install
popd
popd
```

If you need the GUI tools, run this:
```
pushd gui
make gui
make install
```

### Create your ./gitconfig file

Add the following lines to your ./gitconfig file

```
[user]
	name = Pavan Kumar Sunkara
	email = pavan.sss1991@gmail.com
	username = pksunkara
[core]
	editor = vim
	whitespace = fix,-indent-with-non-tab,trailing-space,cr-at-eol
	pager = delta
```

If you need the Natural tools copy them to /usr/local/include:
```
cd natural/modes/tools
sudo cp tools.h /usr/local/include
```

That's everything you need to do.  All done!