#ifndef THREE_INDEX_HPP
#define THREE_INDEX_HPP

namespace three {

template < typename T, T invalid >
struct IndexT {
  explicit IndexT( T t = invalid ) : value( t ) { }
  IndexT( const IndexT& other ) : value( other.value ) { }

  IndexT& operator=( T t ) { value = t; return *this; }
  IndexT& operator=( const IndexT& other ) { value = other.value; return *this; }

  //THREE_EXPLICIT operator bool() const { return value != invalid; }
  bool valid() const { return value != invalid; }

  struct IncompleteType;

  operator T() const { return value; }
  operator unsigned() const { return static_cast<unsigned>(value); }
  operator unsigned long() const { return static_cast<unsigned long>(value); }

  T value;
};

typedef IndexT<int, -1> Index;

} // namespace three

namespace std {
  template <>
  struct hash<three::Index> {
    size_t operator()( const three::Index& index ) {
      return hash<int>()( index.value );
    }
  };
} // namespace std

#endif // THREE_PROPERTIES_HPP
