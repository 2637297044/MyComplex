// The code requires C++20.
#pragma once
#include <stdexcept>
namespace MyComplex {
// primary template MyComplex<T, U>
template <class T = double, class U = double> class MyComplex {
public:
  static constexpr U DefaultSqImagUnit = static_cast<U>(-1.0);
  explicit constexpr MyComplex(const T &re = T(), const T &im = T(),
                               const U &siu = MyComplex::DefaultSqImagUnit)
      : real(re), imag(im), sq_imag_unit(siu) {}
  constexpr MyComplex(const MyComplex &);
  template <class X>
  explicit constexpr MyComplex(const MyComplex<X, U> &other)
      : real(static_cast<T>(other.real)), imag(static_cast<T>(other.imag)),
        sq_imag_unit(other.sq_imag_unit) {}
  template <class Y>
  explicit constexpr MyComplex(const MyComplex<T, Y> &other)
      : real(other.real), imag(other.imag),
        sq_imag_unit(static_cast<U>(other.sq_imag_unit)) {}
  template <class X, class Y>
  explicit constexpr MyComplex(const MyComplex<X, Y> &other)
      : real(static_cast<T>(other.real)), imag(static_cast<T>(other.imag)),
        sq_imag_unit(static_cast<U>(other.sq_imag_unit)) {}
  constexpr T Real() const;
  constexpr void Real(const T &value);
  constexpr T Imag() const;
  constexpr void Imag(const T &value);
  constexpr U SqImagUnit() const;
  constexpr void SqImagUnit(const U &value);
  MyComplex &operator=(const MyComplex &);
  template <class X> MyComplex &operator=(const MyComplex<X, U> &other) {
    this->real = static_cast<T>(other.real);
    this->imag = static_cast<T>(other.imag);
    this->sq_imag_unit = other.sq_imag_unit;
    return *this;
  }
  template <class Y> MyComplex &operator=(const MyComplex<T, Y> &other) {
    this->real = other.real;
    this->imag = other.imag;
    this->sq_imag_unit = static_cast<U>(other.sq_imag_unit);
    return *this;
  }
  template <class X, class Y>
  MyComplex &operator=(const MyComplex<X, Y> &other) {
    this->real = static_cast<T>(other.real);
    this->imag = static_cast<T>(other.imag);
    this->sq_imag_unit = static_cast<U>(other.sq_imag_unit);
    return *this;
  }

private:
  T real, imag;
  U sq_imag_unit;
};
// member functions of primary template MyComplex<T, U>
template <class T, class U>
constexpr MyComplex<T, U>::MyComplex(const MyComplex &other)
    : real(other.real), imag(other.imag), sq_imag_unit(other.sq_imag_unit) {}
template <class T, class U> constexpr T MyComplex<T, U>::Real() const {
  return this->real;
}
template <class T, class U>
constexpr void MyComplex<T, U>::Real(const T &value) {
  this->real = value;
}
template <class T, class U> constexpr T MyComplex<T, U>::Imag() const {
  return this->imag;
}
template <class T, class U>
constexpr void MyComplex<T, U>::Imag(const T &value) {
  this->imag = value;
}
template <class T, class U> constexpr U MyComplex<T, U>::SqImagUnit() const {
  return this->sq_imag_unit;
}
template <class T, class U>
constexpr void MyComplex<T, U>::SqImagUnit(const U &value) {
  this->sq_imag_unit = value;
}
template <class T, class U>
MyComplex<T, U> &MyComplex<T, U>::operator=(const MyComplex &other) {
  this->real = other.real;
  this->imag = other.imag;
  this->sq_imag_unit = other.sq_imag_unit;
  return *this;
}
// specialization MyComplex<float, U>
template <class U> class MyComplex<float, U> {
public:
  static constexpr U DefaultSqImagUnit = static_cast<U>(-1.0);
  explicit constexpr MyComplex(const float &re = 0.0f, const float &im = 0.0f,
                               const U &siu = U())
      : real(re), imag(im), sq_imag_unit(siu) {}
  explicit constexpr MyComplex(const double &re = 0.0, const double &im = 0.0,
                               const U &siu = U())
      : real(static_cast<float>(re)), imag(static_cast<float>(im)),
        sq_imag_unit(siu) {
    if (static_cast<double>(this->real) != re ||
        static_cast<double>(this->imag) != im)
      throw std::invalid_argument("Unavailable conversion.");
  }
  explicit constexpr MyComplex(const long double &re = 0.0L,
                               const long double &im = 0.0L, const U &siu = U())
      : real(static_cast<float>(re)), imag(static_cast<float>(im)),
        sq_imag_unit(siu) {
    if (static_cast<long double>(this->real) != re ||
        static_cast<long double>(this->imag) != im)
      throw std::invalid_argument("Unavailable conversion.");
  }
  constexpr MyComplex(const MyComplex &);
  template <class X, class Y>
  explicit constexpr MyComplex(const MyComplex<X, Y> &other)
      : real(static_cast<float>(other.real)),
        imag(static_cast<float>(other.imag)),
        sq_imag_unit(static_cast<U>(other.sq_imag_unit)) {}
  template <class Y>
  explicit constexpr MyComplex(const MyComplex<float, Y> &other)
      : real(other.real), imag(other.imag),
        sq_imag_unit(static_cast<U>(other.sq_imag_unit)) {}
  template <class Y>
  explicit constexpr MyComplex(const MyComplex<double, Y> &other)
      : real(static_cast<float>(other.real)),
        imag(static_cast<float>(other.imag)),
        sq_imag_unit(static_cast<U>(other.sq_imag_unit)) {
    if (static_cast<double>(this->real) != other.real ||
        static_cast<double>(this->imag) != other.imag)
      throw std::invalid_argument("Unavailable conversion.");
  }
  template <class Y>
  explicit constexpr MyComplex(const MyComplex<long double, Y> &other)
      : real(static_cast<float>(other.real)),
        imag(static_cast<float>(other.imag)),
        sq_imag_unit(static_cast<U>(other.sq_imag_unit)) {
    if (static_cast<long double>(this->real) != other.real ||
        static_cast<long double>(this->imag) != other.imag)
      throw std::invalid_argument("Unavailable conversion.");
  }
  explicit constexpr MyComplex(const MyComplex<double, U> &other)
      : real(static_cast<float>(other.real)),
        imag(static_cast<float>(other.imag)), sq_imag_unit(other.sq_imag_unit) {
    if (static_cast<double>(this->real) != other.real ||
        static_cast<double>(this->imag) != other.imag)
      throw std::invalid_argument("Unavailable conversion.");
  }
  explicit constexpr MyComplex(const MyComplex<long double, U> &other)
      : real(static_cast<float>(other.real)),
        imag(static_cast<float>(other.imag)), sq_imag_unit(other.sq_imag_unit) {
    if (static_cast<long double>(this->real) != other.real ||
        static_cast<long double>(this->imag) != other.imag)
      throw std::invalid_argument("Unavailable conversion.");
  }
  [[nodiscard]] constexpr float Real() const noexcept;
  constexpr void Real(const float &) noexcept;
  constexpr void Real(const double &);
  constexpr void Real(const long double &);
  [[nodiscard]] constexpr float Imag() const noexcept;
  constexpr void Imag(const float &) noexcept;
  constexpr void Imag(const double &);
  constexpr void Imag(const long double &);
  constexpr U SqImagUnit() const;
  constexpr void SqImagUnit(const U &);
  MyComplex &operator=(const MyComplex &);
  MyComplex &operator=(const MyComplex<double, U> &);
  MyComplex &operator=(const MyComplex<long double, U> &);
  template <class Y> MyComplex &operator=(const MyComplex<float, Y> &other) {
    this->real = other.real;
    this->imag = other.imag;
    this->sq_imag_unit = static_cast<U>(other.sq_imag_unit);
    return *this;
  }
  template <class Y> MyComplex &operator=(const MyComplex<double, Y> &other) {
    this->real = static_cast<float>(other.real);
    if (this->imag = static_cast<float>(other.imag);
        static_cast<double>(this->real) != other.real ||
        static_cast<double>(this->imag) != other.imag)
      throw std::invalid_argument("Unavailable conversion.");
    this->sq_imag_unit = static_cast<U>(other.sq_imag_unit);
    return *this;
  }
  template <class Y>
  MyComplex &operator=(const MyComplex<long double, Y> &other) {
    this->real = static_cast<float>(other.real);
    if (this->imag = static_cast<float>(other.imag);
        static_cast<long double>(this->real) != other.real ||
        static_cast<long double>(this->imag) != other.imag)
      throw std::invalid_argument("Unavailable conversion.");
    this->sq_imag_unit = static_cast<U>(other.sq_imag_unit);
    return *this;
  }
  template <class X, class Y>
  MyComplex &operator=(const MyComplex<X, Y> &other) {
    this->real = static_cast<float>(other.real);
    this->imag = static_cast<float>(other.imag);
    this->sq_imag_unit = static_cast<U>(other.sq_imag_unit);
    return *this;
  }

private:
  float real, imag;
  U sq_imag_unit;
};
// member functions of specialization MyComplex<float, U>
template <class U>
constexpr MyComplex<float, U>::MyComplex(const MyComplex &other)
    : real(other.real), imag(other.imag), sq_imag_unit(other.sq_imag_unit) {}
template <class U> constexpr float MyComplex<float, U>::Real() const noexcept {
  return this->real;
}
template <class U>
constexpr void MyComplex<float, U>::Real(const float &value) noexcept {
  this->real = value;
}
template <class U>
constexpr void MyComplex<float, U>::Real(const double &value) {
  this->real = static_cast<float>(value);
  if (static_cast<double>(this->real) != value)
    throw std::invalid_argument("Unavailable conversion.");
}
template <class U>
constexpr void MyComplex<float, U>::Real(const long double &value) {
  this->real = static_cast<float>(value);
  if (static_cast<long double>(this->real) != value)
    throw std::invalid_argument("Unavailable conversion.");
}
template <class U> constexpr float MyComplex<float, U>::Imag() const noexcept {
  return this->imag;
}
template <class U>
constexpr void MyComplex<float, U>::Imag(const float &value) noexcept {
  this->imag = value;
}
template <class U>
constexpr void MyComplex<float, U>::Imag(const double &value) {
  this->imag = static_cast<float>(value);
  if (static_cast<double>(this->imag) != value)
    throw std::invalid_argument("Unavailable conversion.");
}
template <class U>
constexpr void MyComplex<float, U>::Imag(const long double &value) {
  this->imag = static_cast<float>(value);
  if (static_cast<long double>(this->imag) != value)
    throw std::invalid_argument("Unavailable conversion.");
}
template <class U> constexpr U MyComplex<float, U>::SqImagUnit() const {
  return this->sq_imag_unit;
}
template <class U>
constexpr void MyComplex<float, U>::SqImagUnit(const U &value) {
  this->sq_imag_unit = value;
}
template <class U>
MyComplex<float, U> &MyComplex<float, U>::operator=(const MyComplex &other) {
  this->real = other.real;
  this->imag = other.imag;
  this->sq_imag_unit = other.sq_imag_unit;
  return *this;
}
template <class U>
MyComplex<float, U> &
MyComplex<float, U>::operator=(const MyComplex<double, U> &other) {
  this->real = static_cast<float>(other.real);
  if (this->imag = static_cast<float>(other.imag);
      static_cast<double>(this->real) != other.real ||
      static_cast<double>(this->imag) != other.imag)
    throw std::invalid_argument("Unavailable conversion.");
  this->sq_imag_unit = other.sq_imag_unit;
  return *this;
}
template <class U>
MyComplex<float, U> &
MyComplex<float, U>::operator=(const MyComplex<long double, U> &other) {
  this->real = static_cast<float>(other.real);
  if (this->imag = static_cast<float>(other.imag);
      static_cast<long double>(this->real) != other.real ||
      static_cast<long double>(this->imag) != other.imag)
    throw std::invalid_argument("Unavailable conversion.");
  this->sq_imag_unit = other.sq_imag_unit;
  return *this;
}
} // namespace MyComplex
