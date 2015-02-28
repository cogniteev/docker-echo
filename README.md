## `cogniteev/echo` Docker image

Docker automated-build providing a minimal Docker image for data container, compatible with Docker Compose.

## Rationale

Data-only container does not need Linux distribution. It just needs an executable to start the container.

[tianon/true](https://registry.hub.docker.com/u/tianon/true/) is the perfect Docker image for that. It provides `/true` executable and ... that's it!

Unfortunately [Docker Compose][https://github.com/docker/compose] assumes that every container has the `/bin/echo` executable (see [Compose issue #919](https://github.com/docker/compose/issues/919]) on GitHub)

This image is meant to workaround this by providing this missing `/bin/echo` executable.

## Base Docker Image

* *scratch*

## Image content

* `/bin/echo` (written in C, not ASM ... yet)

## Installation

1. Install [Docker](https://www.docker.com/)

2. Download [automated build](https://registry.hub.docker.com/u/cogniteev/echo/): `docker pull cogniteev/echo`

## Basic Usage with *Docker*

1. Create a data container named *data_container*:

    ```sh
    sudo docker run -v /data --name data_container cogniteev/echo 
    ```

2. Create a new container that:
    * mounts volume `/data` of *data_container* container
    * creates a file named `/data/bar`
    * is deleted once the container stops

    ```sh
    sudo echo foo |                         \
        docker run                          \
        --volumes-from data_container       \
        -i --rm  busybox                    \
        tee /data/bar
    ```

3. Create a new container that:
    * mounts volume `/data` of *data_container* container
    * reads content of file `/data/bar`
    * is deleted once the container stops

    ```sh
    sudo docker run --volumes-from data_container --rm busybox cat /data/bar
    ```
