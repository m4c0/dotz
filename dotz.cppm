module;
extern "C" {
double cos(double);
double exp(double);
double pow(double, double);
double sin(double);
double sqrt(double);
double tanh(double);
float floorf(float);
float fmodf(float, float);
float roundf(float);
float sqrtf(float);
}

export module dotz;

export namespace dotz {
constexpr const auto pi = 3.141592653589783;

[[nodiscard]] constexpr auto radians(auto a) { return a * pi / 180.0; }

[[nodiscard]] constexpr auto max(auto a, auto b) { return a > b ? a : b; }
[[nodiscard]] constexpr auto min(auto a, auto b) { return a < b ? a : b; }
[[nodiscard]] constexpr auto abs(auto a) { return a > 0 ? a : -a; }
[[nodiscard]] constexpr auto sign(auto a) { return a / abs(a); }

template<typename T>
[[nodiscard]] constexpr auto clamp(T x, T mn, T mx) { return min(max(x, mn), mx); }

[[nodiscard]] constexpr auto exp(double a) { return ::exp(a); }
[[nodiscard]] constexpr float pow(float b, float e) { return ::pow(b, e); }
[[nodiscard]] constexpr auto round(float a) { return ::roundf(a); }
[[nodiscard]] constexpr auto sqrt(float a) { return ::sqrtf(a); }
[[nodiscard]] constexpr auto sqrt(double a) { return ::sqrt(a); }

[[nodiscard]] constexpr auto sin(double a) { return ::sin(a); }
[[nodiscard]] constexpr auto cos(double a) { return ::cos(a); }
[[nodiscard]] constexpr auto tanh(double a) { return ::tanh(a); }

[[nodiscard]] constexpr auto floor(float a) { return ::floorf(a); }

[[nodiscard]] constexpr auto mod(float a, float b) { return ::fmodf(a, b); }

[[nodiscard]] constexpr float mix(float x, float y, float a) {
  return x * (1.0 - a) + y * a;
}

[[nodiscard]] constexpr auto normalise(auto v) { return v / length(v); }

struct vec2 {
  float x;
  float y;

  constexpr vec2() = default;
  constexpr vec2(float a) : vec2{a, a} {}
  constexpr vec2(int a) : vec2{a, a} {}
  constexpr vec2(float x, float y) : x{x}, y{y} {}
  constexpr vec2(unsigned x, unsigned y)
      : x{static_cast<float>(x)}
      , y{static_cast<float>(y)} {}
  constexpr vec2(int x, int y)
      : x{static_cast<float>(x)}
      , y{static_cast<float>(y)} {}

  constexpr vec2(const vec2 &o) = default;
  constexpr vec2(vec2 &&o) = default;
  constexpr vec2 &operator=(const vec2 &o) = default;
  constexpr vec2 &operator=(vec2 &&o) = default;
};

[[nodiscard]] constexpr vec2 operator-(vec2 a) { return vec2{-a.x, -a.y}; }
[[nodiscard]] constexpr vec2 operator+(vec2 a, float b) {
  return vec2{a.x + b, a.y + b};
}
[[nodiscard]] constexpr vec2 operator-(vec2 a, float b) {
  return vec2{a.x - b, a.y - b};
}
[[nodiscard]] constexpr vec2 operator*(vec2 a, float b) {
  return vec2{a.x * b, a.y * b};
}
[[nodiscard]] constexpr vec2 operator/(vec2 a, float b) {
  return vec2{a.x / b, a.y / b};
}
[[nodiscard]] constexpr vec2 operator+(vec2 a, vec2 b) {
  return vec2{a.x + b.x, a.y + b.y};
}
[[nodiscard]] constexpr vec2 operator-(vec2 a, vec2 b) {
  return vec2{a.x - b.x, a.y - b.y};
}
[[nodiscard]] constexpr vec2 operator*(vec2 a, vec2 b) {
  return vec2{a.x * b.x, a.y * b.y};
}
[[nodiscard]] constexpr vec2 operator/(vec2 a, vec2 b) {
  return vec2{a.x / b.x, a.y / b.y};
}

[[nodiscard]] constexpr vec2 abs(vec2 a) { return vec2{abs(a.x), abs(a.y)}; }
[[nodiscard]] constexpr vec2 floor(vec2 a) {
  return vec2{floorf(a.x), floorf(a.y)};
}
[[nodiscard]] constexpr vec2 round(vec2 a) {
  return vec2{roundf(a.x), roundf(a.y)};
}
[[nodiscard]] constexpr vec2 pow(vec2 b, float e) {
  return vec2{pow(b.x, e), pow(b.y, e)};
}
[[nodiscard]] constexpr vec2 min(vec2 a, vec2 b) {
  return vec2{a.x < b.x ? a.x : b.x, a.y < b.y ? a.y : b.y};
}
[[nodiscard]] constexpr vec2 max(vec2 a, vec2 b) {
  return vec2{a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y};
}
[[nodiscard]] constexpr vec2 mix(vec2 a, vec2 b, float f) {
  return vec2{mix(a.x, b.x, f), mix(a.y, b.y, f)};
}
[[nodiscard]] constexpr float sq_length(vec2 a) {
  return a.x * a.x + a.y * a.y;
}
[[nodiscard]] constexpr float length(vec2 a) { return sqrt(sq_length(a)); }

struct vec3 {
  float x;
  float y;
  float z;

