# Docker container for MulticoreBSP

This repository hosts the setup for a docker container hat contains MulticoreBSP. You can build your own image or download from Docker Hub.


## Compiling a C file with MulticoreBSP

To compile a file called `example.c` in the current directory, run the following command:

```
./run.sh example
```

This will create a binary file called `example` based on `example.c`.


## Build the docker image (optional)

You can build your own docker image if you prefer building the image yourself instead of downloading it from Docker Hub.

To build the C compiler, run

```
./build.sh
```

Or run the full command as below. This will do the same as running the `run.sh` script.

```
docker build -t noordstar/multicorebsp:latest ./multicorebsp-docker/
```