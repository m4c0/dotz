export module dotz;

export namespace dotz {
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

[[nodiscard]] constexpr vec2 floor(vec2 a) noexcept {
  return vec2{static_cast<int>(a.x), static_cast<int>(a.y)};
}
[[nodiscard]] constexpr vec2 min(vec2 a, vec2 b) noexcept {
  return vec2{a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y};
}
[[nodiscard]] constexpr vec2 max(vec2 a, vec2 b) noexcept {
  return vec2{a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y};
}
[[nodiscard]] constexpr float sq_length(vec2 a) noexcept {
  return a.x * a.x + a.y * a.y;
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
};
[[nodiscard]] constexpr float sq_length(vec4 a) noexcept {
  return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}
} // namespace dotz