  constexpr vec3() = default;
  constexpr vec3(float a) : vec3{a, a, a} {}
  constexpr vec3(int a) : vec3{a, a, a} {}
  constexpr vec3(float x, float y, float z) : x{x}, y{y}, z{z} {}
  constexpr vec3(unsigned x, unsigned y, unsigned z)
      : x{static_cast<float>(x)}
      , y{static_cast<float>(y)}
      , z{static_cast<float>(z)} {}
  constexpr vec3(int x, int y, int z)
      : x{static_cast<float>(x)}
      , y{static_cast<float>(y)}
      , z{static_cast<float>(z)} {}

  constexpr vec3(const vec3 &o) = default;
  constexpr vec3(vec3 &&o) = default;
  constexpr vec3 &operator=(const vec3 &o) = default;
  constexpr vec3 &operator=(vec3 &&o) = default;
};
[[nodiscard]] constexpr vec3 operator-(vec3 a) {
  return vec3{-a.x, -a.y, -a.z};
}
[[nodiscard]] constexpr vec3 operator+(vec3 a, float b) {
  return vec3{a.x + b, a.y + b, a.z + b};
}
[[nodiscard]] constexpr vec3 operator-(vec3 a, float b) {
  return vec3{a.x - b, a.y - b, a.z - b};
}
[[nodiscard]] constexpr vec3 operator*(vec3 a, float b) {
  return vec3{a.x * b, a.y * b, a.z * b};
}
[[nodiscard]] constexpr vec3 operator/(vec3 a, float b) {
  return vec3{a.x / b, a.y / b, a.z / b};
}
[[nodiscard]] constexpr vec3 operator+(vec3 a, vec3 b) {
  return vec3{a.x + b.x, a.y + b.y, a.z + b.z};
}
[[nodiscard]] constexpr vec3 operator-(vec3 a, vec3 b) {
  return vec3{a.x - b.x, a.y - b.y, a.z - b.z};
}
[[nodiscard]] constexpr vec3 operator*(vec3 a, vec3 b) {
  return vec3{a.x * b.x, a.y * b.y, a.z * b.z};
}
[[nodiscard]] constexpr vec3 operator/(vec3 a, vec3 b) {
  return vec3{a.x / b.x, a.y / b.y, a.z / b.z};
}

[[nodiscard]] constexpr vec3 floor(vec3 a) {
  return vec3{floorf(a.x), floorf(a.y), floorf(a.z)};
}
[[nodiscard]] constexpr vec3 pow(vec3 b, float e) {
  return vec3{pow(b.x, e), pow(b.y, e), pow(b.z, e)};
}
[[nodiscard]] constexpr vec3 min(vec3 a, vec3 b) {
  return vec3{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z)};
}
[[nodiscard]] constexpr vec3 max(vec3 a, vec3 b) {
  return vec3{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z)};
}
[[nodiscard]] constexpr float sq_length(vec3 a) {
  return a.x * a.x + a.y * a.y + a.z * a.z;
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

  [[nodiscard]] constexpr auto xy() const { return dotz::vec2{x, y}; }
  [[nodiscard]] constexpr auto zw() const { return dotz::vec2{z, w}; }
};
[[nodiscard]] constexpr vec4 operator-(vec4 a) {
  return vec4{-a.x, -a.y, -a.z, -a.w};
}
[[nodiscard]] constexpr vec4 operator+(vec4 a, float b) {
  return vec4{a.x + b, a.y + b, a.z + b, a.w + b};
}
[[nodiscard]] constexpr vec4 operator-(vec4 a, float b) {
  return vec4{a.x - b, a.y - b, a.z - b, a.w - b};
}
[[nodiscard]] constexpr vec4 operator*(vec4 a, float b) {
  return vec4{a.x * b, a.y * b, a.z * b, a.w * b};
}
[[nodiscard]] constexpr vec4 operator/(vec4 a, float b) {
  return vec4{a.x / b, a.y / b, a.z / b, a.w / b};
}
[[nodiscard]] constexpr vec4 operator+(vec4 a, vec4 b) {
  return vec4{a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
[[nodiscard]] constexpr vec4 operator-(vec4 a, vec4 b) {
  return vec4{a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
[[nodiscard]] constexpr vec4 operator*(vec4 a, vec4 b) {
  return vec4{a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}
[[nodiscard]] constexpr vec4 operator/(vec4 a, vec4 b) {
  return vec4{a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
}

[[nodiscard]] constexpr vec4 floor(vec4 a) {
  return vec4{floorf(a.x), floorf(a.y), floorf(a.z), floorf(a.w)};
}
[[nodiscard]] constexpr vec4 pow(vec4 b, float e) {
  return vec4{pow(b.x, e), pow(b.y, e), pow(b.z, e), pow(b.w, e)};
}
[[nodiscard]] constexpr vec4 min(vec4 a, vec4 b) {
  return vec4{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w)};
}
[[nodiscard]] constexpr vec4 max(vec4 a, vec4 b) {
  return vec4{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w)};
}
[[nodiscard]] constexpr float sq_length(vec4 a) {
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

  [[nodiscard]] constexpr bool operator==(const ivec2 &o) const {
    return x == o.x && y == o.y;
  }

  [[nodiscard]] constexpr operator vec2() const { return {x, y}; }
};

[[nodiscard]] constexpr ivec2 operator-(ivec2 a) { return ivec2{-a.x, -a.y}; }
[[nodiscard]] constexpr ivec2 operator+(ivec2 a, int b) {
  return ivec2{a.x + b, a.y + b};
}
[[nodiscard]] constexpr ivec2 operator-(ivec2 a, int b) {
  return ivec2{a.x - b, a.y - b};
}
[[nodiscard]] constexpr ivec2 operator*(ivec2 a, int b) {
  return ivec2{a.x * b, a.y * b};
}
[[nodiscard]] constexpr ivec2 operator/(ivec2 a, int b) {
  return ivec2{a.x / b, a.y / b};
}
[[nodiscard]] constexpr ivec2 operator+(ivec2 a, ivec2 b) {
  return ivec2{a.x + b.x, a.y + b.y};
}
[[nodiscard]] constexpr ivec2 operator-(ivec2 a, ivec2 b) {
  return ivec2{a.x - b.x, a.y - b.y};
}
[[nodiscard]] constexpr ivec2 operator*(ivec2 a, ivec2 b) {
  return ivec2{a.x * b.x, a.y * b.y};
}
[[nodiscard]] constexpr ivec2 operator/(ivec2 a, ivec2 b) {
  return ivec2{a.x / b.x, a.y / b.y};
}
[[nodiscard]] constexpr ivec2 operator%(ivec2 a, ivec2 b) {
  return ivec2{a.x % b.x, a.y % b.y};
}

[[nodiscard]] constexpr ivec2 min(ivec2 a, ivec2 b) {
  return ivec2{min(a.x, b.x), min(a.y, b.y)};
}
[[nodiscard]] constexpr ivec2 max(ivec2 a, ivec2 b) {
  return ivec2{max(a.x, b.x), max(a.y, b.y)};
}
[[nodiscard]] constexpr ivec2 abs(ivec2 a) { return ivec2{abs(a.x), abs(a.y)}; }
[[nodiscard]] constexpr int sq_length(ivec2 a) { return a.x * a.x + a.y * a.y; }

[[nodiscard]] constexpr vec2 operator+(ivec2 a, float b) {
  return vec2{a.x + b, a.y + b};
}
[[nodiscard]] constexpr vec2 operator-(ivec2 a, float b) {
  return vec2{a.x - b, a.y - b};
}
[[nodiscard]] constexpr vec2 operator*(ivec2 a, float b) {
  return vec2{a.x * b, a.y * b};
}
[[nodiscard]] constexpr vec2 operator/(ivec2 a, float b) {
  return vec2{a.x / b, a.y / b};
}

struct ivec4 {
  int x;
  int y;
  int z;
  int w;

  constexpr ivec4() = default;
  constexpr ivec4(int a) : ivec4{a, a, a, a} {}
  constexpr ivec4(unsigned x, unsigned y, unsigned z, unsigned w)
      : x{static_cast<int>(x)}
      , y{static_cast<int>(y)}
      , z{static_cast<int>(z)}
      , w{static_cast<int>(w)} {}
  constexpr ivec4(int x, int y, int z, int w) : x{x}, y{y}, z{z}, w{w} {}

  constexpr ivec4(const ivec4 &o) = default;
  constexpr ivec4(ivec4 &&o) = default;
  constexpr ivec4 &operator=(const ivec4 &o) = default;
  constexpr ivec4 &operator=(ivec4 &&o) = default;

  [[nodiscard]] constexpr bool operator==(const ivec4 &o) const {
    return x == o.x && y == o.y && z == o.z && w == o.w;
  }

  [[nodiscard]] constexpr operator vec4() const { return {x, y, z, w}; }
};

[[nodiscard]] constexpr ivec4 operator-(ivec4 a) {
  return ivec4{-a.x, -a.y, -a.z, -a.w};
}
[[nodiscard]] constexpr ivec4 operator+(ivec4 a, int b) {
  return ivec4{a.x + b, a.y + b, a.z + b, a.w + b};
}
[[nodiscard]] constexpr ivec4 operator-(ivec4 a, int b) {
  return ivec4{a.x - b, a.y - b, a.z - b, a.w - b};
}
[[nodiscard]] constexpr ivec4 operator*(ivec4 a, int b) {
  return ivec4{a.x * b, a.y * b, a.z * b, a.w * b};
}
[[nodiscard]] constexpr ivec4 operator/(ivec4 a, int b) {
  return ivec4{a.x / b, a.y / b, a.z / b, a.w / b};
}
[[nodiscard]] constexpr ivec4 operator+(ivec4 a, ivec4 b) {
  return ivec4{a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
[[nodiscard]] constexpr ivec4 operator-(ivec4 a, ivec4 b) {
  return ivec4{a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
[[nodiscard]] constexpr ivec4 operator*(ivec4 a, ivec4 b) {
  return ivec4{a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}
[[nodiscard]] constexpr ivec4 operator/(ivec4 a, ivec4 b) {
  return ivec4{a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w};
}
[[nodiscard]] constexpr ivec4 operator%(ivec4 a, ivec4 b) {
  return ivec4{a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w};
}

[[nodiscard]] constexpr ivec4 min(ivec4 a, ivec4 b) {
  return ivec4{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w)};
}
[[nodiscard]] constexpr ivec4 max(ivec4 a, ivec4 b) {
  return ivec4{max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w)};
}
[[nodiscard]] constexpr ivec4 abs(ivec4 a) {
  return ivec4{abs(a.x), abs(a.y), abs(a.z), abs(a.w)};
}
[[nodiscard]] constexpr int sq_length(ivec4 a) {
  return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}
} // namespace dotz
