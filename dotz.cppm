module;
#include <math.h>

export module dotz;

export namespace dotz {
[[nodiscard]] constexpr auto max(auto a, auto b) { return a > b ? a : b; }
[[nodiscard]] constexpr auto min(auto a, auto b) { return a < b ? a : b; }
[[nodiscard]] constexpr auto abs(auto a) { return a > 0 ? a : -a; }

[[nodiscard]] constexpr float pow(float b, float e) { return ::pow(b, e); }
[[nodiscard]] constexpr auto sqrt(float a) { return ::sqrtf(a); }
[[nodiscard]] constexpr auto sqrt(double a) { return ::sqrt(a); }

[[nodiscard]] constexpr auto sin(double a) { return ::sin(a); }
[[nodiscard]] constexpr auto cos(double a) { return ::cos(a); }

[[nodiscard]] constexpr float mix(float x, float y, float a) {
  return x * (1.0 - a) + y * a;
}

struct vec2 {
  float x;
  float y;

  constexpr vec2() = default;
  constexpr vec2(float a) : vec2{a, a} {}
  constexpr vec2(int a) : vec2{a, a} {}
  constexpr vec2(float x, float y) : x{x}, y{y} {}
  constexpr vec2(unsigned x, unsigned y)
      : x{static_cast<float>(x)}, y{static_cast<float>(y)} {}
  constexpr vec2(int x, int y)
      : x{static_cast<float>(x)}, y{static_cast<float>(y)} {}

  constexpr vec2(const vec2 &o) = default;
  constexpr vec2(vec2 &&o) = default;
  constexpr vec2 &operator=(const vec2 &o) = default;
  constexpr vec2 &operator=(vec2 &&o) = default;
};

[[nodiscard]] constexpr vec2 operator-(vec2 a) noexcept {
  return vec2{-a.x, -a.y};
}
[[nodiscard]] constexpr vec2 operator+(vec2 a, float b) noexcept {
  return vec2{a.x + b, a.y + b};
}
[[nodiscard]] constexpr vec2 operator-(vec2 a, float b) noexcept {
  return vec2{a.x - b, a.y - b};
}
[[nodiscard]] constexpr vec2 operator*(vec2 a, float b) noexcept {
  return vec2{a.x * b, a.y * b};
}
[[nodiscard]] constexpr vec2 operator/(vec2 a, float b) noexcept {
  return vec2{a.x / b, a.y / b};
}
[[nodiscard]] constexpr vec2 operator+(vec2 a, vec2 b) noexcept {
  return vec2{a.x + b.x, a.y + b.y};
}
[[nodiscard]] constexpr vec2 operator-(vec2 a, vec2 b) noexcept {
  return vec2{a.x - b.x, a.y - b.y};
}
[[nodiscard]] constexpr vec2 operator*(vec2 a, vec2 b) noexcept {
  return vec2{a.x * b.x, a.y * b.y};
}
[[nodiscard]] constexpr vec2 operator/(vec2 a, vec2 b) noexcept {
  return vec2{a.x / b.x, a.y / b.y};
}

[[nodiscard]] constexpr vec2 abs(vec2 a) noexcept {
  return vec2{abs(a.x), abs(a.y)};
}
[[nodiscard]] constexpr vec2 floor(vec2 a) noexcept {
  return vec2{static_cast<int>(a.x), static_cast<int>(a.y)};
}
[[nodiscard]] constexpr vec2 pow(vec2 b, float e) noexcept {
  return vec2{pow(b.x, e), pow(b.y, e)};
}
[[nodiscard]] constexpr vec2 min(vec2 a, vec2 b) noexcept {
  return vec2{a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y};
}
[[nodiscard]] constexpr vec2 max(vec2 a, vec2 b) noexcept {
  return vec2{a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y};
}
[[nodiscard]] constexpr vec2 mix(vec2 a, vec2 b, float f) noexcept {
  return vec2{mix(a.x, b.x, f), mix(a.y, b.y, f)};
}
[[nodiscard]] constexpr float sq_length(vec2 a) noexcept {
  return a.x * a.x + a.y * a.y;
}
[[nodiscard]] constexpr float length(vec2 a) noexcept {
  return sqrt(sq_length(a));
}

struct vec4 {
  float x;
  float y;
  float z;
  float w;

  constexpr vec4() = default;
  constexpr vec4(float a) : vec4{a, a, a, a} {}
  constexpr vec4(int a) : vec4{a, a, a, a} {}
  constexpr vec4(float x, float y, float z, float w) : x{x}, y{y}, z{z}, w{w} {}
  constexpr vec4(unsigned x, unsigned y, unsigned z, unsigned w)
      : x{static_cast<float>(x)}
      , y{static_cast<float>(y)}
      , z{static_cast<float>(z)}
      , w{static_cast<float>(w)} {}
  constexpr vec4(int x, int y, int z, int w)
      : x{static_cast<float>(x)}
      , y{static_cast<float>(y)}
      , z{static_cast<float>(z)}
      , w{static_cast<float>(w)} {}

  constexpr vec4(const vec4 &o) = default;
  constexpr vec4(vec4 &&o) = default;
  constexpr vec4 &operator=(const vec4 &o) = default;
  constexpr vec4 &operator=(vec4 &&o) = default;

