#ifndef FAS_TYPEMANIP_REFERENCE_WRAPPER_HPP
#define FAS_TYPEMANIP_REFERENCE_WRAPPER_HPP

namespace fas
{
     
  template<typename _Tp>
    inline _Tp*
    __addressof(_Tp& __r) 
    {
      return reinterpret_cast<_Tp*>
        (&const_cast<char&>(reinterpret_cast<const volatile char&>(__r)));
    }


  template<typename _Tp>
    class reference_wrapper
    {
      _Tp* _M_data;

    public:
      typedef _Tp type;

      reference_wrapper(_Tp& __indata) 
      : _M_data( ::fas::__addressof(__indata))
      { }

     

      reference_wrapper(const reference_wrapper<_Tp>& __inref) 
      : _M_data(__inref._M_data)
      { }

      reference_wrapper&
      operator=(const reference_wrapper<_Tp>& __inref) 
      {
	_M_data = __inref._M_data;
	return *this;
      }

      operator _Tp&() const 
      { return this->get(); }

      _Tp&
      get() const 
      { return *_M_data; }

      
    };


  /// Denotes a reference should be taken to a variable.
  template<typename _Tp>
    inline reference_wrapper<_Tp>
    ref(_Tp& __t) 
    { return reference_wrapper<_Tp>(__t); }

  /// Denotes a const reference should be taken to a variable.
  template<typename _Tp>
    inline reference_wrapper<const _Tp>
    cref(const _Tp& __t) 
    { return reference_wrapper<const _Tp>(__t); }


  /// Partial specialization.
  template<typename _Tp>
    inline reference_wrapper<_Tp>
    ref(reference_wrapper<_Tp> __t) 
    { return ref(__t.get()); }

  /// Partial specialization.
  template<typename _Tp>
    inline reference_wrapper<const _Tp>
    cref(reference_wrapper<_Tp> __t) 
    { return cref(__t.get()); }

}
#endif 
