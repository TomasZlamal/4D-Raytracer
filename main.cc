#include "include/Hypersphere.h"
#include "include/Object4D.h"
#include "include/ObjectWorld.h"
#include "include/vec3.h"
#include "include/vec4.h"
#include <cstdlib>
#include <iostream>
#include <string>
using color = rt4::vec3;

void write_color(std::ostream &out, const color &pixel_color) {
  auto r = pixel_color.x;
  auto g = pixel_color.y;
  auto b = pixel_color.z;

  // Translate the [0,1] component values to the byte range [0,255].
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);

  // Write out the pixel color components.
  out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

int main(int argc, char **argv) {
  rt4::ObjectWorld world4D;
  rt4::vec4 center = {2.0f, 2.2f, 0.0f, 1.0f};
  rt4::Object4D *hypersphere = new rt4::Hypersphere{center, 2.1f};
  world4D.addObject(hypersphere);

  float aspect_ratio = 16.0f / 9;
  float vp_height = 1.0;
  float vp_width = vp_height * aspect_ratio;
  float vp_depth = 1.0;

  int image_height = 600;
  int image_width = image_height * aspect_ratio;

  float delta_u = vp_width / image_width;
  float delta_v = vp_height / image_height;

  float current_depth = 0.0f;
  if (argc > 1) {
    current_depth = static_cast<float>(std::stoi(std::string(argv[1]))) / 100;
  }

  // so coordinate of vectors will be (i*delta_u,
  // j*delta_v, 0.0f, current_depth)
  // start is (0, 0, 0, 0)
  // so vecs is = (i*delta_u, j*delta_v, 0.0f, current_depth) - start
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = 0; j < image_height; ++j) {
    /*std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;*/
    for (int i = 0; i < image_width; i++) {
      rt4::vec4 curr_vec;
      curr_vec.x = i * delta_u;
      curr_vec.y = j * delta_v;
      curr_vec.z = 0.0f;
      curr_vec.w = current_depth;
      float r, g, b;
      r = 1.0f;
      g = r;
      b = r;
      auto objectMaybe = world4D.borrowNthObject(0);
      if (objectMaybe) {
        auto objectDefinitely = objectMaybe.value();
        {
          auto tmp = objectDefinitely.lock();
          int collides = (*tmp)->vec4Collides(curr_vec);
          r = 0.0f;
          g = static_cast<float>(collides) /
              (1 + abs(collides)); // fast sigmoid
          b = 0.0f;
        }
      }
      rt4::vec3 color = {r, g, b};
      write_color(std::cout, color);
    }
  }

  // std::clog << "\rDone.                 \n";
  return 0;
}