  [[nodiscard]] constexpr auto xy() const noexcept { return dotz::vec2{x, y}; }
  [[nodiscard]] constexpr auto zw() const noexcept { return dotz::vec2{z, w}; }
};
[[nodiscard]] constexpr vec4 operator-(vec4 a) noexcept {
  return vec4{-a.x, -a.y, -a.z, -a.w};
}
[[nodiscard]] constexpr vec4 operator+(vec4 a, float b) noexcept {
  return vec4{a.x + b, a.y + b, a.z + b, a.w + b};
}
[[nodiscard]] constexpr vec4 operator-(vec4 a, float b) noexcept {
  return vec4{a.x - b, a.y - b, a.z - b, a.w - b};
}
[[nodiscard]] constexpr vec4 operator*(vec4 a, float b) noexcept {
  return vec4{a.x * b, a.y * b, a.z * b, a.w * b};
}
[[nodiscard]] constexpr vec4 operator/(vec4 a, float b) noexcept {
  return vec4{a.x / b, a.y / b, a.z / b, a.w / b};
}
[[nodiscard]] constexpr vec4 operator+(vec4 a, vec4 b) noexcept {
  return vec4{a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
[[nodiscard]] constexpr vec4 operator-(vec4 a, vec4 b) noexcept {
  return vec4{a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
[[nodiscard]] constexpr vec4 operator*(vec4 a, vec4 b) noexcept {
  return vec4{a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}
[[nodiscard]] constexpr vec4 operator/(vec4 a, vec4 b) noexcept {
  return vec4{a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
}

[[nodiscard]] constexpr vec4 floor(vec4 a) noexcept {
  return vec4{static_cast<int>(a.x), static_cast<int>(a.y),
              static_cast<int>(a.z), static_cast<int>(a.w)};
}
[[nodiscard]] constexpr vec4 pow(vec4 b, float e) noexcept {
  return vec4{pow(b.x, e), pow(b.y, e), pow(b.z, e), pow(b.w, e)};
}
[[nodiscard]] constexpr vec4 min(vec4 a, vec4 b) noexcept {
  return vec4{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w)};
}
[[nodiscard]] constexpr vec4 max(vec4 a, vec4 b) noexcept {
  return vec4{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w)};
}
[[nodiscard]] constexpr float sq_length(vec4 a) noexcept {
  return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

struct ivec2 {
  int x;
  int y;

  constexpr ivec2() = default;
  constexpr ivec2(int a) : ivec2{a, a} {}
  constexpr ivec2(unsigned x, unsigned y)
      : x{static_cast<int>(x)}
      , y{static_cast<int>(y)} {}
  constexpr ivec2(int x, int y) : x{x}, y{y} {}

  constexpr ivec2(const ivec2 &o) = default;
  constexpr ivec2(ivec2 &&o) = default;
  constexpr ivec2 &operator=(const ivec2 &o) = default;
  constexpr ivec2 &operator=(ivec2 &&o) = default;

  [[nodiscard]] constexpr bool operator==(const ivec2 &o) const noexcept {
    return x == o.x && y == o.y;
  }

  [[nodiscard]] constexpr operator vec2() const { return {x, y}; }
};

[[nodiscard]] constexpr ivec2 operator-(ivec2 a) noexcept {
  return ivec2{-a.x, -a.y};
}
[[nodiscard]] constexpr ivec2 operator+(ivec2 a, int b) noexcept {
  return ivec2{a.x + b, a.y + b};
}
[[nodiscard]] constexpr ivec2 operator-(ivec2 a, int b) noexcept {
  return ivec2{a.x - b, a.y - b};
}
[[nodiscard]] constexpr ivec2 operator*(ivec2 a, int b) noexcept {
  return ivec2{a.x * b, a.y * b};
}
[[nodiscard]] constexpr ivec2 operator/(ivec2 a, int b) noexcept {
  return ivec2{a.x / b, a.y / b};
}
[[nodiscard]] constexpr ivec2 operator+(ivec2 a, ivec2 b) noexcept {
  return ivec2{a.x + b.x, a.y + b.y};
}
[[nodiscard]] constexpr ivec2 operator-(ivec2 a, ivec2 b) noexcept {
  return ivec2{a.x - b.x, a.y - b.y};
}
[[nodiscard]] constexpr ivec2 operator*(ivec2 a, ivec2 b) noexcept {
  return ivec2{a.x * b.x, a.y * b.y};
}
[[nodiscard]] constexpr ivec2 operator/(ivec2 a, ivec2 b) noexcept {
  return ivec2{a.x / b.x, a.y / b.y};
}
[[nodiscard]] constexpr ivec2 operator%(ivec2 a, ivec2 b) noexcept {
  return ivec2{a.x % b.x, a.y % b.y};
}

[[nodiscard]] constexpr ivec2 min(ivec2 a, ivec2 b) noexcept {
  return ivec2{min(a.x, b.x), min(a.y, b.y)};
}
[[nodiscard]] constexpr ivec2 max(ivec2 a, ivec2 b) noexcept {
  return ivec2{max(a.x, b.x), max(a.y, b.y)};
}
[[nodiscard]] constexpr ivec2 abs(ivec2 a) noexcept {
  return ivec2{abs(a.x), abs(a.y)};
}
[[nodiscard]] constexpr int sq_length(ivec2 a) noexcept {
  return a.x * a.x + a.y * a.y;
}

[[nodiscard]] constexpr vec2 operator+(ivec2 a, float b) noexcept {
  return vec2{a.x + b, a.y + b};
}
[[nodiscard]] constexpr vec2 operator-(ivec2 a, float b) noexcept {
  return vec2{a.x - b, a.y - b};
}
[[nodiscard]] constexpr vec2 operator*(ivec2 a, float b) noexcept {
  return vec2{a.x * b, a.y * b};
}
[[nodiscard]] constexpr vec2 operator/(ivec2 a, float b) noexcept {
  return vec2{a.x / b, a.y / b};
}
} // namespace dotz
