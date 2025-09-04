# raytracer4d
![4D Ray Traced Image](https://github.com/TomasZlamal/4D-Raytracer/blob/main/example.png)
Image - Example of a 4D hypersphere render

A four-dimensional ray tracer, written in C++.
Currently only supports hyperspheres.

This project heavily borrowed code and concepts from [RayTracingInOneWeekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview), but scaled it up to the fourth dimension.
## Using it
Build and try the raytracer out:
```bash
cd build
cmake ..
cmake --build .
./raytracer4d > out.ppm
```
Then the result is inside of out.ppm

## Parameters
The way this ray tracer works is that it projects the 4D space onto a 3D viewport, which has a viewport width, height and depth.
Since you can only project a 2D image onto a 2D screen, you can only see a certain "depth" of the image at a time. You can set this depth by passing a parameter to the program:
```
./raytracer4d 30
```
Would be equivavlent to a depth of 0.3f, since the result gets divived by a hundred.
