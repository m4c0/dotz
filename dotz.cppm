export module dotz;

export namespace dotz {
[[nodiscard]] constexpr float max(float a, float b) { return a > b ? a : b; }
[[nodiscard]] constexpr float min(float a, float b) { return a < b ? a : b; }

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

[[nodiscard]] constexpr ivec2 min(ivec2 a, ivec2 b) noexcept {
  return ivec2{a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y};
}
[[nodiscard]] constexpr ivec2 max(ivec2 a, ivec2 b) noexcept {
  return ivec2{a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y};
}
[[nodiscard]] constexpr int sq_length(ivec2 a) noexcept {
  return a.x * a.x + a.y * a.y;
}

} // namespace dotz
