#ifndef __DISTINGUISHER_H__
#define __DISTINGUISHER_H__

#include "Controller.h"
#include <cstdint>

enum struct Color { NONE, BLACK, WHITE, RED, BLUE, YELLOW, GREEN };

struct Rgb {
  Color color;
  std::uint16_t r;
  std::uint16_t g;
  std::uint16_t b;
};

class DistinguisherTest;

class Distinguisher {
  friend class DistinguisherTest;

 public:
  explicit Distinguisher(Controller controller_) : controller(controller_) {}
  Color getColor();
  Color distingishColor();
  void setRawColor2Rgb();
  void judgement(const Rgb& rgb, double& min);
  double distanceColor(Rgb target_color);
  double last_distance = 0.0;
  double threshold_distance = 400;
  Rgb raw_color = { Color::NONE, 0, 0, 0 };

 private:
  Controller controller;
  Color color = Color::NONE;
  const Rgb RED = { Color::RED, 112, 13, 9 };
  const Rgb BLUE = { Color::BLUE, 18, 47, 50 };
  const Rgb GREEN = { Color::GREEN, 24, 77, 13 };
  const Rgb YELLOW = { Color::YELLOW, 116, 120, 15 };
  const Rgb BLACK = { Color::BLACK, 14, 19, 5 };
  const Rgb WHITE = { Color::WHITE, 128, 158, 93 };
};

#endif