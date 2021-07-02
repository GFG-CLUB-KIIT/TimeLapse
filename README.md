# TimeLapse

## Environment Setup

step : 1

```
sudo apt-get update -y && sudo apt-get upgrade
```

step : 2

```
sudo apt-get install opencv-data libopencv-dev
```

## Running the project

### Using cmake

step: 1

``` cd build```

step: 2

`cmake ../`

step: 3

`make`

to run the executable: `./elapso --help`

### normal method

step : 1

```
cd include
```

step : 2

```
g++ main.cpp -o output `pkg-config --cflags --libs opencv4` -lstdc++fs
```
step : 3

```
./output <directory_with_image>
```

