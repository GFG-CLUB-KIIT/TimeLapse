# TimeLapse

## Environment Setup

step : 1

```
sudo apt-get update -y && sudo apt-get upgrade
```

step : 2

```
sudo apt-get install opencv-data libopence-dev
```

## Running the project

step : 1

```
cd include
```

step : 2

```
g++ main.cpp -o output `pkg-config --cflags --libs opencv` -lstdc++fs
```
step : 3

```
./output
```

